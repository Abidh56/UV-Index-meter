#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/Org_01.h>
#include <Fonts/FreeMonoBoldOblique12pt7b.h>
#include <Fonts/FreeMonoBoldOblique9pt7b.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define bitmap_height   128
#define bitmap_width    64
static const unsigned char PROGMEM bitmap[] =
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x7F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x7F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x7F, 0xF0, 0x00, 0x00, 0x7F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x7F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x1F, 0xFF, 0xC0, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x03, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x79, 0xE0, 0x00, 0x0F, 0x00, 0x00,
0x00, 0x0F, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x79, 0xF0, 0x00, 0x1F, 0x00, 0x00,
0x00, 0x3F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x79, 0xF0, 0x00, 0x1E, 0x00, 0x00,
0x00, 0x7F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0xF8, 0x00, 0x3E, 0x00, 0x00,
0x00, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x78, 0x00, 0x3C, 0x00, 0x00,
0x01, 0xFE, 0x00, 0x40, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x7C, 0x00, 0x7C, 0x00, 0x00,
0x03, 0xFC, 0x01, 0xF0, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x3C, 0x00, 0xF8, 0x00, 0x00,
0x07, 0xF8, 0x07, 0xE0, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x3E, 0x00, 0xF8, 0x00, 0x00,
0x0F, 0xF0, 0x0F, 0xC0, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x1F, 0x01, 0xF0, 0x00, 0x00,
0x0F, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x1F, 0x01, 0xE0, 0x00, 0x00,
0x1F, 0xE0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x0F, 0x83, 0xE0, 0x00, 0x00,
0x1F, 0xE0, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x07, 0x83, 0xC0, 0x00, 0x00,
0x1F, 0xE0, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x07, 0xC7, 0xC0, 0x00, 0x00,
0x1F, 0xE0, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x78, 0x03, 0xCF, 0x80, 0x00, 0x00,
0x1F, 0xE0, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x80, 0x00, 0xF8, 0x03, 0xEF, 0x80, 0x00, 0x00,
0x1F, 0xE0, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x01, 0xF0, 0x01, 0xFF, 0x00, 0x00, 0x00,
0x1F, 0xE0, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x03, 0xE0, 0x03, 0xF0, 0x01, 0xFE, 0x00, 0x00, 0x00,
0x0F, 0xF0, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x07, 0xC0, 0x00, 0xFE, 0x00, 0x00, 0x00,
0x0F, 0xF8, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x80, 0x00, 0x7C, 0x00, 0x00, 0x00,
0x07, 0xF8, 0x0F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFE, 0x00, 0x00, 0x7C, 0x00, 0x00, 0x00,
0x03, 0xFC, 0x03, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0xFE, 0x00, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xFF, 0x80, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x7F, 0xE0, 0x07, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x3F, 0xF8, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x01, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0F, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x03, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x1F, 0xFF, 0xF8, 0x00, 0x01, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x7F, 0xFF, 0xFF, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


void uv_index()
{

  float sensorVoltage; 
  float sensorValue;
  int UV_index;
  String quality =""; 
  sensorValue = analogRead(A0);
  sensorVoltage = sensorValue/1024*5.0;
  UV_index= sensorVoltage/0.1;


 //condition for UV state
 if(UV_index<=2){ 
   quality = "   LOW ";
  }

  else if(UV_index > 2 && UV_index <=5){
   quality = "   MOD ";
  }

  else if(UV_index>5 && UV_index<=7){
   quality = "   HIGH ";
  }

  else if(UV_index>7 && UV_index<=10){
   quality = "VERY HIGH";

  }

  else{
   quality = " EXTREME ";
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(2);
  display.setCursor(16, 6);
  display.setFont(&Org_01);
  display.println("UV INDEX");
  display.setCursor(53, 35);
  display.setTextSize(1);
  display.setFont(&FreeMonoBoldOblique12pt7b);
  display.println(UV_index);
  display.setTextSize(2);
  display.setCursor(10, 55);
  display.setFont();
  display.println(quality);   
  display.display();  
  delay(1000);

}

void setup() {
  Serial.begin(9600);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
  }
  showBitmap();
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(15, 9);
  display.setFont(&FreeMonoBoldOblique12pt7b);
  display.println("INDEX");
  display.setTextSize(1);
//    display.setFont();
  display.setCursor(55, 37);
  display.setFont(&FreeSans9pt7b);
  display.println("meter");
  display.display();
  delay(1000);
}

void loop() {
  display.clearDisplay();
  uv_index();

}

void showBitmap(void) {
  display.clearDisplay();

  display.drawBitmap(5, 0, bitmap, bitmap_height, bitmap_width, WHITE);
  display.display();
  delay(2000);
}
