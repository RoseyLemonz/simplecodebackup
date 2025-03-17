  // define all the leds and their conneting pins
#define LD1 19
#define LD2 18
#define LD3 17 
#define LD4 16
#define LD5 15
#define LD6 14
#define LD7 9
#define LD8 8
  // define the buttons
  // S = Switch = Button
#define S1 6
#define S2 5
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
}


void loop() 
{
    


}
