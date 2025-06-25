#include "LedControl.h"

/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 */
LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=100;

#define xAxe  A2
#define yAxe  A3
#define button A4

int xPosition = 4;
int yPosition = 4;

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
  
  Serial.begin(9600);
  pinMode(xAxe, INPUT);
  pinMode(yAxe, INPUT);
  pinMode(button, INPUT_PULLUP);

  
}

void loop() {
  lc.setLed(0, xPosition, yPosition, true);
  
  if (analogRead(xAxe) > 1000) {
    
    if (xPosition == 7) {
      xPosition = 0 ;
      delay(delaytime);
      lc.setLed(0, 7, yPosition, false);
    }
   else { 
    xPosition = xPosition + 1 ;
    delay(delaytime);
    lc.setLed(0, xPosition - 1, yPosition, false);
   }
  }

  if (analogRead(xAxe) < 100) {
    
    if (xPosition == 0) {
      xPosition = 7 ;
      delay(delaytime);
      lc.setLed(0, 0, yPosition, false);
    }
   else { 
    xPosition = xPosition - 1 ;
    delay(delaytime);
    lc.setLed(0, xPosition + 1, yPosition, false);
   }
  }

 
  if (analogRead(yAxe) > 1000) {
    
    if (yPosition == 0) {
      yPosition = 7 ;
      delay(delaytime);
      lc.setLed(0, xPosition, 0, false);
    }
   else { 
    yPosition = yPosition - 1 ;
    delay(delaytime);
    lc.setLed(0, xPosition, yPosition + 1, false);
   }
  }

  
  if (analogRead(yAxe) < 100) {
    
    if (yPosition == 7) {
      yPosition = 0 ;
      delay(delaytime);
      lc.setLed(0, xPosition, 7, false);
    }
   else { 
    yPosition = yPosition + 1 ;
    delay(delaytime);
    lc.setLed(0, xPosition, yPosition - 1, false);
   }
  }
  
  Serial.print("axe x :");
  Serial.print(analogRead(xAxe));
  Serial.print(" axe y :");
  Serial.println(analogRead(yAxe));
  
}
