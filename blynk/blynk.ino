#define BLYNK_TEMPLATE_ID "TMPL6ev5Ith6_"
#define BLYNK_TEMPLATE_NAME "Pendeteksi banjir"
#define BLYNK_AUTH_TOKEN "65xKlHCDWthzXdg9hj5G8qtsjnd6uXan"

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "rahma";
char pass[] = "hp12345678910";
// char ssid[] = "iPhone";
// char pass[] = "1234567890";

// pin Lcd Blynk
WidgetLCD lcd(V1);

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  lcd.clear();
  lcd.print(1, 0, "DETEKSI BANJIR");
  delay(1000);
}

void loop()
{
  Blynk.run();

  String data = "";
  while(Serial.available() > 0){
    data += char(Serial.read());
  }


  Serial.println(data);

  // print data di Lcd blynk 
  if(data.length() > 0){
    lcd.clear();
    lcd.print(0, 0, data);
  }
  
  delay(1000);
}
