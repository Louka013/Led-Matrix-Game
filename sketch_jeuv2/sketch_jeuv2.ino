#include "LedControl.h"

/*
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 */
LedControl lc=LedControl(12,11,10,1);

unsigned long delaytime=100;

//paramètre d'apparition des ennemis
int rowColumn;
int startingLine;
int startingPositionInLine;

//joystick output
#define xAxe  A2
#define yAxe  A3
#define button A4

//Player position
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
  randomSeed(analogRead(0));

  pinMode(xAxe, INPUT);
  pinMode(yAxe, INPUT);
  pinMode(button, INPUT_PULLUP);

  
}



void loop() {

  player();
  rowColumn = random(0,2);
  startingLine = random(0,2);
  startingPositionInLine = random(0,8);

  if (rowColumn == 0){
    if (startingLine == 0) {
      
      for (int i=0; i<8; i++) {
        
        lc.setLed(0, i, startingPositionInLine, true);
        delay(delaytime);
        lc.setLed(0, i, startingPositionInLine, false);
        player();

        if (xPosition == i & yPosition == startingPositionInLine) {
          while (1==1) {
            loose();
          }
        }
      }
    }
    else {
      for (int i=7; i>=0; i--) {
        
        lc.setLed(0, i, startingPositionInLine, true);
        delay(delaytime);
        lc.setLed(0, i, startingPositionInLine, false);
        player();

        if (xPosition == i & yPosition == startingPositionInLine) {
          while (1==1) {
            loose();
          }
        }
      }

  else {
    if (startingLine == 0) {
    
    
      for (int i=0; i<8; i++) {
        
        lc.setLed(0, startingPositionInLine, i, true);
        delay(delaytime);
        lc.setLed(0, startingPositionInLine, i, false);
        player();

        if (xPosition == startingPositionInLine & yPosition == i) {
          while (1==1) {
            loose();
          }

        }
    else {
      for (int i=7; i>=0; i--) {
        
        lc.setLed(0, startingPositionInLine, i, true);
        delay(delaytime);
        lc.setLed(0, startingPositionInLine, i, false);
        player();

        if (xPosition == startingPositionInLine & yPosition == i) {
          while (1==1) {
            loose();
          }

        }
      }
    }
  }


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

  delay(300);
  lc.setRow(0,0,L[0]);
  lc.setRow(0,1,L[1]);
  lc.setRow(0,2,L[2]);
  lc.setRow(0,3,L[3]);
  lc.setRow(0,4,L[4]);
  delay(300);
  lc.clearDisplay(0);
  delay(150);
  lc.setRow(0,0,O[0]);
  lc.setRow(0,1,O[1]);
  lc.setRow(0,2,O[2]);
  lc.setRow(0,3,O[3]);
  lc.setRow(0,4,O[4]);
  delay(300);
  lc.clearDisplay(0);
  delay(150);
  lc.setRow(0,0,O[0]);
  lc.setRow(0,1,O[1]);
  lc.setRow(0,2,O[2]);
  lc.setRow(0,3,O[3]);
  lc.setRow(0,4,O[4]);
  delay(300);
  lc.clearDisplay(0);
  delay(150);
  lc.setRow(0,0,S[0]);
  lc.setRow(0,1,S[1]);
  lc.setRow(0,2,S[2]);
  lc.setRow(0,3,S[3]);
  lc.setRow(0,4,S[4]);
  delay(300);
  lc.clearDisplay(0);
  delay(150);
  lc.setRow(0,0,E[0]);
  lc.setRow(0,1,E[1]);
  lc.setRow(0,2,E[2]);
  lc.setRow(0,3,E[3]);
  lc.setRow(0,4,E[4]);
  
}


while (digitalRead(button)==0){
            loose()
          }
          loop()
