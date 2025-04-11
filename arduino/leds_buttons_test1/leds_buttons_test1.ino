#include "LedsButtons.h"

void loop() 
{
  uint8_t nappi = readButtons();

  if (nappi = S1)
  {
    setLeds(0x55);
  }    
  if (nappi = S2)
  {
    setLeds(0xAA);
  }

}
