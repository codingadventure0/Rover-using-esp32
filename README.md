# Mars Rover Project

[Mars-Rover-Document_.pdf](https://github.com/codingadventure0/Rover-using-esp32/files/15357546/Mars-Rover-Document_.pdf)

## Abstract

The Mars Rover Project represents a pioneering effort aimed at designing and developing a robotic rover capable of traversing the challenging terrain of Mars while conducting sophisticated scientific experiments and observations. This multidisciplinary project integrates mechanical engineering, electronics, software development, and robotics, with the rover equipped with a suite of scientific instruments to investigate key aspects of Mars' geology, atmosphere, and potential habitability.

This project is created for showcasing in planetariums as an educational and interactive model to inspire and educate the public about Mars exploration and robotics.

## Key Objectives

1. Design a robust and maneuverable rover chassis capable of traversing diverse Martian landscapes.
2. Develop a sophisticated control system for autonomous navigation, obstacle avoidance, and precise maneuvering.
3. Implement camera and communication systems for real-time data transmission between the rover and mission control on Earth.
4. Conduct comprehensive testing and validation procedures to ensure reliability and performance in simulated Martian environments.

## Components Required

### Receiver
```
1. L298N Motor Driver Module - 1
2. DC Geared Motor (150 rpm) - 6
3. ESP32 (Wi-Fi/BL Module) - 1
4. Li-ion Battery (5200 mAh) - 1
5. CP Plus Camera - 1
6. Wheel - 6
7. Jumper Wires - As per requirement
8. Ply Board - As per requirement
9. PVC Pipes - As per requirement
```

### Transmitter
```
1. ESP32 (Wi-Fi/BL Module) - 1
2. Analog Joystick - 1
3. LED - 1
4. Switch - 1
5. Battery - 3
6. Micro USB Connector - 1
7. Battery Cell Holder (3 Cells) - 1
8. Jumper Wires - As per requirement
9. Ply Board - As per requirement
10. Screw & Hinges - As per requirement
```

## Methodology

### Assembly
- **Receiver:** Assemble the motor driver module, DC motors, ESP32 module, battery, camera, wheels, and necessary wiring on a ply board with PVC pipes for structural support.
- **Transmitter:** Assemble the ESP32 module, joystick, LED, switch, batteries, USB connector, and necessary wiring on a separate ply board.

### Schematic Design
- Detailed circuit diagrams for both receiver and transmitter are drawn to ensure correct connections and integrations of all components.

### Programming
- **Receiver Programming:** Implement control algorithms for motor drivers and integrate camera feed transmission.
- **Transmitter Programming:** Develop the interface for joystick control and LED indicators, ensuring seamless communication with the receiver.

### Arduino Programming
- The project utilizes Arduino programming for the implementation of control systems and communication protocols. The ESP32 module is programmed using the Arduino IDE to handle input from the joystick, control the motors, and manage data transmission between the rover and the control station.

## Testing and Application

Comprehensive testing is conducted in simulated Martian environments to validate the rover's functionality and performance, including:
- Navigation and obstacle avoidance in varied terrains.
- Data transmission tests between the rover and control station.
- Functionality checks for all scientific instruments on board.

## Conclusion

The Mars Rover Project demonstrates technological prowess and contributes to the broader scientific community's efforts in exploring Mars. This project aims to inspire future generations of scientists, engineers, and space enthusiasts while advancing our understanding of Mars and its potential for harboring life.

## Future Scope

Future enhancements include:
- Improved autonomous navigation algorithms.
- Advanced scientific instruments for more detailed geological and atmospheric analysis.
- Integration of new technologies for in-situ resource utilization and long-term missions.

## Planetarium Showcasing

This Mars Rover model is specifically designed for planetarium showcasing. It serves as an educational and interactive exhibit to demonstrate the principles of Mars exploration, robotics, and engineering to the public. The model aims to inspire interest and curiosity about space exploration and science.

## Getting Started

### Prerequisites

- Arduino IDE
- Git

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/mars-rover.git
    cd mars-rover
    ```

2. (Optional) Create and activate a virtual environment:
    ```bash
    python -m venv venv
    source venv/bin/activate  # On Windows use `venv\Scripts\activate`
    ```

3. Install dependencies:
    ```bash
    pip install -r requirements.txt
    ```

### Running the Project

Upload the Arduino code to the ESP32 modules using the Arduino IDE. Ensure the correct board and port settings are configured in the IDE before uploading.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature-name`
3. Make your changes and commit them: `git commit -m 'Add some feature'`
4. Push to the branch: `git push origin feature-name`
5. Submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- NASA for inspiration.
- Contributors and developers who have worked on similar projects.

Thank you for checking out the Mars Rover project! Feel free to reach out if you have any questions or suggestions. Happy coding! 🚀

---
