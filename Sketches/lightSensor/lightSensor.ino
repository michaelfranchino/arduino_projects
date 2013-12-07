int sensorPin = A0;
int led = 13;

float rawRange = 1024;
float logRange = 5.0;
float rawMin = 999999999.00;
float rawMax = 0.00;
int   samples = 500;

void setup()
{
  analogReference(EXTERNAL);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println("Light sensor test");
  
  getAmbient();
}

void loop()
{ 
  float  reading = 0.00;
  reading = getReading();
  
  if (reading < rawMin || reading > rawMax)
  {
    Serial.print("A change in ambient has been noticed. Value was ");
    Serial.println(reading);
  }
  delay(250);
}

void getAmbient()
{
  float totalRawRead = 0.0;
  
  float ambientAverage = 0.00;
  float reading = 0.00;
  
  Serial.print("Let me get the ambient luxes");
  for(int i=0;i < samples;i++) 
  {
    reading = getReading();
    if (reading < rawMin)
      rawMin = reading;
    if (reading > rawMax)
      rawMax = reading;
    totalRawRead += reading;
    delay(75);
  }

  ambientAverage = totalRawRead / samples;

  Serial.println("");
  Serial.print("Ok.. Ambient low was ");
  Serial.print(rawMin);
  Serial.print(" and ambient high was ");
  Serial.print(rawMax);
  Serial.print(" with an average of ");
  Serial.println(ambientAverage);
}

float getReading()
{
  int rawValue = analogRead(sensorPin);
  
  //Serial.Serial.print("Raw = ");
  //Serial.Serial.print(rawValue);
  //Serial.Serial.print(" - Lux = ");
  //Serial.Serial.println(RawToLux(rawValue));
  
  return RawToLux(rawValue);
}

float RawToLux(int raw)
{
  float logLux = raw * logRange / rawRange;
  return pow(10, logLux);
}
  
