#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
}

#define ARROW_LEFT  B01111110
#define ARROW_RIGHT B01111111

bool lArrowRow = 0;
bool rArrowRow = 1;

void loop() {
  for (int col = 0, bcol = 15; col<16, bcol>-1; col++, bcol--)
  {
    lcd.setCursor(col-1, lArrowRow);
    lcd.write(" ");
    lcd.setCursor(col, lArrowRow);
    lcd.write(ARROW_LEFT);

    lcd.setCursor(bcol+1, rArrowRow);
    lcd.write(" ");
    lcd.setCursor(bcol, rArrowRow);
    lcd.write(ARROW_RIGHT);

    delay(500);
  }

  if (lArrowRow == 0)
  {
    lArrowRow = 1;
  }
  else if(lArrowRow == 1)
  {
    lArrowRow = 0;
  }
  if(rArrowRow == 0)
  {
    rArrowRow = 1;
  }
  else if(rArrowRow == 1)
  {
    rArrowRow = 0;
  }
}

