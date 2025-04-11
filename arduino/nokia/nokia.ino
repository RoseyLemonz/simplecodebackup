#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

uint8_t tempImg[] = {0x18, 0x1C, 0x18, 0x1C, 0x18, 0x1C, 0x18, 0x1C, 0x18, 0x3C, 0x7E, 0x7E, 0x7E, 0x3C};

uint8_t clockImg[] = {0x18, 0x1C, 0x18, 0x1C, 0x18, 0x1C, 0x18, 0x1C, 0x18, 0x3C, 0x7E, 0x7E, 0x7E, 0x3C};

uint8_t humiImg[] = {0x00, 0x70, 0x58, 0x78, 0x38, 0x00, 0x1C, 0x16, 0x1E, 0x0E, 0x00, 0x70, 0x58, 0x78, 0x38, 0x00};

void setup()   
{
	Serial.begin(9600);

	display.begin();
	display.setContrast(66);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);

  display.drawBitmap(0, 0, tempImg, 7, 16, BLACK);
  display.setCursor(12, 4);
  display.print("Temp:");

  display.drawBitmap(0, 32, humiImg, 7, 16, BLACK);
  display.setCursor(12, 37);
  display.print("Humi:");

  display.setCursor(76, 4);
  display.drawCircle(74, 4, 1, 1);
  display.print("C");

  display.setCursor(76, 37);
  display.print("%");

  delay(2000);
  display.display();
}

void loop() 
{

  float temp = 25.5;
  int humi = 67;

  display.setCursor(42, 4);
  display.print(temp, 1);

  display.setCursor(42, 37);
  display.print(humi);

  delay(2000);
  display.display();

  /*
  int x;
  int y;
  int z;
  int color;

  x = random(0,84);
  y = random(0,48);
  z = random (0,2);
  
  if (z == 0)
    color = WHITE;
  else
    color = BLACK;

  display.drawPixel(x, y, color);
  display.display();
  delay(5);
  */
}