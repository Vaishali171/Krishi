#include <OneWire.h>
#include <DallasTemperature.h>


#define SOIL_MOISTURE_PIN A1
#define TURBIDITY_PIN     A2
#define PH_SENSOR_PIN     A0
#define ONE_WIRE_BUS      2  


OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  
  int soilValue = analogRead(SOIL_MOISTURE_PIN);
  float soilPercent = map(soilValue, 1023, 0, 0, 100); 

  
  int turbidityValue = analogRead(TURBIDITY_PIN);

 
  int phRaw = analogRead(PH_SENSOR_PIN);
  float voltage = phRaw * (5.0 / 1023.0);
  float phValue = 7 + ((2.5 - voltage) / 0.18);  


  sensors.requestTemperatures();
  float tempC = sensors.getTempCByIndex(0);

  
  Serial.println("------ Sensor Readings ------");
  Serial.print("Soil Moisture (%): ");
  Serial.println(soilPercent);

  Serial.print("Turbidity (Raw): ");
  Serial.println(turbidityValue);

  Serial.print("pH Value (Approx): ");
  Serial.println(phValue);

  Serial.print("Temperature (°C): ");
  Serial.println(tempC);

  Serial.println("-----------------------------\n");
  delay(2000);
}