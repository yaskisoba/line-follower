#include <Arduino.h>
#include <ACS712.h>

// verificar o monitor_speed no platformio.ini

const int irSensor1 = 32; 
const int irSensor2 = 33; 
const int irSensor3 = 25;

ACS712 sensor(34, 5.0); // confirmar tensão

void setup() {
    Serial.begin(115200);

    pinMode(irSensor1, INPUT);
    pinMode(irSensor2, INPUT);
    pinMode(irSensor3, INPUT);
}

void loop() {
    float current = sensor.mA_DC();
    Serial.print("Corrente: ");
    Serial.println(current);

    int irValue1 = digitalRead(irSensor1);
    int irValue2 = digitalRead(irSensor2);
    int irValue3 = digitalRead(irSensor3);

    Serial.print("IR1: ");
    Serial.print(irValue1);
    Serial.print(", IR2: ");
    Serial.print(irValue2);
    Serial.print(", IR3: ");
    Serial.println(irValue3);

    delay(1000); //em milesegundos
}
