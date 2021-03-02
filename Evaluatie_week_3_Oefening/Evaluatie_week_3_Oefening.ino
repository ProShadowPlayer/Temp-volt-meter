#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 2
 
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
LiquidCrystal lcd(12, 11, 5, 4, 3, 7);
float input_voltage = 0.0;
float temp=0.0;
float r1=5000.0;
float r2=1000.0;
DallasTemperature sensors(&oneWire);
 
void setup(void)
{

  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Temp=");
  lcd.setCursor(0, 1);
  lcd.print("Volt=")
  ;sensors.begin();
}
 
 
void loop(void)
{

  sensors.requestTemperatures(); 
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  lcd.setCursor(6, 0);
  lcd.print(sensors.getTempCByIndex(0));
   int analog_value = analogRead(A0);
   temp = (analog_value * 5.0) / 1024.0; 
   input_voltage = temp / (r2/(r1+r2));
   lcd.setCursor(6, 1); 
   lcd.print(input_voltage);
   Serial.println();
   Serial.print("Voltage = ");
   Serial.print(input_voltage);

   delay(1000);
}
