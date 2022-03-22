// Definimos las variables de los puertos
// que utlizaremos.
#define MotA 10
#define MotB 11
#define Pot A0

// Variable auxiliar
int val=0;

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
  float voltage = val*(5.0/1023.0);
  
  // Si el voltaje es < 2 usamos la función
  // Levogiro
  Serial.println(voltage);
  if(voltage<2 ){
    Levogiro();
    
  // Si esta entre 2 y 3, Freno Pasivo
  } else if(voltage >2 and voltage<3){
    Detenido();
  } else {
    
  // Por último, > 3, Dextrogiro
    Dextrogiro();
  }
}

//Función Levogiro
void Levogiro (){
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, LOW);
  Serial.println("Levogiro");
}

//Función Dextrogiro
void Dextrogiro (){
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
  Serial.println("Dextrogiro");
}

//Función Frenos Pasivo
void Detenido (){
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, LOW);
  Serial.println("Freno pasivo");
}
