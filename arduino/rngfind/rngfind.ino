void setup() 
{
  Serial.begin(9600);
    // random number
  randomSeed(analogRead(0));
}

int number = 0; 
int rollnmbr = 1;

void loop() 
{
    // check if the number is 99
  while(number != 99)
  {
      // draw a number from 0 to 99
    number = random(100);
      // say what the number was
    Serial.println(number);
    rollnmbr++;
    delay(50);
  }
  Serial.print("Number 99 found after ");
      // the number of the roll
  Serial.print(rollnmbr);
  Serial.print(" rolls");

    // stop the program after the testi is done
  //while(1);

    // reset number, so the loop can restart 
    // set the roll number to 1
  number = 0; rollnmbr = 1;
  delay(5000);
}
