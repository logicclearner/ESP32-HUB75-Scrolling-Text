#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define R1_PIN 23
#define G1_PIN 21
#define B1_PIN 22
#define R2_PIN 4
#define G2_PIN 19
#define B2_PIN 15

#define A_PIN 5
#define B_PIN 33
#define C_PIN 18
#define D_PIN 17
#define E_PIN 16

#define LAT_PIN 32
#define OE_PIN 25
#define CLK_PIN 26

#define PANEL_RES_X 32  // Width of each panel module in pixels
#define PANEL_RES_Y 32  // Height of each panel module in pixels
#define PANEL_CHAIN 4   // Number of panels chained together

MatrixPanel_I2S_DMA *dma_display = nullptr;

void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  delay(1000);

  // Define pin configuration for HUB75 panels
  HUB75_I2S_CFG::i2s_pins _pins = {R1_PIN, G1_PIN, B1_PIN, R2_PIN, G2_PIN, B2_PIN, A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, LAT_PIN, OE_PIN, CLK_PIN};
  
  // Create configuration object for the panels
  HUB75_I2S_CFG mxconfig(PANEL_RES_X, PANEL_RES_Y, PANEL_CHAIN, _pins);
  
  // Set I2S clock speed
  mxconfig.i2sspeed = HUB75_I2S_CFG::HZ_10M;

  // Initialize the DMA driven display
  dma_display = new MatrixPanel_I2S_DMA(mxconfig); 
  dma_display->begin();
  dma_display->setBrightness8(35); // Set brightness (0-255)

  dma_display->clearScreen(); // Clear the screen initially
}
    
void loop() {
  String text = "START"; // Text to display
  int textWidth = text.length() * 6; // Width of the text in pixels

  int startX = PANEL_CHAIN * PANEL_RES_X; // Start text off-screen on the right

  while (true) {
    dma_display->clearScreen(); // Clear the screen for each frame

    int panelStartX = startX;

    // Draw the text
    dma_display->setCursor(panelStartX, 0);
    dma_display->setTextColor(dma_display->color565(255, 255, 255)); // White text color
    dma_display->setTextSize(1);
    dma_display->print(text);

    startX -= 1; // Update position for the next frame

    // Reset position if text has fully scrolled off the left edge
    if (panelStartX < -textWidth) {
      startX = PANEL_CHAIN * PANEL_RES_X;
    }

    delay(30); // Delay to control scrolling speed
  }
}
