#include <Servo.h>

//INICIALIZANDO VARIABLES//
Servo s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s_c,s_c2,s_c3;
int v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12;
int x,y;

//SETUP//
void setup() {

}
//LOOP PRINCIPAL//
void loop() {

while(1){
  posicion_inicial_lado1();
  delay(1000);
  posicion_1();
  delay(1000);
  posicion_2();
  delay(1000);
}


}

void posicion_2(){
  //SE MUEVE LAS PATAS 1 y 3//
    //ATACH//
    //LEVANTAMOS//
    s5.attach(7);
    s2.attach(4);
    s5.write(120);
    s2.write(130);
    delay(300);
    s2.detach();
    s5.detach();
    ///////////////
    s1.attach(3);
    s6.attach(8);
    s1.write(100);
    s6.write(120);
    delay(300);  
    s1.detach();
    s6.detach();
    /////////////
    s5.attach(7);
    s2.attach(4);
    s5.write(80);
    s2.write(90);
    delay(300);
    s2.detach();
    s5.detach();
    ///////////////
    s1.attach(3);
    s6.attach(8);
    s1.write(30);
    s6.write(40);
    delay(300);  
    s1.detach();
    s6.detach();
  }
void posicion_1(){
  // SE MUEVE LA PATA 2//
  //PATA 2//
      // ATACH //
      s3.attach(5);
      s4.attach(6);
      //LEVANTAMOS //
      s4.write(170);
      delay(75);
      //AL FRENTE //
      s3.write(70);
      delay(75);
      //ABAJO//
      s4.write(120);
      delay(75);
      //REGRESA//
      s3.write(50);
      delay(75);
      /////////////
      delay(800);
      s3.detach();
      s4.detach();
  }
void posicion_inicial_lado2(){
    while(y<1){

    }
  }
  
void posicion_inicial_lado1(){
  while(x<1){
      //POSICION INICIAL//
      //PATA COMUN//
      s_c.attach(2);
      s_c2.attach(9);
      s_c2.write(180);
      s_c.write(170);
      delay(800);
      s_c.detach();
      s_c2.detach();
      //PATA 1//
      s1.attach(3);
      s2.attach(4);
      //ESCRITURA//
      s1.write(90);
      s2.write(90);
      delay(800);
      s1.detach();
      s2.detach();
      //PATA 2//
      s3.attach(5);
      s4.attach(6);
      s3.write(50);
      s4.write(120);
      delay(800);
      s3.detach();
      s4.detach();
      //PATA 3//
      s5.attach(7);
      s6.attach(8);
      s5.write(75);
      s6.write(90);
      delay(800);
      s5.detach();
      s6.detach();
      x=1;
    }  
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

  
