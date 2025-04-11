#define D0  11
#define D1  10
#define D2  9
#define D3  8

void setup() 
{
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  Serial.begin(9600);     // establish serial connection
}

void num(uint8_t n)
{
  digitalWrite(D3, 0); digitalWrite(D2, 0); digitalWrite(D1, 0); digitalWrite(D0, 0); 

  switch (n)
  {
    case 0: digitalWrite(D0, 1);
            break;
    case 1: digitalWrite(D1, 1);
            break;
    case 2: digitalWrite(D2, 1);
            break;
    case 3: digitalWrite(D3, 1);
            break;
  }
}

/*
 * funktio palauttaa tilatun kerroksen numeron 0 (P-kerros), 1 ,2 tai 3
 * jos mitään kerrosta ei ole tilattu, palautetaan arvo -1
 */

int onkoTilattu()
{
  int merkki = 0;
  int retu = -1;

  if (Serial.available() > 0)
  {
    merkki = Serial.read();
    Serial.println(merkki);
  }

  switch (merkki) 
  {
    case 112:
    case 80:  retu = 0; break;
    case 49:  retu = 1; break;
    case 50:  retu = 2; break;
    case 51:  retu = 3; break;
    default:  retu = -1;
  }
  return retu;
}

int nykyinenKerros = 0,
int tilattuKerros = 0;

void loop() 
{
  tilattuKerros = onkoTilattu();

  if (tilattuKerros > nykyinenKerros)
  {
    nykyinenKerros++;
  }
  else if (tilattu < nykyinenKerros)
  {
    nykyinenKerros--;
  }

  num(nykyinenKerros)
  delay(1000);
}



