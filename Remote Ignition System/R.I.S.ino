int v = 0;
#define TONE A0
#define RED A5
#define GREEN A4
#define BLUE A3
#define RELAY 3
void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY,OUTPUT);
  pinMode(TONE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  analogWrite(BLUE, 255);
  analogWrite(GREEN, 255);
 Serial.begin(9600);
 delay(2500);
}

void loop() {
  analogWrite(BLUE, 0);
  if(Serial.available()){
  v = Serial.parseInt();
  if(v > 0){
  tone(TONE, 360, 300);
  if(v != 0){
    while(v > 0){
      delay(1000);
      v = v - 1;
      if(v < 12 && v > 0){
        tone(TONE, 680, 200);
      }
      if(v == 0){
        tone(TONE, 5600, 800);
      }
      
    }
  }
  analogWrite(GREEN, 0);
  digitalWrite(BLUE, 255);
  digitalWrite(RELAY, HIGH);
  Serial.end();
  delay(30000);
  digitalWrite(RELAY, LOW);
  }
  }
}
