# CSGO Replica Game on Arduino

## Introduction

This project is a replica of the popular game Counter-Strike: Global Offensive (CSGO) implemented on an Arduino Uno. It features four game modes, labeled A, B, C, and D, which can be activated using an 8x8 keypad. The game also utilizes an LCD with I2C interface, a buzzer, and an LED to enhance the gameplay experience.

## Materials

- Arduino Uno
- LCD with I2C interface
- Buzzer
- LED
- 8x8 Keypad
- Jumper wires
- Breadboard

## Features

- **Four Game Modes**: Activate different game modes using the keypad.
  - **Mode A**
  - **Mode B**
  - **Mode C**
  - **Mode D**
- **LCD Display**: Provides visual feedback and instructions.
- **Buzzer**: Generates sound effects.
- **LED**: Indicates game status.

## Installation

1. **Clone the Repository**:
   ```sh
   git clone https://github.com/Matias-Leiva/csgo-replica-arduino.git
   cd csgo-replica-arduino

2. **Install Required Libraries**:
   - Install the [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C) library for the LCD.
   - Install any other necessary libraries for the keypad and buzzer.

3. **Upload the Code**:
   - Open the Arduino IDE.
   - Load the `csgo-replica.ino` file from the cloned repository.
   - Select the appropriate board and port in the Arduino IDE.
   - Upload the code to the Arduino Uno.

## Wiring Diagram

Follow the wiring diagram below to connect all the components to the Arduino Uno:

- **LCD with I2C**:
  - VCC to 5V
  - GND to GND
  - SDA to A4
  - SCL to A5

- **Buzzer**:
  - Positive pin to Digital Pin 10
  - Negative pin to GND

- **LED**:
  - Anode (long leg) to Digital Pin 11 (with a 220Ω resistor)
  - Cathode (short leg) to GND

- **8x8 Keypad**:
  - Connect rows and columns to the appropriate digital pins 2 - 9.

## Usage

1. **Power Up**: Connect your Arduino Uno to a power source or your computer via USB.
2. **Start the Game**: The LCD will display the main menu. Use the keypad to navigate and select a game mode.
3. **Play**: Follow the on-screen instructions to play the selected game mode. The buzzer and LED will provide audio and visual feedback respectively.

## Contributing

We welcome contributions to enhance the project. Please fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Contact

For any inquiries or issues, please open an issue on the GitHub repository or contact the project maintainer at [info@leivamatias.com](mailto:info@leivamatias.com).

---

Enjoy your CSGO replica game on Arduino!