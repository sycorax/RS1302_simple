#include <RS1302_simple.h>

void setup() {
 ds1302_setup();
 Serial.begin(9600);
}

void loop() {
char * t= get_time();
Serial.println(t);
delay(1000);
char * d= get_date();
Serial.println(d);
delay(3000);
}