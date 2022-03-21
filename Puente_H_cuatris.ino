#define MotA 10
#define MotB 11
#define aux 9
#define Pot A0
int val=0;
int potencia=0;
int incremento=1;
float voltage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
}

void loop() {
  //potencia = potencia + incremento;
  //Serial.println(potencia);
  //if(potencia<=0 or potencia >=255){
    //incremento=-incremento;
  //}
  //Leemos el voltaje que esta recibiendo por parte del potenciometro
  val= analogRead(Pot);
  //Hacemos la conversion
  voltage = val*(5.0/1023.0);
  //Condicionamos para que solo encienda si es igual o mayor que 3V
  //Serial.println(voltage);
  if(voltage<2 ){
    potencia = map(val,0,408,255,40);
    Levogiro();
  } else if(voltage >2 and voltage<3){
    potencia = 0;
    Detenido();
  } else {
    potencia = map(val,612,1023,40,255);
    Dextrogiro();
  }
  delay(100);
}

//Funcion Levogiro
void Levogiro (){
  analogWrite(aux,potencia);
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, LOW);
  Serial.print("Levogiro ");
  Serial.print(voltage);
  Serial.print("  ");
  Serial.println(potencia);
}

void Dextrogiro (){
  analogWrite(aux,potencia);
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
  Serial.print("Dextrogiro ");
  Serial.print(voltage);
  Serial.print("  ");
  Serial.println(potencia);
}

void Detenido (){
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, LOW);
  Serial.print("Freno pasivo ");
  Serial.print(voltage);
  Serial.print("  ");
  Serial.println(potencia);
}
