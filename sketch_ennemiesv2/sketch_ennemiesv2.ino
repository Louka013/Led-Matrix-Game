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
  
  //paramètres du premier point pour chaque début de partie
  columnStart = 4;
  rowstate = 0;
  columnState = 4;
  rowState = 0;

}

void loop() {
  updateeEnemies();

}

void updateeEnemies() {

  
}
