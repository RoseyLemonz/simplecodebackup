//*******************************************************************
//  Pohjatiedosto LEDs & Buttons Shield for Arduino kortille
//*******************************************************************

void setup() 
{
  pinMode(LD1, OUTPUT);   // määritellään kaikkien ledien 
  pinMode(LD2, OUTPUT);   // liitännät lähdöiksi
  pinMode(LD3, OUTPUT);
  pinMode(LD4, OUTPUT);
  pinMode(LD5, OUTPUT);
  pinMode(LD6, OUTPUT);
  pinMode(LD7, OUTPUT);
  pinMode(LD8, OUTPUT);

  pinMode(S1, INPUT_PULLUP);  // määritellään kaikkin painonappeihin
  pinMode(S2, INPUT_PULLUP);  // liitännät tuloksi
  pinMode(S3, INPUT_PULLUP);  // MUISTA PULLUP
  pinMode(S4, INPUT_PULLUP);

  Serial.begin(9600);         // alustetaan sarjaliikenne tulostusta varten
                              // debuggausta varten 
}


//***********************************************************
//  setLeds
//***********************************************************
void setLeds(uint8_t ledStates)
{
  if (ledStates & 0x80) digitalWrite(LD1, HIGH); else digitalWrite(LD1, LOW);
  if (ledStates & 0x40) digitalWrite(LD2, HIGH); else digitalWrite(LD2, LOW);
  if (ledStates & 0x20) digitalWrite(LD3, HIGH); else digitalWrite(LD3, LOW);
  if (ledStates & 0x10) digitalWrite(LD4, HIGH); else digitalWrite(LD4, LOW);
  if (ledStates & 0x08) digitalWrite(LD5, HIGH); else digitalWrite(LD5, LOW);
  if (ledStates & 0x04) digitalWrite(LD6, HIGH); else digitalWrite(LD6, LOW);
  if (ledStates & 0x02) digitalWrite(LD7, HIGH); else digitalWrite(LD7, LOW);
  if (ledStates & 0x01) digitalWrite(LD8, HIGH); else digitalWrite(LD8, LOW);
}

/*
 *  Funktio palauttaa näppäimen vakion S1, S2, S3, tai S4, jos
 *  näppäintä on painettu. Jos näppäimintä ei ole painettu,
 *  palautetaan 0
 */
uint8_t readButtons()
{
  if (digitalRead(S1) == LOW)         // onko painettu S1?
    return S1;

  else if (digitalRead(S2) == LOW)    // onko painettu S2?
    return S2;

  else if (digitalRead(S3) == LOW)    // onko painettu S3?
    return S3;

  else if (digitalRead(S4) == LOW)    // onko painettu S4?
    return S4;

  else
   return 0;
}














