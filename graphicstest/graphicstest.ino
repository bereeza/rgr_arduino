/***************************************************
  This is our GFX example for the Adafruit ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/


#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// For the Adafruit shield, these are the default.
#define TFT_DC 9
#define TFT_CS 10

// Use hardware SPI (on Uno, #13, #12, #11) and the above for CS/DC
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);
// If using the breakout, change pins as desired
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);

byte customChar[8] = {
	0b00000,
	0b11011,
	0b01010,
	0b01110,
	0b11111,
	0b01110,
	0b01110,
	0b00100
};

void setup() {
  Serial.begin(9600);
  Serial.println("ILI9341 Test!"); 
 
  tft.begin();

  // read diagnostics (optional but can help debug problems)
  uint8_t x = tft.readcommand8(ILI9341_RDMODE);
  Serial.print("Display Power Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDMADCTL);
  Serial.print("MADCTL Mode: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDPIXFMT);
  Serial.print("Pixel Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDIMGFMT);
  Serial.print("Image Format: 0x"); Serial.println(x, HEX);
  x = tft.readcommand8(ILI9341_RDSELFDIAG);
  Serial.print("Self Diagnostic: 0x"); Serial.println(x, HEX); 

  Serial.print(F("Text                     "));
  Serial.println(testText());
  delay(3000);

  Serial.println(F("Done!"));

}


void loop(void) {
    testText();
    delay(1000);
}

unsigned long testText() {
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(2, 2);
  tft.setTextColor(ILI9341_WHITE);  
  tft.setTextSize(3);
  tft.println("RGR:");

  // tft.setCursor(2, 30);
  // tft.setTextColor(ILI9341_GREEN);
  // tft.setTextSize(2);
  // tft.println("Berezanskyi");
  tft.drawBitmap(30, 30, customChar, 8, 8, ILI9341_GREEN, ILI9341_BLACK);
  return micros();
}