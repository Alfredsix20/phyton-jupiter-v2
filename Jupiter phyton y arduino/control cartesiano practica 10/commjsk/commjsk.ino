// Librería para la comunicación serial
#include <SoftwareSerial.h>

// Pines de conexión del joystick
const int pinX = A0;
const int pinY = A1;
const int pinButton = 2;

// Variables para almacenar la posición y estado del joystick
int xPos = 0;
int yPos = 0;
bool buttonState = false;

// Objeto de la clase SoftwareSerial para la comunicación serial
SoftwareSerial serial(10, 11); // RX, TX

void setup() {
  // Iniciar la comunicación serial con una velocidad de 9600 bps
  Serial.begin(9600);
  serial.begin(9600);

  // Configurar el pin del botón como entrada con resistencia de pull-up
  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {
  // Leer la posición del joystick en las coordenadas x e y
  xPos = analogRead(pinX);
  yPos = analogRead(pinY);

  // Leer el estado del botón
  buttonState = digitalRead(pinButton);

  // Enviar los datos como mensajes de texto a través del puerto serial
  serial.print("x=");
  serial.print(xPos);
  serial.print(",y=");
  serial.print(yPos);
  serial.print(",button=");
  serial.println(buttonState);

  // Esperar un breve período de tiempo antes de enviar el siguiente mensaje
  delay(100);
}
