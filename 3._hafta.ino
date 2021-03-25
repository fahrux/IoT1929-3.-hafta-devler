#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <SPI.h>                   
 
constexpr uint8_t RST_PIN = D3;
constexpr uint8_t SS_PIN = D4;


#define yesilled D8
#define kirmiziled D2

MFRC522 mfrc522(SS_PIN, RST_PIN); 
MFRC522 :: MIFARE_Key key;
String tag;

void setup() {
  pinMode(kirmiziled,OUTPUT);
  pinMode(yesilled,OUTPUT);
  
  Serial.begin(9600); 
  SPI.begin(); 
  mfrc522.PCD_Init(); 
  Serial.println("Kartınız okunuyor.");
}

void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent())
    return;
  if (mfrc522.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += mfrc522.uid.uidByte[i];
      }
    Serial.println(tag);
    if (tag == "00//karrtımı okutamadığım için bilmiyorum") {
      Serial.println("Hoşgeldiniz Fahrünisa Hanım.");
      digitalWrite(yesilled, HIGH);
      delay(2000);
      digitalWrite(yesilled, LOW);
      
      
    } else {
      Serial.println("Tanımsız kart ile giriş yapmaya çalışıyorsunuz.");
      digitalWrite(kirmiziled, HIGH);
      delay(2000);
      digitalWrite(kirmiziled, LOW);
    }
    tag = "";
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}
  
   
  
  
  



 

 
