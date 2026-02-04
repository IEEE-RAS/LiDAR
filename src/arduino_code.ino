#include <Wire.h>
#include <VL53L1X.h>

//configurações do motor
#define PULSES_PER_REV 756
#define DEG_PER_PULSE 360/PULSES_PER_REV

//configurações do encoder optico
#define ENCODER_PIN_1 2
#define ENCODER_PIN_2 3

//configurações da ponte h
#define BRIDGE_PWMPIN 9
#define BRIDG_IN1PIN 7
#define BRIDGE_IN2PIN 8
#define BRIDGE_STDBYPIN 10


//configurações dos sensores
//angulo entre os sensores
#define SENSOR_ANGLE 60
//numero de sensores
#define SENSOR_NUMBER 3

//caso tenham mais sensores, adicionar mais linhas matendo a mesma ideia
#define SENSOR_1_XSHUTPIN 4
#define SENSOR_2_XSHUTPIN 5
#define SENSOR_3_XSHUTPIN 6

const uint8_t xshutPins[SENSOR_NUMBER] = { SENSOR_1_XSHUTPIN, SENSOR_2_XSHUTPIN, SENSOR_3_XSHUTPIN};

VL53L1X sensors[SENSOR_NUMBER];

volatile int step_count;
volatile int sensor_measure[SENSOR_NUMBER];
volatile int direction;




//codigo copiado do exemplo da biblioteca para uso de multiplos sensores
void setup()
{
    //configuração do sensor
    while (!Serial) {}
    Serial.begin(115200);
    Wire.begin();
    Wire.setClock(400000); // use 400 kHz I2C

    // Disable/reset all sensors by driving their XSHUT pins low.
    for (uint8_t i = 0; i < SENSOR_NUMBER; i++)
    {
        pinMode(xshutPins[i], OUTPUT);
        digitalWrite(xshutPins[i], LOW);
    }

    // Enable, initialize, and start each sensor, one by one.
    for (uint8_t i = 0; i < SENSOR_NUMBER; i++)
    {
        // Stop driving this sensor's XSHUT low. This should allow the carrier
        // board to pull it high. (We do NOT want to drive XSHUT high since it is
        // not level shifted.) Then wait a bit for the sensor to start up.
        pinMode(xshutPins[i], INPUT);
        delay(10);

        sensors[i].setTimeout(500);
        if (!sensors[i].init())
        {
            Serial.print("Failed to detect and initialize sensor ");
            Serial.println(i);
            while (1);
        }

        // Each sensor must have its address changed to a unique value other than
        // the default of 0x29 (except for the last one, which could be left at
        // the default). To make it simple, we'll just count up from 0x2A.
        sensors[i].setAddress(0x2A + i);

        sensors[i].startContinuous(50);
    }

    //configuração da ponte h
    pinMode(BRIDGE_PWMPIN, OUTPUT);
    pinMode(BRIDG_IN1PIN, OUTPUT);
    pinMode(BRIDGE_IN2PIN, OUTPUT);
    pinMode(BRIDGE_STDBYPIN, OUTPUT);
    digitalWrite(BRIDGE_STDBYPIN, HIGH);
    digitalWrite(BRIDGE_PWMPIN, HIGH);

    //configuração do encoder optico
    pinMode(ENCODER_PIN_1, INPUT);
    pinMode(ENCODER_PIN_2, INPUT);
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_1), encoder_1, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_2), encoder_2, RISING);
}

void loop()
{
    //leitura
    for (uint8_t i = 0; i < SENSOR_NUMBER; i++)
    {
        sensor_measure[i] = sensors[i].read();
    }

    if (step_count*DEG_PER_PULSE >= 360 || step_count*DEG_PER_PULSE <= 0) {
        direction = !direction
    }

    digitalWrite(BRIDG_IN1PIN, direction);
    digitalWrite(BRIDGE_IN2PIN, !direction);
}


void encoder_1(){
    if(digitalRead(ENCODER_PIN_2) == HIGH) {
        step_count++;
        direction = HIGH;
    } else {
        step_count--;
        direction = LOW;
    }
}

void encoder_2(){
    for (uint8_t i = 0; i < SENSOR_NUMBER; i++){
        Serial.print(i)
        Serial.print(",");
        Serial.print(sensor_measure[i]);
        Serial.print(",");
    }
    Serial.println(step_count);
}