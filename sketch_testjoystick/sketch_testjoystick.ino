#define xAxe  A2
#define yAxe  A3
#define button A4
void setup() {
  Serial.begin(9600);
  pinMode(xAxe, INPUT);
  pinMode(yAxe, INPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  Serial.print("axe x :");
  Serial.print(analogRead(xAxe));
  Serial.print(" axe y :");
  Serial.println(analogRead(yAxe));
  delay(500);
}
