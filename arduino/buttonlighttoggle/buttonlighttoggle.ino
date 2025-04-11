#define S1 7
#define S2 6
#define LED_R 2
#define LED_G 3

void setup() 
{
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);

  pinMode(S1, INPUT_PULLUP);
  pinMode(S2, INPUT_PULLUP);

  digitalWrite(LED_R, HIGH);
}

void loop()
{
  if (digitalRead(S1) == LOW && digitalRead(LED_G) == HIGH)
  {
    digitalWrite(LED_R, HIGH);
    digitalWrite(LED_G, LOW);
    delay(20);
  }

  if (digitalRead(S2) == LOW && digitalRead(LED_R) == HIGH)
  {
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, HIGH);
    delay(20);
  }
}
