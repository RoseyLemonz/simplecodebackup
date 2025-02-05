void setup() 
{
    // Sarjaliikenteenalustus. Tiedonsiirot nopeus 9600 b/s
  Serial.begin(9600);
  //delay(100);
    // flush garbage data, doesnt fix issue so commented out
  //Serial.flush();
}

  // muuttajien esittely
  // int = tietotyyppi ---> numero -32678...+32678
  // muuttajan nimi perään

int counter_u = 0;
int counter_d = 100;
int row_nmbr = 1;
int rndm = 0;

void loop() 
{
    
    // \n = new line
    // \r = also new line maybe i dont actually know. use both when coding for windows. linux and other unix likes prob only need \n
    // \t = tab

/*
  Serial.print("Up: \t");
    // print the output of counter_u and incriment it by one
  Serial.println(++counter_u);
  Serial.print("Down: \t");
    // print the output of counter_d and reduce it by one
  Serial.println(--counter_d);
  delay(3000);
    // random stuff i wanted to add lol
  Serial.println("I speak English.");
  delay(2000);
  Serial.println("So you know what ASSHOLE means.");
    // breaking bad :))
*/
/*
  Serial.print("Testi");
    // new line in dec
  //Serial.write(10);
    // new line in hex
  //Serial.write(0x0A);
    // new line in bin
  Serial.write(0b00001010);
*/
/*
  Serial.print(counter_u);
  Serial.print(" -> ");
  Serial.write(counter_u);
  Serial.write(10);
  counter_u++;
*/
/*
  satu = random(10);
  satu++;
  Serial.println(satu);
*/

    // 10 loops of 10 random numbers
    
    // int counter_y=0: sets the base value of the integer
    // counter_y<10: checks if the counter is below 10, if true, then proceed
    // counter_y++: incriment by one

  for (int counter_y=0; counter_y<10; counter_y++)
  {
      // display the value of row_nmbr before each set of numbers and incriment it by one
    Serial.print(row_nmbr++);
    Serial.print(": ");

    for (int counter_x=0; counter_x<7; counter_x++) 
    {
        // draws a random number and set rndm as it
      rndm = random(10);
        // prints result of the random number as
      Serial.print(rndm);
        // tab
      Serial.print("\t");
    }
      // put next set on a new line
    Serial.println();
  }
    // when the for loop has completed, make new line
  Serial.println();

  //delay(5000); 
}
