#include <esp_now.h>
#include <WiFi.h>

// Define a data structure
typedef struct struct_message {
  int joystickXValue;
  int joystickYValue;
} struct_message;

// Create a structured object
struct_message myData;

// Motor control pins
int enableRightMotor = 32;
int rightMotorPin1 = 25;
int rightMotorPin2 = 26;
int enableLeftMotor = 33;
int leftMotorPin1 = 12;
int leftMotorPin2 = 13;

// Maximum motor speed
const int MAX_MOTOR_SPEED = 200;

// PWM settings
const int PWMFreq = 1000;
const int PWMResolution = 8;
const int rightMotorPWMSpeedChannel = 4;
const int leftMotorPWMSpeedChannel = 5;

// Signal timeout
#define SIGNAL_TIMEOUT 1000
unsigned long lastRecvTime = 0;

// Callback function executed when data is received
void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));

  // Print received values
  Serial.print("Joystick X-axis Value: ");
  Serial.print(myData.joystickXValue);
  Serial.print(", Joystick Y-axis Value: ");
  Serial.println(myData.joystickYValue);

  // Motor control based on joystick values
  int throttle = map(myData.joystickYValue, 0, 4096, -MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
  int steering = map(myData.joystickXValue, 0, 4096, -MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);

  int rightMotorSpeed = throttle + steering;
  int leftMotorSpeed = throttle - steering;

  rightMotorSpeed = constrain(rightMotorSpeed, -MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);
  leftMotorSpeed = constrain(leftMotorSpeed, -MAX_MOTOR_SPEED, MAX_MOTOR_SPEED);

  rotateMotor(rightMotorSpeed, leftMotorSpeed);

  // Reset signal timeout
  lastRecvTime = millis();
}

void setUpPinModes() {
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  // Set up PWM for motor speed
  ledcSetup(rightMotorPWMSpeedChannel, PWMFreq, PWMResolution);
  ledcSetup(leftMotorPWMSpeedChannel, PWMFreq, PWMResolution);
  ledcAttachPin(enableRightMotor, rightMotorPWMSpeedChannel);
  ledcAttachPin(enableLeftMotor, leftMotorPWMSpeedChannel);

  rotateMotor(0, 0);
}

void setup() {
  // Set up Serial Monitor
  Serial.begin(115200);

  // Set ESP32 as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register callback function
  esp_now_register_recv_cb(OnDataRecv);

  // Set up motor control pins
  setUpPinModes();
}

void loop() {
  // Check signal timeout
  unsigned long now = millis();
  if (now - lastRecvTime > SIGNAL_TIMEOUT) {
    rotateMotor(0, 0);
  }
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  // Motor control logic
  if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
  } else if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  ledcWrite(rightMotorPWMSpeedChannel, abs(rightMotorSpeed));
  ledcWrite(leftMotorPWMSpeedChannel, abs(leftMotorSpeed));
}
