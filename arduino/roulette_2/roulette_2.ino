#define LD1 19             // define all the leds and their conneting pins
#define LD2 18
#define LD3 17 
#define LD4 16
#define LD5 15
#define LD6 14
#define LD7 9
#define LD8 8

#define S1 6                // define the buttons
#define S2 5                // S = Switch = Button
#define S3 3
#define S4 2  

#define lightdelay 40


void setup() 
{
  pinMode(LD1, OUTPUT);
  pinMode(LD2, OUTPUT);
  pinMode(LD3, OUTPUT);
  pinMode(LD4, OUTPUT);
  pinMode(LD5, OUTPUT);
  pinMode(LD6, OUTPUT);
  pinMode(LD7, OUTPUT);
  pinMode(LD8, OUTPUT);

  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);
  pinMode(S3, INPUT_PULLUP);
  pinMode(S4, INPUT_PULLUP);
}

/*
    function sets the 8 leds states
    parameter 0x00...0xFF
*/
void SetLeds(uint8_t ledState)
{
  if(ledState & 0x80) digitalWrite(LD1, HIGH); else digitalWrite(LD1, LOW);
  if(ledState & 0x40) digitalWrite(LD2, HIGH); else digitalWrite(LD2, LOW); 
  if(ledState & 0x20) digitalWrite(LD3, HIGH); else digitalWrite(LD3, LOW); 
  if(ledState & 0x10) digitalWrite(LD4, HIGH); else digitalWrite(LD4, LOW); 
  if(ledState & 0x08) digitalWrite(LD5, HIGH); else digitalWrite(LD5, LOW); 
  if(ledState & 0x04) digitalWrite(LD6, HIGH); else digitalWrite(LD6, LOW); 
  if(ledState & 0x02) digitalWrite(LD7, HIGH); else digitalWrite(LD7, LOW); 
  if(ledState & 0x01) digitalWrite(LD8, HIGH); else digitalWrite(LD8, LOW); 
}

uint8_t ruletti = 0x01;
uint8_t extra = 0;

void loop() 
{

  if (digitalRead(S4) == LOW || extra > 0)
  {
    SetLeds(ruletti);           // shows modifiers value in leds
    ruletti <<= 1;              // shift the bits 1 step left

    if (ruletti == 0)           // have we gone over?
    {
      ruletti = 0x01;           // if we have, go again
    }
    
    if (digitalRead(S4) == LOW) 
    {
      extra++;
    }
    else 
    {
      extra--;
    }

    delay(20);                  // put here a fitting delay
  }
}
