#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.

  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Waiting for data");
  display.display();
}



void loop() {

  if (Serial.available() > 0)
    {
      String incomingData;

      while (Serial.available() > 0)
        {
          incomingData += (char)Serial.read();
        }

      if (incomingData != "")
        {
          display.clearDisplay();
          display.setCursor(0,0);
          display.print(incomingData);
          display.display();
        }
    }

}
