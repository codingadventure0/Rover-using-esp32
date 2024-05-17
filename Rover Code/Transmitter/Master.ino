#include <esp_now.h>
#include <WiFi.h>


// It will transmite all the function to C8:F0:9E:7A:C1:78 
// C8:F0:9E:7A:C1:78
uint8_t receiverAddress[] = {0xC8, 0xF0, 0x9E, 0x7A, 0xC1, 0x78}; // Change with your reciever mac address

// Define a data structure
typedef struct struct_message {
  int joystickXValue;
  int joystickYValue;
} struct_message;

// Create a structured object
struct_message myData;

// Peer info
esp_now_peer_info_t peerInfo;

// Callback function called when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("\r\nLast Packet Send Status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
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

  // Register the send callback
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  // Read analog joystick values
  int joystickXValue = analogRead(32); // vrX pin of joystick is connected to esp32 at 32pin
  int joystickYValue = analogRead(33);  // vrY pin of joystick is connected to esp32 at 33pin

  // Set joystick values
  myData.joystickXValue = joystickXValue;
  myData.joystickYValue = joystickYValue;

  // Send the data via ESP-NOW
  esp_err_t result = esp_now_send(receiverAddress, (uint8_t *)&myData, sizeof(myData));

  if (result == ESP_OK) {
    Serial.println("Sending confirmed");
  } else {
    Serial.println("Sending error");
  }

  delay(200);
}
