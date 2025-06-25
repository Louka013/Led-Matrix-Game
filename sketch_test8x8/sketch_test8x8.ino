///We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,11,10,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime=250;

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}




void loop() { 
  for (int i=0; i<8; i++) {
  lc.setRow(0,i,143);
  delay(500);
  
  }

  for (int i=0; i<8; i++) {
  lc.setRow(0,i,159);
  delay(500);
  
  }

  for (int i=0; i<8; i++) {
  lc.setRow(0,i,207);
  delay(500);
  
  }

  for (int i=0; i<8; i++) {
  lc.setRow(0,i,0);
  delay(500);
  
  }

  for (int i=0; i<8; i++) {
  lc.setChar(0,0,0,true);
  delay(100);
  lc.setChar(0,0,0,false);
  delay(100);

  }
/*  for(int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      lc.setLed(0,j,i,true);
      delay(10);
      lc.setLed(0,i,0,true);
      delay(10);
    }
    
  }
  for(int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      lc.setLed(0,j,i,false);
      delay(10);
      lc.setLed(0,i,0,false);
      delay(10);
    }
    
  }*/

  
  
  
}  
