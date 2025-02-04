void setup() 
{
    // Sarjaliikenteenalustus. Tiedonsiirot nopeus 9600 b/s
  Serial.begin(9600);
}

  // kokonaislukumuuttaha, jonka nimi on counter
int counter_u = 0;
int counter_d = 100;

int satu = 0;

void loop() 
{
    
    // \n = new line, \r = also new line maybe i dont actually know. use both when coding for windows. linux and other unix likes prob only need \n
    // \t = tab

/*
  Serial.print("Ylös: \t");
    // print the output of counter_u and incriment it by one
  Serial.println(++counter_u);
  Serial.print("Alas: \t");
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

  for (int counter_u=0; counter_u<10; counter_u++)
  {
  satu = random(10);
  Serial.print(satu);
  delay(200);
  }
  
  delay(8000);
}
