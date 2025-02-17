  // led red on pin 2
#define LED_R 2
  // led green on pin 3
#define LED_G 3

  // led is off
#define NONE  0
  // led is red
#define RED   1
  // led is green
#define GRN   2

void setup() 
{
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
}

void setled (uint8_t tila)
{
    // is the value 1?
  if (tila == RED)
  {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
  }
    // 2?
  else if (tila == GRN)
  {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
  }
    // something else?
  else
  {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
  }

}

void loop()
{
  for (int i=0; i<3; i++)
    {
      setled(i);
      delay(500);
    }
}
