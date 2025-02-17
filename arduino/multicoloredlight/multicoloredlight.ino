#define LED_R 2
#define LED_G 3

void setup() 
{
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
}

void loop()
{

  // turns on the red led and off the green led
  digitalWrite(LED_R, HIGH); 
  digitalWrite(LED_G, LOW);  
  delay(500);
  // turns off the red led and on the green led
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, HIGH);  
  delay(500);
  // orange :::::::::::::::) , well yellow but it looks orange on the led :::)
  digitalWrite(LED_R, HIGH);
  digitalWrite(LED_G, HIGH);  
  delay(500);

}
