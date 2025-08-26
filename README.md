# ESP32-HUB75-Scrolling-Text
A project demonstrating how to create a smooth, horizontally scrolling text marquee on a chain of HUB75 RGB LED matrix panels using an ESP32 microcontroller.

This project provides the code to drive a large RGB LED display made of multiple HUB75 panels chained together. It leverages the processing power of the ESP32 and a specialized library that uses I2S and DMA (Direct Memory Access) to efficiently refresh the display without flickering, making it ideal for creating dynamic signs, information tickers, or decorative visual displays.

Features:
This project's key feature is its ability to create a smooth, continuous scrolling text effect across a large display area composed of four 32x32 panels. It is highly efficient, utilizing the ESP32's I2S peripheral and DMA to handle panel refreshing, which frees up the main processor for other tasks and ensures a flicker-free image. The code is easily configurable, allowing you to change the displayed text, scrolling speed, panel chain length, and brightness with simple modifications to the defined variables.

Hardware Requirements:
To build this project, you will need an ESP32 development board, which is essential for its processing power and DMA capabilities. You will also need one or more HUB75-compatible RGB LED matrix panels (the code is configured for a chain of four 32x32 panels). A stable 5V power supply with sufficient amperage to power all the LED panels is critical, as the ESP32's 5V pin is not adequate. Finally, you will need the necessary jumper wires or a custom PCB to connect the ESP32's GPIO pins to the HUB75 input header on the first panel.

Getting Started:
Follow these instructions to get the project set up and running.

1. Wiring:
The wiring for this project requires connecting numerous GPIO pins from the ESP32 to the 16-pin HUB75 connector on the first LED panel. The specific pin mapping is defined at the top of the sketch and includes connections for the red, green, and blue data lines (R1, G1, B1, R2, G2, B2), the address lines (A, B, C, D, E), and the control signals (LAT, OE, CLK). It is crucial that each pin from the ESP32 is connected to the correct corresponding pin on the HUB75 input. The panels should be chained together by connecting the output of one panel to the input of the next.

2. Installation:
The installation process begins by setting up the Arduino IDE for ESP32 development. If you haven't already, you will need to add the ESP32 board manager URL to your preferences. Next, you must install the ESP32-HUB75-MatrixPanel-I2S-DMA library, which can be found and installed through the Arduino IDE's Library Manager. Once the library is installed, open the sketch_may25b.ino file, connect your ESP32 to the computer, and select the correct ESP32 board and Port from the Tools menu. Finally, click the Upload button to transfer the code to the board.

How It Works:
The system works by leveraging the ESP32-HUB75-MatrixPanel-I2S-DMA library to handle the complex task of driving the LED panels. In the setup() function, the code defines the specific GPIO pin configuration and the physical layout of the display (panel resolution and chain length). It then initializes the DMA display driver with this configuration and sets an initial brightness. The loop() function contains the logic for the animation. It continuously clears the entire display, calculates the new horizontal position for the text, and draws the text string at that position. By incrementally shifting this position in each frame and adding a small delay, it creates the smooth illusion of text scrolling from right to left across the panels.

License:
This project is open source. Feel free to use, modify, and distribute it.
