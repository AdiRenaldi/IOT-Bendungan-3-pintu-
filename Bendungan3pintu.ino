#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27 ,20,4);

const int TRIGGER = 5;
const int ECHO = 6;
const int buzzer = 7;

const int enA = 3;
const int in1 = 2;
const int in2 = 4;

NewPing sonar(TRIGGER, ECHO);
String dataLama = "";
String dc = "";

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("ALAT PENDETEKSI");
  lcd.setCursor(7, 1);
  lcd.print("BANJIR");
  lcd.setCursor(1, 3);
  lcd.print("FILDA 13020190150"); 
  delay(5000);
}

void loop() {
  int jarak = sonar.ping_cm();
  // Serial.println(jarak);
  delay(20);

  // analogWrite(enA, 255);
  //     digitalWrite(in1, HIGH);
  //     delay(400);
  //     digitalWrite(in1, LOW);

  if(dc == "siaga1" && jarak > 26){
      dc = "";
      analogWrite(enA, 255);
      digitalWrite(in2, HIGH);
      delay(300);
      digitalWrite(in2, LOW);
  }

  if(jarak >=5 && jarak <=7){
    if(jarak == 7){
      String dataJarak = String("SIAGA 1, ") + String("KETINGGIAN AIR : ") + String(jarak) + String(" CM");
      if(dataJarak != dataLama){
        Serial.println(dataJarak);
        dataLama = dataJarak;
      }
    }

      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("SIAGA SATU");
      lcd.setCursor(2, 1);
      lcd.print("JARAK AIR " + String(jarak) + " CM");
      lcd.setCursor(1, 3);
      lcd.print("FILDA 13020190150"); 

    if(dc != "siaga1"){
      dc = "siaga1";
      analogWrite(enA, 255);
      digitalWrite(in1, HIGH);
      delay(100);
      digitalWrite(in1, LOW);
    }

      digitalWrite(buzzer, HIGH);
      delay(5000);
      digitalWrite(buzzer, LOW);
      delay(2000);
      
  } else if(jarak > 7 && jarak <=17) {
      if(jarak == 17){
        String dataJarak = String("SIAGA 2, ") + String("KETINGGIAN AIR : ") + String(jarak) + String(" CM");
        if(dataJarak != dataLama){
          Serial.println(dataJarak);
          dataLama = dataJarak;
        }
      } 
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("SIAGA DUA");
      lcd.setCursor(2, 1);
      lcd.print("JARAK AIR " + String(jarak) + " CM");
      lcd.setCursor(1, 3);
      lcd.print("FILDA 13020190150");

    if(dc != "siaga2" && dc != "siaga1"){
      dc = "siaga2";
      analogWrite(enA, 255);
      digitalWrite(in1, HIGH);
      delay(130);
      digitalWrite(in1, LOW);

      for(int i = 1; i <= 2; i++){
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(500);
      }
    }
      delay(2000); 

  } else if(jarak > 17 && jarak <=26) {
      if(jarak == 26){
        String dataJarak = String("SIAGA 3, ") + String("KETINGGIAN AIR : ") + String(jarak) + String(" CM");
        if(dataJarak != dataLama){
          Serial.println(dataJarak);
          dataLama = dataJarak;
        }
      } 
      lcd.clear();
      lcd.setCursor(5, 0);
      lcd.print("SIAGA TIGA"); 
      lcd.setCursor(2, 1);
      lcd.print("JARAK AIR " + String(jarak) + " CM");
      lcd.setCursor(1, 3);
      lcd.print("FILDA 13020190150");

    if(dc != "siaga3" && dc != "siaga2" && dc != "siaga1"){
      dc = "siaga3";
      analogWrite(enA, 255);
      digitalWrite(in1, HIGH);
      delay(130);
      digitalWrite(in1, LOW);

      for(int i = 1; i <= 3; i++){
        digitalWrite(buzzer, HIGH);
        delay(1000);
        digitalWrite(buzzer, LOW);
        delay(500);
      }
    }
      delay(2000);

  } else if (jarak > 26) {
      dc = "";
      Serial.println("STATUS NORMAL   JARAK AIR " + String(jarak) + " CM");
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("STATUS NORMAL");  
      lcd.setCursor(2, 1);
      lcd.print("JARAK AIR " + String(jarak) + " CM");
      lcd.setCursor(1, 3);
      lcd.print("FILDA 13020190150");
      
      delay(2000);
  }

}
