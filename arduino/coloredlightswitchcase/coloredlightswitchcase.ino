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

  switch (tila)
  {
      // make led red
    case 1:
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      break;
      // make led green
    case 2:
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      break;
      // make led orange / yellow
    case 3:
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, HIGH);
      break;
      // default to led being off
    default:
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      break;
  }

}

void loop()
{
  for (int i=0; i<4; i++)
    {
      setled(i);
      delay(500);
    }
}
