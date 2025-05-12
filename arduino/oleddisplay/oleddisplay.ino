#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define S1 8
#define S2 9

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() 
{
  Serial.begin(9600);

  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.display();
  delay(2000);
  display.setTextColor(SSD1306_WHITE);
}

bool started = false;
bool S2Pressed = false;
int timestep = 5;
int timer = timestep;

void loop() 
{

    display.clearDisplay();
    display.setTextSize(1);

    display.setCursor(0, 0);
    display.print("Please set timer");

    display.setCursor(0, 25);
    display.print("Current timer: ");
    display.print(timer);

    display.display();

    if (digitalRead(S1) == LOW)
    {
      started = true;
    }

    if (digitalRead(S2) == LOW && S2Pressed == false)
    {
      timer += timestep;
      S2Pressed = true;
      delay(50);
    }

    if (digitalRead(S2) == HIGH && S2Pressed == true)
    {
      S2Pressed = false;
    }

  	while (started == true)
    {
      display.clearDisplay();
      display.setTextSize(3);
      display.setCursor(0, 6);
      display.print(timer);
      display.display();
      timer--;
      delay(1000);
      if (timer == 0)
      {
        display.clearDisplay();
        display.setCursor(0, 10);
        display.setTextSize(2);
        display.print("TIMES UP!");
        display.display();
        delay(3500);
        timer = timestep;
        break;
      }
    }
    started = false;
}
