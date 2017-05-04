#include <SoftwareSerial.h>

SoftwareSerial lora(4, 5);

void setup() {
    Serial.begin(9600);
    lora.begin(9600);

    pinMode(13, OUTPUT);

    digitalWrite(13, HIGH);
    delay(3000);
    digitalWrite(13, LOW);
}

void loop() {
  if (lora.available()) {
    String read_string = lora.readString();
    Serial.println(read_string.length());
    Serial.println(read_string);
    if (read_string.length() >= 74 && read_string.length() <= 78 &&read_string.indexOf("AgriWeather") != -1 && read_string.indexOf("!") == -1 && read_string.indexOf("@") == -1) {
        //Serial.println("if");
        //Serial.println(read_string.indexOf("AgriWeather"));
        //Serial.println(read_string);
        digitalWrite(13, HIGH);
        lora.println("@" + read_string);
        delay(500);
        digitalWrite(13, LOW);
    } else{
        //Serial.println("else");
        //Serial.println(read_string.indexOf("AgriWeather"));
        //Serial.println(read_string);
    }
  }
}
