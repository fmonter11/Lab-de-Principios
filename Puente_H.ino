// Definimos las variables de los puertos
// que utlizaremos.
#define MotA 10
#define MotB 11

void setup() {
  // Inicializamos la comunicación serial
  // y los puertos en modo salida
  Serial.begin(9600);
  pinMode(MotA, OUTPUT);
  pinMode(MotB, OUTPUT);
}

void loop() {
  // Declaramos los diferentes estados
  // y damos un delay de 1 segundo entre
  // cada uno de ellos.
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
