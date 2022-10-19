#include <TinyGPS.h>
#include "LiquidCrystal.h"  

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);


TinyGPS gps;  //Creates a new instance of the TinyGPS object


void setup()
{
  Serial.begin(9600);  
  Serial.print("Branch : Telecommunication Engineering  "); Serial.println(TinyGPS::library_version());
  Serial.println("Testing GPS");
  Serial.println("Under the Guidance of Dr Prashanth CR sir ");
  Serial.println("Designed by : Deepika, Jagruth, Jayshree, Rachana ");
  Serial.println();
  
  lcd.begin(16,2);
  lcd.setCursor(1,0);
  lcd.print("Temp= ");
  lcd.setCursor(10,0);
  lcd.print("C");
  lcd.setCursor(1,1);
lcd.print("RESULT");
}

void loop()
{
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (Serial.available())
    {
      char c = Serial.read();
      //Serial.print(c);
      if (gps.encode(c)) 
        newData = true;  
    }
  }

  if (newData)      //If newData is true
  {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);   
    Serial.print("Latitude = ");
    Serial.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
    Serial.print(" Longitude = ");
    Serial.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);

  }
 
  Serial.println(failed);
 // if (chars == 0)
   // Serial.println("** No characters received from GPS: check wiring **");
   
     int Valeur=analogRead(A0);
    int Vout=Valeur*5.0/1023*1000;
    int temp=Vout/10;
   
    lcd.setCursor(7,0);
    lcd.print(temp);

}
