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


void loop() 
{
  for (uint8_t i=0; i<3; i++)
  {  
    num(i); 
    delay(500);
  }  
}



