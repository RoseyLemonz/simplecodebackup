
  // purple led on pin 2
#define LED_P 2
  // white led on pin 3
#define LED_W 3
  // yellow button on pin 8
#define BTN_W 8
  // red button on pin 9
#define BTN_R 9

void setup() 
{
  pinMode(LED_P, OUTPUT);
  pinMode(LED_W, OUTPUT);
  pinMode(BTN_W, INPUT_PULLUP);
  pinMode(BTN_R, INPUT_PULLUP);
}

  // white button modifier
int btn_w = 1;
  // red button modifier
int btn_r = 1; 
  // white led is off
bool white = false; 
  // purple led is off
bool purp = false;

void loop()
{
    // read the white buttons mode
  btn_w = digitalRead(BTN_W);
    // if the white button is pressed down...
  if (btn_w == 0)
  {
    if (white == true)
    {
      digitalWrite(LED_W, LOW);
        // mark the white led as off
      white = false;
    }
    else
    {
      digitalWrite(LED_W, HIGH);
      // mark the white led as on
      white = true;
    }

    // repeat as long as the button is pressed down
    while(btn_w == 0)
    {
      delay(10);
      btn_w = digitalRead(BTN_W);
    }
    delay(10);
  }   // end of if
  delay(10);

    // same but purple led and red button
  btn_r = digitalRead(BTN_R);
  if (btn_r == 0)
  {
    if (purp == true)
    {
      digitalWrite(LED_P, LOW);
      purp = false;
    }
    else
    {
      digitalWrite(LED_P, HIGH);
      purp = true;
    }

    while(btn_r == 0)
    {
      delay(10);
      btn_r = digitalRead(BTN_R);
    }
    delay(10);
  }   // end of if
  delay(10);

  // simple buttons
  /*
    // read the buttons mode
  btn_w = digitalRead(BTN_W);
  btn_r = digitalRead(BTN_R);

    // if the white button is pressed down,
  if (btn_w == 0)
  {
      // light the white led
    digitalWrite(LED_W, HIGH);
  }
    // otherwise,
  else
  {
      // keep it off
    digitalWrite(LED_W, LOW);
  }
    // same but purple led and red button
  if (btn_r == 0)
  {
    digitalWrite(LED_P, HIGH);
  } 
  else
  {
    digitalWrite(LED_P, LOW);
  }
  */

} // end of loop
