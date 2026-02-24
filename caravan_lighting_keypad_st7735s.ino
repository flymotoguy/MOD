# ST7735S Display with 4x4 Matrix Keypad Integration

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <Keypad.h>

// Pin definitions
#define TFT_CS     10  // Chip select pin for display
#define TFT_RST    9   // Reset pin for display
#define TFT_DC     8   // Data/Command pin for display

// Create the display object
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_RST, TFT_DC);

// Keypad settings
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = { {'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'} };
byte rowPins[ROWS] = { 5, 4, 3, 2 }; // connect to the row pinouts of the keypad
byte colPins[COLS] = { 12, 11, 10, 9 }; // connect to the column pinouts of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  tft.init();  // Initialize the touchscreen
  tft.fillScreen(ST7735_BLACK);  // Clear the screen
  tft.setTextColor(ST7735_WHITE);  // Set text color
  tft.setTextSize(1);  // Set text size
  tft.setCursor(0, 0);  // Set cursor position
  tft.println("Initialized Display and Keypad");
}

void loop() {
  char key = keypad.getKey();
  if (key) {  // If a key is pressed
    tft.setCursor(0, 20);  // Move cursor
    tft.fillRect(0, 20, 128, 16, ST7735_BLACK);  // Clear previous text
    tft.print("Key Pressed: ");
    tft.println(key);  // Display pressed key on screen
  }
}