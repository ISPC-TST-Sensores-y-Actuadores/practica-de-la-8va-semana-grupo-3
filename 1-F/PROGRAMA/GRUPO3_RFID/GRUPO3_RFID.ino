// SENSORES Y ACTUADORES - GRUPO 3 - RFID

// DEFINO EL TIPO DE VARIABLES A UTILIZAR EN EL PROGRAMA
String id; // variable donde almaceno la clave asignada a mi tarjeta rfid
// funcion para configurar 
void setup()
{// inicializo la comunicacion serie 
  Serial.begin(9600);
  // pin 13 como salida donde conecto el LED verde que indica el estado de valdiacion de la tarjeta rfid
  pinMode(13, OUTPUT);
  // imprimo mensaje por el monitor serie
  Serial.println("TARJETA  RFID LISTA PARA ESCANEAR");
  // inicializo con el LEd apagado
  digitalWrite(13, LOW);
}
// funcion bucle que se repite
void loop()
{
// mientras no ingrese caracter espero
  while (!Serial.available())
  {
  }
  // almaceno en la variable c cada caracter ingresado por el monito serie
  id = Serial.readString(); // leo el monitor serie la clave asociada a mi tarjeta
   // imprimo el valor asociado de la clave
  Serial.print(id);// 
// comparo el valor asociado de la tarjeta con la clave ingresada por monitor serie

  if (id == "GRUPO3") // condicional de verificacion de igualdad
  {
    Serial.println(" TARJETA VALIDADA");// se verifica imprimo mensaje
    digitalWrite(13, HIGH);// enciendo led
    delay(1000);// espero 1 segundo
  }
  else
  {

    Serial.println(" TARJETA INVALIDA");// no se cumple la igualdad tarjeta invalida
    digitalWrite(13, LOW);// apago led
    delay(1000);// espero 1 segundo
  }

  id = "";// borro el contenido de id
  delay(500);// tiempo de espera de medio segundo
}
