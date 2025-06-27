#include "LedControl.h"

/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 */
LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=75;

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

//joystick output
#define xAxe  A2
#define yAxe  A3
#define button 2


//Player position
int xPosition = 3;
int yPosition = 3;

void setup() {
  //pour restart
  delay(delaytime);
  //Player position
  xPosition = 3;
  yPosition = 3;
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
  randomSeed(analogRead(0));

  pinMode(xAxe, INPUT);
  pinMode(yAxe, INPUT);
  pinMode(button, INPUT_PULLUP);

  //paramètres du premier point ennemie pour chaque début de partie
  columnStart = 4;
  rowStart = 0;
  columnState = 4;
  rowState = 0;

  
}



void loop() {
  collision();
  updateEnemies();
  player();
  
}

void player() {

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

void loose() {

  byte L[5]={ B11111111,B00000001,B00000001,B00000001,B00000001  };
  byte O[5]={ B01111110,B10000001,B10000001,B10000001,B01111110  };
  byte S[5]={ B00110001,B01001001,B01001001,B01001001,B01000110  };
  byte E[5]={ B11111110,B10010010,B10010010,B10010010,B00000000  };

  //lettre L
  lc.setColumn(0,2,255);
  lc.setColumn(0,3,1);
  lc.setColumn(0,4,1);
  lc.setColumn(0,5,1);
  lc.setColumn(0,6,1);
  delay(300);
  lc.clearDisplay(0);
  delay(150);

  //lettre O
  lc.setColumn(0,2,126);
  lc.setColumn(0,3,129);
  lc.setColumn(0,4,129);
  lc.setColumn(0,5,129);
  lc.setColumn(0,6,126);
  delay(300);
  lc.clearDisplay(0);
  delay(150);

  //lettre O
  lc.setColumn(0,2,126);
  lc.setColumn(0,3,129);
  lc.setColumn(0,4,129);
  lc.setColumn(0,5,129);
  lc.setColumn(0,6,126);
  delay(300);
  lc.clearDisplay(0);
  delay(150);

  //lettre S
  lc.setColumn(0,2,49);
  lc.setColumn(0,3,73);
  lc.setColumn(0,4,73);
  lc.setColumn(0,5,73);
  lc.setColumn(0,6,70);
  delay(300);
  lc.clearDisplay(0);
  delay(150);

  //lettre E
  lc.setColumn(0,2,255);
  lc.setColumn(0,3,137);
  lc.setColumn(0,4,137);
  lc.setColumn(0,5,137);
  lc.setColumn(0,6,137);
  delay(300);
  lc.clearDisplay(0);
  delay(500);
  
}

void updateEnemies() {

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


void collision() {
  attachInterrupt(digitalPinToInterrupt(2), buttonPressed, FALLING);
  while ((xPosition == rowState) & (yPosition == columnState)) {
    loose();
 }
}

void buttonPressed() {
  setup();
}
