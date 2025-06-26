#include "LedControl.h"

/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 */
LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=100;

/*création d'une liste de paramètres d'un point, grace aux 
quelles on pourra mettre à jour le déplacement du point*/
int columnState;
int rowState;
int columnStart;
int rowStart;
int pointParameters[4]={columnStart, rowStart, columnState, rowState};




int rowColumn;
int startingLine;
int startingPositionInLine;

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

  randomSeed(analogRead(0));

}

void loop() {

  rowColumn = random(0,2);
  startingLine = random(0,2);
  startingPositionInLine = random(0,8);

  if (rowColumn == 0){
    if (startingLine == 0) {
      
      for (int i=0; i<8; i++) {
        
        lc.setLed(0, i, startingPositionInLine, true);
        delay(delaytime);
        lc.setLed(0, i, startingPositionInLine, false);
      }
    }
    else {
      for (int i=7; i>=0; i--) {
        
        lc.setLed(0, i, startingPositionInLine, true);
        delay(delaytime);
        lc.setLed(0, i, startingPositionInLine, false);
      }
    }
  }

  else {
    if (startingLine == 0) {
    
    
      for (int i=0; i<8; i++) {
        
        lc.setLed(0, startingPositionInLine, i, true);
        delay(delaytime);
        lc.setLed(0, startingPositionInLine, i, false);
      }

  }
    else {
      for (int i=7; i>=0; i--) {
        
        lc.setLed(0, startingPositionInLine, i, true);
        delay(delaytime);
        lc.setLed(0, startingPositionInLine, i, false);
      }
    }
  }
  
}

void updateeEnemies() {
  
}
