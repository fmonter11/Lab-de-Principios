#define MotA 10
#define MotB 11

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, LOW);
  Serial.println("Levogiro");
  delay(1000);

  digitalWrite(MotA, LOW);
  digitalWrite(MotB, LOW);
  Serial.println("Freno pasivo");
  delay(1000);

  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
  Serial.println("Dextrogiro");
  delay(1000);

  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, HIGH);
  Serial.println("Freno activo");
  delay(1000);
  
}
