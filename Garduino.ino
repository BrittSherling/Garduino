/*A prototype for monitoring Temp, Humidity, and Soil Moisture fora garden*/#include <LiquidCrystal.h>#include "DHT.h"#define DHTPIN 7     // what digital pin we're connected to#define DHTTYPE DHT11   // DHT 11 temp&humidity sensorDHT dht(DHTPIN, DHTTYPE);   // Initialize DHT sensorLiquidCrystal lcd(12, 11, 5, 4, 3, 2);    // initialize the library with the numbers of the interface pinsvoid setup() {  Serial.begin(9600);  // set up the LCD's number of columns and rows:  lcd.begin(16, 2);  // Print a message to the LCD.  lcd.print("Temp: ");  lcd.print("Humidity: ");  dht.begin();}void loop() {  delay(2000); // wait 2 seconds before updating    float humidity = dht.readHumidity(); // Read humidity  float f = dht.readTemperature(true); // Read temperature as Fahrenheit (isFahrenheit = true)  // read the input on analog pin 0:  int soil_raw = analogRead(A0);  // convert soil_moist to 0 - 100 values  int soil_real = map(soil_raw, 0, 1023, 0, 100);    // print out the value you read:  Serial.print("humidity: ");  Serial.println(humidity);  Serial.print("Temp: ");  Serial.println(f);  Serial.print("Soil Moisture: ");  Serial.println(soil_real);  lcd.setCursor(0,1);  lcd.print(f);  lcd.setCursor(6, 1);  lcd.print(humidity);  }