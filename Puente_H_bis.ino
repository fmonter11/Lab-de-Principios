#define MotA 10
#define MotB 11
#define Pot A0
int val=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
}

void loop() {
  //Leemos el voltaje que esta recibiendo por parte del potenciometro
  val= analogRead(Pot);
  //Hacemos la conversion
  float voltage = val*(5.0/1023.0);
  //Condicionamos para que solo encienda si es igual o mayor que 3V
  Serial.println(voltage);
  if(voltage<2 ){
    Levogiro();
  } else if(voltage >2 and voltage<3){
    Detenido();
  } else {
    Dextrogiro();
  }
}

//Funcion Levogiro
void Levogiro (){
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, LOW);
  Serial.println("Levogiro");
}

void Dextrogiro (){
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
  Serial.println("Dextrogiro");
}

void Detenido (){
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, LOW);
  Serial.println("Freno pasivo");
}
