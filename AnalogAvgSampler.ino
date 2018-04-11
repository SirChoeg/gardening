const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
int sensorValue = 0;        // value read from the pot
int cnt = 0;
int sum = 0;
const int avg = 1000;

void setup()
{
	Serial.begin(9600);
	Serial.print("Sampling starts with ");
	Serial.print(avg);
	Serial.println(" sample average");
	// initialize serial communications at 9600 bps: 	
}

void loop()
{	
	sensorValue = analogRead(analogInPin);
	sum += sensorValue;
	cnt ++;
	if( cnt == avg){
		Serial.print("average = ");
	 	Serial.println(sensorValue);
	 	//Serial.println();
	 	sum=0;
	 	cnt=0;		
	}
	delay(2);

}

