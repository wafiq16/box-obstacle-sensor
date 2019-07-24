int led = 2; //d2
int ir = 3; //d3

#include <DFPlayer_Mini_Mp3.h> //memanggil library DFPlayer mini
#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 5); // Declare pin RX & TX
int duit = HIGH;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
  pinMode(ir, INPUT);
  Serial.begin(9600);

  mySerial.begin (9600);

  mp3_set_serial (mySerial); //set softwareSerial for DFPlayer
  delay(10);

  mp3_reset();  //soft-Reset module DFPlayer

  delay(10);   //wait 1ms for respon command

  mp3_set_volume(100); //set Volume module DFPlayer
  delay(1);
}

// the loop function runs over and over again forever
void loop() {
  duit = digitalRead(ir);
  if (duit == LOW) {
    digitalWrite(led, HIGH);
    Serial.println("kenek ye");
    mp3_play();
  }
  else if (duit == HIGH) {
    digitalWrite(led, LOW);
    Serial.println("rakenek jo");
    mp3_stop();
  }
  delay(100);
}
