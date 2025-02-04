#define SHORT 200
#define LONG (3 * SHORT)

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  // three short blinks. S
  for (int s1=0; s1<3; s1++)
  {
    // turn on led
    digitalWrite(LED_BUILTIN, HIGH);
    delay(SHORT);
    // turn off led
    digitalWrite(LED_BUILTIN, LOW);
    delay(SHORT);
  }

  delay(SHORT);

  // three long blinks. O
  for (int o=0; o<3; o++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(LONG);
    digitalWrite(LED_BUILTIN, LOW);
    delay(LONG);
  }

  delay(SHORT);

  // three short blinks. S
  for (int s2=0; s2<3; s2++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(SHORT);
    digitalWrite(LED_BUILTIN, LOW);
    delay(SHORT);
  }

  // delay for 2 seconds, then loop
  delay(2000);
}
