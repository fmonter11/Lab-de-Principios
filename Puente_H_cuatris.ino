
// Definimos las variables de los puertos
// que utlizaremos.
#define MotA 10
#define MotB 11
#define aux 9
#define Pot A0

// Variables auxiliares
int val=0;
int potencia=0;
int incremento=1;
float voltage;

void setup() {
  // Inicializamos la comunicación serial
  // y los puertos en modo salida
  Serial.begin(9600);
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
}

void loop() {
  // Leemos el voltaje que esta recibiendo por
  // parte del potenciometro
  val= analogRead(Pot);
  
  //Hacemos la conversion a volts.
  voltage = val*(5.0/1023.0);
  
  // Si el voltaje es < 2 usamos la función
  // Levogiro
  if(voltage<2 ){
    potencia = map(val,0,408,255,40);
    Levogiro();
    
  // Si esta entre 2 y 3, Freno Pasivo
  } else if(voltage >2 and voltage<3){
    potencia = 0;
    Detenido();
  } else {
    
  // Por último, > 3, Dextrogiro
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

//Función Dextrogiro
void Dextrogiro (){
  analogWrite(aux,potencia);
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
  Serial.print("Dextrogiro ");
  Serial.print(voltage);
  Serial.print("  ");
  Serial.println(potencia);
}

//Función Frenos Pasivo
void Detenido (){
  analogWrite(aux,0);
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, LOW);
  Serial.print("Freno pasivo ");
  Serial.print(voltage);
  Serial.print("  ");
  Serial.println(potencia);
}
