#include <Servo.h>
const int servo2 = 9;
const int servo3 = 10;
const int servo4 = 11;
const int servo5 = 12;


const int joyH1 = A0;
const int joyV1 = A1;
const int joyH2 = A2;
const int joyV2 = A3;
int posX = 90;

int servoVal;
int indice = 0;
const int cantidadPruebas = 10;

int joyH1List[cantidadPruebas] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int joyV1List[cantidadPruebas] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int joyH2List[cantidadPruebas] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int joyV2List[cantidadPruebas] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;


void setup() {
  myservo2.attach(servo2);
  myservo3.attach(servo3);
  myservo4.attach(servo4);
  myservo5.attach(servo5);

  Serial.begin(9600);
  myservo2.write(posX);
  initArray();

}

void loop() {

  /*servoVal = analogRead(joyH1);
    servoVal = map(servoVal,0,1023,180,0);
    myservo2.write(servoVal);

    servoVal = analogRead(joyV1);
    servoVal = map(servoVal,0,1023,50,120);
    myservo3.write(servoVal);

    servoVal2 = analogRead(joyH2);
    servoVal2 = map(servoVal2,0,1023,180,0);
    myservo5.write(servoVal2);

    servoVal2 = analogRead(joyV2);
    servoVal2 = map(servoVal2,0,1023,50,120);
    myservo4.write(servoVal2);*/

  updateArray();
  updateServos();
  delay(5);
  Serial.println(servoVal);

}


void initArray() {
  for (int i = 0; i < cantidadPruebas; i++) {
    joyH1List[i] = analogRead(joyH1);
    joyV1List[i] = analogRead(joyV1);
    joyH2List[i] = analogRead(joyH2);
    joyV2List[i] = analogRead(joyV2);
    delay(10);
  }
}

void updateArray() {
  joyH1List[indice] = analogRead(joyH1);
  joyV1List[indice] = analogRead(joyV1);
  joyH2List[indice] = analogRead(joyH2);
  joyV2List[indice] = analogRead(joyV2);
  indice++;
  if (indice == cantidadPruebas) indice = 0;
}


int promedio(int lista[]) {
  int resultado = 0;
  for (int i = 0; i < cantidadPruebas; i++) {
    resultado = resultado + lista[i];
  }
  resultado = resultado / cantidadPruebas;
  return resultado;
}

void updateServos() {
  servoVal = map(promedio(joyH1List), 0, 1023, 180, 0);
  Serial.print("Servo1: ");
  Serial.print(servoVal);
  Serial.print("\t  ");
  myservo2.write(servoVal);

  servoVal = map(promedio(joyV1List), 0, 1023, 50, 120);
  Serial.print("Servo2: ");
  Serial.print(servoVal);
  Serial.print("\t  ");
  myservo3.write(servoVal);

  servoVal = map(promedio(joyV2List), 0, 1023, 50, 120);
  Serial.print("Servo3: ");
  Serial.print(servoVal);
  Serial.print("\t  ");
  myservo4.write(servoVal);

  servoVal = map(promedio(joyH2List), 0, 1023, 180, 0);
  Serial.print("Servo4: ");
  Serial.print(servoVal);
  Serial.print("\t  ");
  myservo5.write(servoVal);
}

