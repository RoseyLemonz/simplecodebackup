#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define UP 3
#define DOWN 2

#define STAR_HEIGHT   6
#define STAR_WIDTH    6

const unsigned char star_bmp [] PROGMEM = {
	0x10, 0x30, 0xf8, 0x7c, 0x30, 0x20
};

#define MAN_HEIGHT   16
#define MAN_WIDTH    7

const unsigned char PROGMEM man_bmp[] = {
	0x38, 0x7c, 0x7c, 0x7c, 0x38, 0x10, 0x10, 0x7c, 0xd6, 0x92, 0x92, 0x38, 0x28, 0x6c, 0x44, 0x44
};

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  delay(2000);
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);

  display.setCursor(10, 10);
  display.println("3...");
  display.display();
  delay(1000);
  
  display.clearDisplay();
  display.setCursor(10, 10);
  display.println("2..");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.setCursor(10, 10);
  display.println("1.");
  display.display();
  delay(1000);

  display.clearDisplay();
  display.setCursor(10, 10);
  display.println("GO!");
  display.display();
  delay(1000);

  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  display.clearDisplay();
}

int man_y = 10;
int starscore = 0;
bool pAlive = true;

void loop() 
{
  int star_y = random(0,26);
  for (int star_x = -12; star_x < 128; star_x += 2) 
  {
    Serial.println(star_x);

    // player input

    if (digitalRead(UP) == LOW)
    {
      man_y++;
    }

    if (digitalRead(DOWN) == LOW)
    {
      man_y--;
    }

    if (digitalRead(DOWN) == LOW && digitalRead(UP) == LOW && pAlive == false)
    {
      display.clearDisplay();
      display.setTextSize(3);

      display.setCursor(10, 10);
      display.println("3...");
      display.display();
      delay(1000);
      
      display.clearDisplay();
      display.setCursor(10, 10);
      display.println("2..");
      display.display();
      delay(1000);

      display.clearDisplay();
      display.setCursor(10, 10);
      display.println("1.");
      display.display();
      delay(1000);

      display.clearDisplay();
      display.setCursor(10, 10);
      display.println("GO!");
      display.display();
      delay(1000);

      pAlive = true; 
      star_x = -12;
      display.setTextSize(1);
      display.setCursor(0, 26);
      display.print("Score: ");
      display.print(starscore);
    }

    else if (pAlive == false)
    {
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 16);
      display.setTextWrap(true);
      display.print("You Died! Press both buttons to restart.");

      star_y = 4;
    }

    // collision check
    if (man_y < -10)
    {
      man_y = -10;
    }

    if (man_y > 26)
    {
      man_y = 26;
    }

    if (star_x >= 117)
    {
      if ((star_y+STAR_HEIGHT) >= man_y && star_y <= (man_y+MAN_HEIGHT))
      {
        pAlive = false;
        star_x = 128;
      }
      else
      {
        starscore += 1;
      }
    }

    // draw projectile and player
    display.drawBitmap(star_x, star_y, star_bmp, STAR_WIDTH, STAR_HEIGHT, WHITE);

    // check if player is alive
    if (pAlive == true)
    {
      display.drawBitmap(121, man_y, man_bmp, MAN_WIDTH, MAN_HEIGHT, WHITE);
    }

    // draw score
    display.setTextSize(1);
    display.setCursor(0, 24);
    display.print("Score: ");
    display.print(starscore);

    display.display();
    delay(20);
    display.clearDisplay();
  }
}
