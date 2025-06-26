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

//variable aléatoire pour recréer un nouveau point de départ
int rowOrColumn;
int startingPosition;
int highOrLow;

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
  rowStart = 0;
  columnState = 4;
  rowState = 0;

}

void loop() {
  updateeEnemies();

}

void updateeEnemies() {

  //On éteint la led qui était allumer avant d'allumer la suivante
  lc.setLed(0, rowState, columnState, false);
  
  //boucle while lorsque le point ne sort pas de la matrice
  if ((rowState != abs(rowStart-7)) & (columnState != abs(columnStart-7) )) {
    if (rowStart == 0) {
      rowState = rowState + 1;
    }
    if (rowStart == 7) {
      rowState --;
    }
    if (columnStart == 0) {
      columnState ++;
    }
    if (columnStart == 7) {
      columnState --;
    }
  }
  //lorsque l'on sort de la boucle (de la matrice) on recrée un nouveau point de départ
  else {
    //on génère aléatoirement les nouveaux paramètres
    rowOrColumn = random(0,2);
    highOrLow = random(0,2);
    startingPosition = random(0,8);

    if (rowOrColumn == 0) {
      columnState = startingPosition;
      if (highOrLow = 0) {
        rowState = 0;
      }
      else {
        rowState = 7;
      }
    }
    else {
      rowState = startingPosition;
      if (highOrLow = 0) {
        columnState = 0;
      }
      else {
        columnState = 7;
      }
    }

    //On redéfinie les nouveaux points de départ
    columnStart = columnState;
    rowStart = rowState;

  }

  //On allume la nouvelle led
  lc.setLed(0, rowState, columnState, true);
  delay(delaytime);
}
