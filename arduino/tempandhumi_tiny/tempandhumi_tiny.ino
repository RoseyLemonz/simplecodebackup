#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN 8

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

uint8_t tempImg[] = {0x18, 0x1C, 0x18, 0x1C, 0x18, 0x1C, 0x18, 0x1C, 0x18, 0x3C, 0x7E, 0x7E, 0x7E, 0x3C};

uint8_t humiImg[] = {0x00, 0x70, 0x58, 0x78, 0x38, 0x00, 0x1C, 0x16, 0x1E, 0x0E, 0x00, 0x70, 0x58, 0x78, 0x38, 0x00};

void setup() 
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextWrap(false);
  display.setTextSize(1);
}

void loop() 
{
  DHT.read(DHT11_PIN);
  display.clearDisplay();

  display.drawBitmap(0, 0, tempImg, 7, 16, WHITE);
  display.setCursor(12, 4);
  display.print("Temp:");

  display.drawBitmap(0, 16, humiImg, 7, 16, WHITE);
  display.setCursor(12, 22);
  display.print("Humi:");

  display.setCursor(52, 4);
  display.print(DHT.temperature);
  display.print(" ");
  display.print((char)247);display.print("C");

  display.setCursor(52, 22);
  display.print(DHT.humidity);
  display.print(" %");

  display.display();
  delay(1000);
}
