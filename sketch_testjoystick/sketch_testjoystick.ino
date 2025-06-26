#define xAxe  A2
#define yAxe  A3
#define button 2
void setup() {
  Serial.begin(9600);
  pinMode(xAxe, INPUT);
  pinMode(yAxe, INPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  Serial.print("button state : ");
  Serial.println(digitalRead(button));
  delay(500);
}
