#include <Arduino.h>
#include <Wire.h>
#include "I2C_Definitions.h"
#include "HelperLED.h"
#include "HelperAnalog.h"
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme;  // I2C

/////// real time frame controls

#define MAX_FRAME 4
#define FRAME_INTERVAL 250UL
uint8_t frame = 0;
unsigned long frameMilliseconds = 0;
unsigned long marchMilliseconds = 0;
unsigned long generalAlarmMilliseconds = 0;

#define GREEN_LED_PIN 32
#define MQ2_LED_PIN 27
#define MQ7_LED_PIN 25

HelperLED greenLED;
HelperLED mq2LED;
HelperLED mq7LED;

#define PHOTO_RESISTOR_PIN 34
#define MQ2_PIN 39
#define MQ7_PIN 35

HelperAnalog photoSensor;
HelperAnalog mq2Sensor;
HelperAnalog mq7Sensor;

////////////////////////////////////////////////////////////////////////////
// I2C stuff
///////

///////
// Interrupt the bus master indicating data ready for transfer
void interruptMaster() {
  //i2cLED.on();
  //analogWrite(I2C_INT_PIN, 1023);
  //delay(10);
  //analogWrite(I2C_INT_PIN, 0);
  //Serial.println("Slave:interruptMaster");
}

///////
// Handle a request from the master for a packet of data
void requestEvent() {
  if (i2cCommand == 0x10) {
    Wire.write(registers, messageSize);
    //for (int i=0; i<8; i++) {
    //Wire.write(registers[i]);
    //}
    Serial.println("sending list");
  } else if (i2cCommand == 0x77) {
    //int motion = pirCounter;
    //memcpy(registers,&motion,2);
    Wire.write(registers, messageSize);
    //for (int i=0; i<8; i++) {
    //Wire.write(registers[i]);
    //}
  } else if (i2cCommand != 0x20) {
    Wire.write(registers[i2cCommand]);
    //i2cLED.off();
  }
}

///////
// prepare slave I2C bus transmissions
void initI2cSlave() {

  // set up the LED devices
  Serial.println("Slave:init LEDs");
  //i2cLED.init(I2C_LED_PIN);
  //errorLED.init(ERROR_LED_PIN);

  //pinMode(I2C_INT_PIN, OUTPUT);

  // I2C bus slave
  Serial.println("Slave:init Wire and requestEvent");
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(requestEvent);  // register master request data event
  //Wire.onReceive(receiveEvent);   // register master send data event
}

void setup() {
  delay(2000);
  Serial.begin(9600);
  while (!Serial)
    ;
  Serial.println("\n\rArduino Nano RP2040 Connect");
  Serial.println("I2C Communication Testbedt");
  Serial.println("Slave Processor Functions");

  greenLED.init(GREEN_LED_PIN);
  mq2LED.init(MQ2_LED_PIN);
  mq7LED.init(MQ7_LED_PIN);

  photoSensor.init(PHOTO_RESISTOR_PIN, 3.28, 10, 10);
  photoSensor.calibrate(300.0, 2.37);
  mq2Sensor.init(MQ2_PIN, 3.3, 10, 10);
  mq2Sensor.calibrate(300.0, 2.37);
  mq7Sensor.init(MQ7_PIN, 3.3, 10, 10);
  mq7Sensor.calibrate(300.0, 2.37);

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1)
      ;
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150);  // 320*C for 150 ms
}

void measurebme680() {
  if (!bme.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }
  Serial.print("Temperature = ");
  Serial.print(bme.temperature);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(bme.pressure / 100.0);
  Serial.println(" hPa");

  Serial.print("Humidity = ");
  Serial.print(bme.humidity);
  Serial.println(" %");

  Serial.print("Gas = ");
  Serial.print(bme.gas_resistance / 1000.0);
  Serial.println(" KOhms");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.println();
}

void loop() {
  // timed events

  unsigned long time = millis();
  unsigned long duration = time - frameMilliseconds;

  if (duration > FRAME_INTERVAL) {

    frameMilliseconds = time;
    frame++;

    // process frame sequenced code
    switch (frame) {
      case 0:
        {
          frameMilliseconds = millis();
          frame++;
        }
        break;
      case 1:
        {
          greenLED.blink();
        }
        break;
      case 2:
        {
        }
        break;
      case 3:
        {
        }
      case 4:
        {
          frame = 0;
        }
        break;
      default:
        break;
    }
  }

  photoSensor.read();
  int idata = photoSensor.counts();
  Serial.print("PR counts = ");
  Serial.print(idata);
  float fdata = photoSensor.millivolts();
  Serial.print("  Millivolts = ");
  Serial.println(fdata);
  Serial.println();

  mq2Sensor.read();
  idata = mq2Sensor.counts();
  Serial.print("MQ-2 counts = ");
  Serial.print(idata);
  fdata = mq2Sensor.millivolts();
  Serial.print("  Millivolts = ");
  Serial.println(fdata);

  mq7Sensor.read();
  idata = mq7Sensor.counts();
  Serial.print("MQ-7 counts = ");
  Serial.print(idata);
  fdata = mq7Sensor.millivolts();
  Serial.print("  Millivolts = ");
  Serial.println(fdata);
  Serial.println();

  measurebme680();

  delay(5000);
}
