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

void setup() {
  // Inicializamos la comunicación serial
  // y los puertos en modo salida
  Serial.begin(9600);
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
}

void loop() {
  // Enviamos al puerto auxiliar el valor
  // de potencia calculado.
  analogWrite(aux, potencia);
  Serial.println(potencia);
  
  // Calculamos la potencia para el siguiente ciclo.
  potencia = potencia + incremento;
  
  // Si el valor de la potencia sale del rango deseado
  // la ajustamos.
  if(potencia<=0 or potencia >=255){
    incremento=-incremento;
  }
  
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

//Funcion Levogiro
void Levogiro (){
  digitalWrite(MotA, HIGH);
  digitalWrite(MotB, LOW);
}

//Función Dextrogiro
void Dextrogiro (){
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, HIGH);
}

//Función Frenos Pasivo
void Detenido (){
  digitalWrite(MotA, LOW);
  digitalWrite(MotB, LOW);
}
