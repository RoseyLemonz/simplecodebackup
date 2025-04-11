void setup() 
{
  Serial.begin(9600);
}


uint16_t adc_val = 0;
float temp = 0;
float tmp = 0;


void loop() 
{
    adc_val = analogRead(A0);
    temp = map(adc_val, 786, 349, 0, 400) / 10.0;
    tmp = round(temp * 2) / 2.0;

    Serial.print(adc_val);
    Serial.print(" -> ");
    Serial.print(temp, 1);
    Serial.print(" C");
    Serial.print(" - ");
    Serial.print(tmp, 1);
    Serial.println(" C");

    delay(500);

}
