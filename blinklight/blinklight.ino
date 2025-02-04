void setup() 
{
  // put your setup code here, to run once:
  
  pinMode(LED_BUILTIN, OUTPUT);  
}

void loop() 

{
  // put your main code here, to run repeatedly:

  // turns on the led
  digitalWrite(LED_BUILTIN, HIGH); 
  delay(100);
  // turns off the led
  digitalWrite(LED_BUILTIN, LOW); 
  delay(100);

  // delay for 1 second
  delay(1000);
}
