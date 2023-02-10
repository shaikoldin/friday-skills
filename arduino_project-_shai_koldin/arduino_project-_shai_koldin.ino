#include <Adafruit_AHT10.h>
#include <Wire.h>
#include "Sodaq_DS3231.h"

Adafruit_AHT10 aht;

char weekDay[][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

//year, month, date, hour, min, sec and week-day(starts from 0 and goes to 6)
//writing any non-existent time-data may interfere with normal operation of the RTC.
//Take care of week-day also.
DateTime dt(2022, 12, 30, 11, 12, 0, 3);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);


  //voltage setup
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("voltage intialized");

  //AH10 initialize
  if (! aht.begin()) {
    Serial.println("Could not find AHT10? Check wiring");
    while (1) delay(10);
  }
  Serial.println("AHT10 found");

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  Serial.println("timestamp, temp.c, relhum, light intensity");



}


void loop() {
  // put your main code here, to run repeatedly:

  //read aht

  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data

  //read rtc

  DateTime now = rtc.now(); //get the current date-time

  //print both to serial

  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.date(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);

  delay(500);


  //printing voltage
  int sensorValue = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);

  Serial.println("timestamp, temp.c, relhum, light intensity");
  Serial.println (DateTime,);
 



}
