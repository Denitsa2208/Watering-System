// C++ code
//
#include <Adafruit_LiquidCrystal.h>
int sensor_value=0;

int pin=8;
int percentage;
int buzzer_pin=13;
int PButton1=2;
int PButton2=4;


Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  Serial.begin(9600);
  //soil moisture sensor
  pinMode(pin,OUTPUT);
  
  //lcd display
  lcd_1.begin(16, 2);
  lcd_1.setCursor(0, 0);
  lcd_1.setBacklight(1);
  lcd_1.display();
  lcd_1.print("Welcome...");
  delay(4000);
  lcd_1.clear();
  
  //buzzer
  pinMode(buzzer_pin,OUTPUT);
  
  //Motor(Pump)
  pinMode(PButton1,OUTPUT);
  pinMode(PButton2,OUTPUT);
  
  
  
   
}

void loop()
{
  //Sensor
  digitalWrite(pin,HIGH);
  sensor_value=analogRead(A0);
  digitalWrite(pin,LOW);
  Serial.println(sensor_value);
  //moisture percentage
  percentage =map(sensor_value,0,872,0,100);
 
  //Printing percentage on display
  lcd_1.print(" Moisture value ");
  lcd_1.setCursor(7,1);
  lcd_1.print(percentage);
  lcd_1.print("%");
  delay(1000);
  lcd_1.clear();
  
  //buzzer/motor(pump)
  if (sensor_value<350)
     
  {
    digitalWrite(buzzer_pin,HIGH);
    digitalWrite(PButton1,HIGH);
  }
  else
  {
    digitalWrite(buzzer_pin,LOW);
    digitalWrite(PButton1,LOW);
  }
  

  
  delay(10); // Delay a little bit to improve simulation performance
 
}