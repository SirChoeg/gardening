#include <LM75A.h>


#include <LiquidCrystal.h>
#include <LM75A.h>
#include <DHT.h>

#define CONTRASTPIN 13
#define CONTRAST 150
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte DT[8] = {
  0b11000,
  0b10100,
  0b10100,
  0b11000,
  0b00000,
  0b00111,
  0b00010,
  0b00010
};

byte DH[8] = {
  0b11000,
  0b10100,
  0b10100,
  0b11000,
  0b00000,
  0b00101,
  0b00111,
  0b00101
};

byte LT[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b11100,
  0b00000,
  0b00111,
  0b00010,
  0b00010
};

byte SH[8] = {
  0b01100,
  0b10000,
  0b01000,
  0b00100,
  0b11000,
  0b00101,
  0b00111,
  0b00101
};

byte PH[8] = {
  0b11000,
  0b10100,
  0b11000,
  0b10000,
  0b00000,
  0b00101,
  0b00111,
  0b00101
};

byte Light[8] = {
  0b00000,
  0b10101,
  0b01110,
  0b11011,
  0b01110,
  0b10101,
  0b00000,
  0b00000
};

LM75A lm75a_sensor(false,  //A0 LM75A pin state
                   false,  //A1 LM75A pin state
                   false); //A2 LM75A pin state
float Lm75atemp = 0;

#define DHTPIN 8 
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
float DhtTemp = 0;
float DhtHumid = 0;

int SoilHumidityPin= 0; // Soil Sensor input at Analog PIN A0
float SoilHumid = 0;

int PhPin= 1; // Soil Sensor input at Analog PIN A0
float Ph = 0;

void setup()
{
	pinMode(CONTRASTPIN, OUTPUT);
	lcd.begin(16, 2);
	Serial.begin(9600);
	dht.begin();
	lcd.createChar(0, LT);
	lcd.createChar(1, DT);
	lcd.createChar(2, DH);
	lcd.createChar(3, SH);
	lcd.createChar(4, PH);
	lcd.createChar(5, Light);
	analogWrite(CONTRASTPIN,CONTRAST);
	Serial.println("Reading sensor values");

}

void loop()
{
	analogWrite(CONTRASTPIN,CONTRAST);
	Lm75atemp = lm75a_sensor.getTemperatureInDegrees();
	SoilHumid = 100.0-(((analogRead(SoilHumidityPin)/10.0)/102.0)*100.0);
	DhtTemp = dht.readTemperature();
	DhtHumid = dht.readHumidity();
	Ph = analogRead(PhPin)-900;

	lcd.setCursor(0, 0);
	lcd.write(byte(0));
	lcd.print(Lm75atemp,1);

	Serial.print("Lm75aTemp: ");	
	Serial.println(Lm75atemp);

	lcd.setCursor(5, 0);
	lcd.write(byte(1));
	lcd.print(DhtTemp,0);

	Serial.print("DhtTemp: ");
	Serial.println(DhtTemp);

	lcd.setCursor(9, 0);
	lcd.write(byte(2));
	lcd.print(DhtHumid,0);
	
	Serial.print("DhtHumid: ");
	Serial.println(DhtHumid);

	lcd.setCursor(13, 0);
	lcd.write(byte(3));
	lcd.print(SoilHumid,0);

	Serial.print("SoilHumid: ");
	Serial.println(SoilHumid);

	lcd.setCursor(0, 1);
	lcd.write(byte(4));
	lcd.print(Ph,0);

	Serial.print("Ph: ");
	Serial.println(Ph);

	delay(1000);

}
