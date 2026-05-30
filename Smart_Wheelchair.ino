#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1); // RX, TX
String readvoice = "";
void setup() {
  pinMode(10, OUTPUT); // IN1
  pinMode(11, OUTPUT); // IN2
  pinMode(12, OUTPUT); // IN3
  pinMode(13, OUTPUT); // IN4
  Serial.begin(9600);
  BT.begin(9600);
}
void smartControl(String cmd) {
  cmd.toLowerCase(); // normalize
  if (cmd.indexOf("forward") >= 0 || cmd.indexOf("go") >= 0) {
    digitalWrite(10, HIGH); digitalWrite(11, LOW);
    digitalWrite(12, HIGH); digitalWrite(13, LOW);
  }
  else if (cmd.indexOf("back") >= 0) {
    digitalWrite(10, LOW); digitalWrite(11, HIGH);
    digitalWrite(12, LOW); digitalWrite(13, HIGH);
  }
  else if (cmd.indexOf("left") >= 0) {
    digitalWrite(10, LOW); digitalWrite(11, HIGH);
    digitalWrite(12, HIGH); digitalWrite(13, LOW);
  }
  else if (cmd.indexOf("right") >= 0) {
    digitalWrite(10, HIGH); digitalWrite(11, LOW);
    digitalWrite(12, LOW); digitalWrite(13, HIGH);
  }
  else if (cmd.indexOf("stop") >= 0 || cmd.indexOf("halt") >= 0) {
    digitalWrite(10, LOW); digitalWrite(11, LOW);
    digitalWrite(12, LOW); digitalWrite(13, LOW);
  }
}
void loop() {
  if (BT.available()) {
    readvoice = BT.readString();
    readvoice.trim();
    Serial.println("Heard: " + readvoice);
    smartControl(readvoice); // pass command to AI logic
    delay(200);
 }
