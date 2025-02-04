void setup() 
{
  // put your setup code here, to run once:
  
  pinMode(LED_BUILTIN, OUTPUT);  
}

void loop() 

{
  // put your main code here, to run repeatedly:

  // repeat 5 times
  for(int i=0; i<5; i++)
  {
    // turns on the led
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(100);
    // turns off the led
    digitalWrite(LED_BUILTIN, LOW); 
    delay(100);
  }

  // after loop, delay for 2 seconds
  delay(2000);
}
