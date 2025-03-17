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

  int seed = 0;                       // scramble random funktion
  while(digitalRead(S4) == HIGH)     // wait until s4 is pressed down
  {
    seed++;
  }

  Serial.begin(9600);                 // initialize serial connection
//  Serial.println(seed);               // print the seeds value
  randomSeed(seed);                   // set the seed to a random value
  SetLeds(0x01);                      // 
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

uint8_t ruletti = 0x01;         // 0000 0001
uint8_t run = 0;                // how many loops the roulette will spin
bool    hascalc = false;          // have the results been calculated

uint8_t led1 = 0;
uint8_t led2 = 0;
uint8_t led3 = 0;
uint8_t led4 = 0;
uint8_t led5 = 0;
uint8_t led6 = 0;
uint8_t led7 = 0;
uint8_t led8 = 0;
uint8_t ledzeppelin = 0;
// uint16_t viive = 50;

void loop() 
{
  if(digitalRead(S4) == 0)      // if buttons s4 is pressed down...
  {
    ruletti = 0;
    // viive = 25;                 // reset viive from the slowdown...
    run = random(60, 160);                 // and draw the number of loops
    hascalc = false;
  }

  if(run > 0)                   // is the routlette still spinning?
  {
    SetLeds(ruletti);           // print the roulettes value to the led
    ruletti <<= 1;              // move to the next led
    run--;                      // subtract the number of rolls
    // delay(viive);                      
  }

/*
  if(run<25)                  // slowdown roulette when its below the specified value
  {
    viive += 5;
  }
*/

  if(ruletti == 0)              // if the roulette overflows...
  {
    ruletti = 0x01;             // reset it
  }

  if(run == 0)
  {
    if(hascalc == false)                // have the results already been calculated?
    {
      ruletti >>= 1;
      switch (ruletti)
      {
        case 0x00: led1++; break; case 0x40: led2++; break;
        case 0x20: led3++; break; case 0x10: led4++; break;
        case 0x08: led5++; break; case 0x04: led6++; break;
        case 0x02: led7++; break; case 0x01: led8++; break;
      }
      Serial.print(led1); Serial.print(" "); Serial.print(led2); Serial.print(" "); 
      Serial.print(led3); Serial.print(" "); Serial.print(led4); Serial.print(" ");
      Serial.print(led5); Serial.print(" "); Serial.print(led6); Serial.print(" ");
      Serial.print(led7); Serial.print(" "); Serial.print(led8); Serial.println();
    }  
    hascalc = true;
  }

  switch(run)                       // make the roulette slowdown as it gets closer to the result
  {
    case 6: delay(75); break;
    case 5: delay(112); break;
    case 4: delay(169); break; 
    case 3: delay(253); break;
    case 2: delay(378); break;
    case 1: delay(570); break;
    default: delay(50); break;
  }

}
