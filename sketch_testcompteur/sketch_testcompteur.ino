/*
  Showing number 0-9 on a Common Anode 7-segment LED display
  Displays the numbers 0-9 on the display, with one second inbetween.
    A
   ---
F |   | B
  | G |
   ---
E |   | C
  |   |
   ---
    D
  This example code is in the public domain.
 */
 
// Pin 2-8 is connected  to the 7 segments of the display.

int pinA = 42;
int pinB = 43;
int pinC  = 44;
int pinD = 45;
int pinE = 46;
int pinF = 47;
int pinG = 48;
int  D1 = 49;
int D2 = 50;
int D3 = 51;
int D4 = 52;

// the setup routine  runs once when you press reset:
void setup() {                
  // initialize  the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB,  OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG,  OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3,  OUTPUT);  
  pinMode(D4, OUTPUT);  
}

// the loop routine runs over  and over again forever:
void loop() {
  digitalWrite(pinE, HIGH);
              // wait for a second
  
}
