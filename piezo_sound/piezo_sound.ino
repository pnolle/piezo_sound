#include <Arduino.h>

#define soundpin 4

void setup() {

  Serial.begin(115200);
  delay(6000);
}

void loop() {

  
  Serial.println("Buzzer Start");

  ledcAttach(soundpin,NOTE_A,7); //ledcAttach(uint8_tpin,uint32_tfreq,uint8_tresolution); for ESP core V3

  /*
  delay(115); 
  ledcWriteNote(soundpin,NOTE_A, 4);    // PIN, frequency, octave for ESP core V3
  delay(900);
  ledcWrite(soundpin,0); // No sound 
  */




  ledcWriteNote(soundpin,NOTE_E, 4);
  delay(100);
  ledcWrite(soundpin,0);
  delay(100);
  
  ledcWriteNote(soundpin,NOTE_E, 4);
  delay(100);
  ledcWrite(soundpin,0);
  delay(100);
  
  ledcWriteNote(soundpin,NOTE_E, 4);
  delay(400);
  ledcWrite(soundpin,0);

  

  ledcWriteNote(soundpin,NOTE_A, 3);
  delay(390);
  ledcWrite(soundpin,0);
  delay(10);

  ledcWriteNote(soundpin,NOTE_A, 3);
  delay(390);
  ledcWrite(soundpin,0);
  delay(10);
  

  
  ledcWriteNote(soundpin,NOTE_D, 4);
  delay(590);
  ledcWrite(soundpin,0);
  delay(10);
  
  ledcWriteNote(soundpin,NOTE_D, 4);
  delay(190);
  ledcWrite(soundpin,0);
  delay(10);


  
  ledcWriteNote(soundpin,NOTE_C, 4);
  delay(1000);
  ledcWrite(soundpin,0);




  /*
  
  ledcWriteNote(soundpin,NOTE_F, 3);
  delay(400);
  ledcWrite(soundpin,0);
  
  ledcWriteNote(soundpin,NOTE_G, 3);
  delay(400);
  ledcWrite(soundpin,0);
  
  ledcWriteNote(soundpin,NOTE_A, 3);
  delay(400);
  ledcWrite(soundpin,0);
  
  ledcWriteNote(soundpin,NOTE_B, 3);
  delay(400);
  ledcWrite(soundpin,0);
  
  ledcWriteNote(soundpin,NOTE_C, 4);
  delay(1000);
  ledcWrite(soundpin,0);

  

  */
  
  
  delay(1000);
  
  ledcDetach(soundpin);  
  Serial.println("Buzzer Stop");
  
  }
