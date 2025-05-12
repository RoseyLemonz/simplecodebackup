#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 2

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const unsigned char tempImg [] PROGMEM = {
	0x0c, 0x00, 0x1e, 0x00, 0x13, 0x80, 0x13, 0x80, 0x12, 0x00, 0x12, 0x00, 0x13, 0x80, 0x13, 0x80, 
	0x12, 0x00, 0x12, 0x00, 0x13, 0x80, 0x13, 0x80, 0x12, 0x00, 0x12, 0x00, 0x13, 0x80, 0x13, 0x80, 
	0x12, 0x00, 0x1e, 0x00, 0x3f, 0x00, 0x61, 0x80, 0xc0, 0xc0, 0x80, 0x40, 0x80, 0x40, 0x80, 0x40, 
	0xc0, 0xc0, 0x61, 0x80, 0x3f, 0x00, 0x1e, 0x00
};

const unsigned char humiImg [] PROGMEM = {
	0x07, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x19, 0x80, 0x00, 0x30, 0x80, 0x00, 0x60, 0x80, 0x00, 0x44, 
	0x80, 0xc0, 0xcc, 0x81, 0xc0, 0x98, 0x83, 0x40, 0x80, 0x86, 0x60, 0x80, 0x8c, 0x20, 0x81, 0x98, 
	0x20, 0x81, 0x11, 0x20, 0xc3, 0x33, 0x20, 0x7f, 0x26, 0x20, 0x1c, 0x20, 0x20, 0x00, 0x20, 0x20, 
	0x00, 0x20, 0x60, 0x00, 0x30, 0x40, 0x00, 0x38, 0xc0, 0x00, 0x1f, 0xc0, 0x00, 0x07, 0x00
};

uint8_t temptinyImg[] = {0x18, 0x1C, 0x18, 0x1C, 0x18, 0x1C, 0x18, 0x1C, 0x18, 0x3C, 0x7E, 0x7E, 0x7E, 0x3C};

uint8_t humitinyImg[] = {0x00, 0x70, 0x58, 0x78, 0x38, 0x00, 0x1C, 0x16, 0x1E, 0x0E, 0x00, 0x70, 0x58, 0x78, 0x38, 0x00};

int maxtemp, mintemp;
int maxhumi, minhumi;

void setup() 
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);
  
  DHT.read(DHT11_PIN);
  
  mintemp = DHT.temperature;
  maxtemp = DHT.temperature;
  minhumi = DHT.humidity;
  maxhumi = DHT.humidity;
  
}

void loop() 
{
  DHT.read(DHT11_PIN);
  
  //
  //    TEMP
  //

  display.setTextSize(3);
  display.clearDisplay();

  display.drawBitmap(8, 2, tempImg, 10, 28, WHITE);

  display.setCursor(35, 7);
  display.print(DHT.temperature, 1);
  display.setTextSize(1); display.print(" "); display.setTextSize(2); display.print((char)247); display.setTextSize(3); display.print("C");

  display.display();
  delay(5000);

  //
  //    HUMI
  //

  DHT.read(DHT11_PIN);

  display.clearDisplay();

  display.drawBitmap(5, 6, humiImg, 19, 21, WHITE);

  display.setCursor(35, 7);
  display.print(DHT.humidity);
  display.setTextSize(1); display.print(" "); display.setTextSize(3);display.print("%");

  display.display();
  delay(5000);

  //
  //    MAX TEMP / HUMI
  //

  display.clearDisplay();
  display.setTextSize(1);

  display.drawBitmap(0, 0, temptinyImg, 7, 16, WHITE);
  display.setCursor(12, 4);
  display.print("Max Temp:");

  display.drawBitmap(0, 16, humitinyImg, 7, 16, WHITE);
  display.setCursor(12, 22);
  display.print("Max Humi:");

  if (maxtemp < DHT.temperature)
    maxtemp = DHT.temperature;

  if (maxhumi < DHT.humidity)
    maxhumi = DHT.humidity;

  display.setCursor(66, 4);
  display.print(maxtemp);
  display.print(" ");
  display.print((char)247);display.print("C");

  display.setCursor(66, 22);
  display.print(maxhumi);
  display.print(" %");

  display.display();
  delay(2500);

  //
  //    MIN TEMP / HUMI
  //

  display.clearDisplay();
  display.setTextSize(1);

  display.drawBitmap(0, 0, temptinyImg, 7, 16, WHITE);
  display.setCursor(12, 4);
  display.print("Min Temp:");

  display.drawBitmap(0, 16, humitinyImg, 7, 16, WHITE);
  display.setCursor(12, 22);
  display.print("Min Humi:");

  if (mintemp > DHT.temperature)
    mintemp = DHT.temperature;

  if (minhumi > DHT.humidity)
    minhumi = DHT.humidity;

  display.setCursor(66, 4);
  display.print(mintemp);
  display.print(" ");
  display.print((char)247);display.print("C");

  display.setCursor(66, 22);
  display.print(minhumi);
  display.print(" %");

  display.display();
  delay(2500);
}
