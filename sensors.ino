#include "AS726X.h"

AS726X sensor;

void setup() {
  Wire.begin();
  Serial.begin(115200);

  sensor.begin();

  // Print out the columns for the csv
  if (sensor.getVersion() == SENSORTYPE_AS7262) {
    Serial.print("Violet;Blue;Green;Yellow;Orange;Red\n");
  } else {
    
  }
}

void loop() {
  sensor.takeMeasurements();
  //Prints all measurements
  if (sensor.getVersion() == SENSORTYPE_AS7262)
  {
    //Visible readings
    Serial.print(sensor.getCalibratedViolet(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedBlue(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedGreen(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedYellow(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedOrange(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedRed(), 2);
    Serial.print("\n");
  }
  else if (sensor.getVersion() == SENSORTYPE_AS7263)
  {
    //Near IR readings
    Serial.print(sensor.getCalibratedR(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedS(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedT(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedU(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedV(), 2);
    Serial.print(",");
    Serial.print(sensor.getCalibratedW(), 2);
   }
}
