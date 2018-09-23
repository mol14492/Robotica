#include <Servo.h>
#include <barrido.h>

Servo servo;
Servo servo1;
Servo servo2;
int antiguo;
int antiguo2;
int nuevo;
int nuevo2;
int valor;
int valor2;
int indicador=13;


void setup() {
  //Se inicia la comunicacion con el puerto serial. BR=9600//
  Serial.begin(9600);  
  //Puertos de Salida//
  pinMode(indicador, OUTPUT); //El puerto 13 sera un indicador. 
  // ROBOT EN POSICION INICIAL// 
  pos_init_1();
}

void loop() {
  delay(1000);
  barrido(130,4);
  barrido(90,4);
  delay(1000);
  barrido(170,6);
  barrido(120,6);
  delay(1000);
  barrido(120,7);
  barrido(80,7);


}


/*
 * FUNCION pos_1()
 * 
 * Esta funcion mueve la pata 2 del robot. No tiene argumentos de entrda.
 * 
*/
void pos_1(){
  barrido(170,6);
  barrido(120,6);
  }
/*
 * FUNCION pos_2()
 * 
 * Esta funcion mueve la pata 2 del robot. No tiene argumentos de entrda.
 * 
*/
void pos_2(){

  }

/*
 *  FUNCION: pos_init_1()
 *  
 *  Esta funcion coloca todas las patas del lado 1 en su posicion inicial. 
 *  No tiene argumentos de entrada. 
 *  
*/
void pos_init_1(){
    //Se coloca el robot en posicion inicial.//
    //Indicador de SETUP//
    digitalWrite(indicador,HIGH);
    //POSICION INICIAL//
    //PATA COMUN//
    servo1.attach(2);
    servo1.write(170);
    delay(800);
    //PATA 1//
    servo1.attach(3);
    servo2.attach(4);
    //ESCRITURA//
    servo1.write(90);
    servo2.write(90);
    delay(800);
    servo1.detach();
    servo2.detach();
    //PATA 2//
    servo1.attach(5);
    servo2.attach(6);
    servo1.write(50);
    servo2.write(120);
    delay(800);
    servo1.detach();
    servo2.detach();
    //PATA 3//
    servo1.attach(7);
    servo2.attach(8);
    servo1.write(75);
    servo2.write(90);
    delay(800);
    servo1.detach();
    servo2.detach();
    //Senal de que esta listo//
    delay(300);
    digitalWrite(indicador,LOW);
    delay(300);
    digitalWrite(indicador,HIGH);
    delay(300);
    digitalWrite(indicador,LOW);
    delay(300);
    digitalWrite(indicador,HIGH);
    delay(400);
    digitalWrite(indicador,LOW);
  }





/*
 *  FUNCION: barrido(angulo,pin)
 * 
 *  Esta funcion hace un barrido del angulo actual al angulo deseado 
 *  para que el servo se mueva mas fluido. 
 *
 *  Como argumento se tiene el angulo al que se desea llegar y el pin 
 * .en donde esta conectado el servo.
*/

void barrido (int angulo, int pin ){
    //Se hace reset de las variables//
    nuevo=0;
    antiguo=0;
    valor=0;
    // Se conecta el servo al pin. //
    servo.attach(pin);
    Serial.println("- Se conecto el servo al pin: " + String(pin));
    //Se obtiene el valor del angulo anterior//
    antiguo=servo.read();
    Serial.println("- El servo tiene el angulo:"+ String(antiguo));
    //Se hace la conversion para el barrido.//
    valor=(angulo-antiguo)/20;  // Se fracciona en x partes el valor.
    //Se hace el barrido//
    for(int i=0;i<=30;i++){
      nuevo=antiguo+(valor);    //El nuevo valor es la suma entre el valor antiguo y el fraccionado.
      Serial.println("- El nuevo valor es: "+String(nuevo));  
      servo.write(nuevo);     //Se escribe el valor en el servo.
      antiguo=nuevo;
      delay(5);
    }
  servo.write(angulo);   //Se escribe en el servo el valor final.
  servo.detach();        //Desconectamos el servo del pin.
  delay(10);
  }




  /*
 *  FUNCION: barrido2(angulo,pin)
 * 
 *  Esta funcion hace un barrido del angulo actual al angulo deseado 
 *  para que el servo se mueva mas fluido. 
 *
 *  Como argumento se tiene el angulo al que se desea llegar y el pin 
 * .en donde esta conectado el servo.
*/
/*
void barrido2 (int angulo, int angulo2,int pin, int pin2 ){
    //Se hace reset de las variables//
    antiguo=0;
    nuevo=0;
    valor=0;
    antiguo2=0;
    nuevo2=0;
    valor2=0;
    // Se conecta el servo al pin. //
    servo.attach(pin);
    servo1.attach(pin2);
    Serial.println("- Se conecto el servo al pin: " + String(pin));
    Serial.println("- Se conecto el servo 2 al pin: " + String(pin2));
    //Se obtiene el valor del angulo anterior//
    antiguo=servo.read();
    antiguo2=servo1.read();
    Serial.println("- El servo tiene el angulo:"+ String(antiguo));
    Serial.println("- El servo 2 tiene el angulo:"+ String(antiguo2));
    //Se hace la conversion para el barrido.//
    valor=(angulo-antiguo)/20;  // Se fracciona en x partes el valor.
    valor2=(angulo2-antiguo2)/20;
    //Se hace el barrido//
    for(int i=0;i<30;i++){
      nuevo=antiguo+valor;    //El nuevo valor es la suma entre el valor antiguo y el fraccionado.
      nuevo2=antiguo2+valor2;
      Serial.println("- El nuevo valor es: "+String(nuevo));
      Serial.println("- El nuevo valor2 es: "+String(nuevo2));
      if(nuevo<180 && nuevo>0 && nuevo2<180 && nuevo2>0){
        servo.write(nuevo);     //Se escribe el valor en el servo.
        servo1.write(nuevo2);
        antiguo=nuevo;
        antiguo2=nuevo2;
        delay(5);
      }
  }
  servo.write(angulo);   //Se escribe en el servo el valor final.
  servo1.write(angulo2);
  servo.detach();        //Desconectamos el servo del pin.
  servo1.detach();
  delay(10);
  }
*/
