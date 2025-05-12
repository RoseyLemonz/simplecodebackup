#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define buttonVal  0

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

bool clockState = 0;

int timeS = 0, timeM = 0, timeH = 0;
// easily test values
//int timeS = 0, timeM = 59, timeH = 9;

// cheat sheet for the buttons
/*
if (analogRead(buttonVal) < 50 && analogRead(buttonVal) >= 0)   // right
if (analogRead(buttonVal) < 200 && analogRead(buttonVal) > 50)  // up
if (analogRead(buttonVal) < 400 && analogRead(buttonVal) > 200) // down
if (analogRead(buttonVal) < 600 && analogRead(buttonVal) > 400) // left
if (analogRead(buttonVal) < 800 && analogRead(buttonVal) > 600) // select 
*/

void loop() 
{
  lcd.setCursor(0, 0);
  lcd.print("Select = Start");

  if (analogRead(buttonVal) < 800 && analogRead(buttonVal) > 600)     // select 
  {
    lcd.clear();
    timeS = 0;
    timeM = 0;
    timeH = 0;
    clockState = 1;
  }

  while (clockState == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print("D=Stop, U=Reset");

    lcd.setCursor(0,0);

    if (timeH < 10)
      lcd.print("0");
    lcd.print(timeH);
    lcd.print(":");

    if (timeM < 10)
      lcd.print("0");
    lcd.print(timeM);
    lcd.print(":");

    if (timeS < 10)
      lcd.print("0");
    lcd.print(timeS);

    timeS++;

    if (timeS == 60)
    {
      timeS = 0;
      timeM++;

      if (timeM == 60)
      {
        timeM = 0;
        timeH++;

        if (timeH == 100)
        {
          timeS = 0;
          timeM = 0;
          timeH = 0;
        }
      }
    }

    if (analogRead(buttonVal) < 200 && analogRead(buttonVal) > 50)  // up
    {
      timeS = 0;
      timeM = 0;
      timeH = 0;
    }

    if (analogRead(buttonVal) < 400 && analogRead(buttonVal) > 200) // down
    {
      clockState = 0;
    }

    delay(1000);
    lcd.clear();
    Serial.println(analogRead(buttonVal));
    Serial.println(clockState);
  }
}

