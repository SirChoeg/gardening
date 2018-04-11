#define IND_OP 13
#define SEN_IN 2
void setup() {
   pinMode(IND_OP, OUTPUT);
  pinMode(SEN_IN, INPUT);
}
void loop() {
  if(digitalRead(SEN_IN) == HIGH){
    digitalWrite(IND_OP, HIGH);
  } else {
    digitalWrite(IND_OP, LOW);
    delay(1000);
  }
}
