#include <Arduino.h>

#define soundpin 4

void setup() {

  Serial.begin(115200);
  delay(6000);
}

void loop() {

  
  Serial.println("Buzzer Start");

  ledcAttach(soundpin,NOTE_A,7); //ledcAttach(uint8_tpin,uint32_tfreq,uint8_tresolution); for ESP core V3
  
  delay(115); 
  ledcWriteNote(soundpin,NOTE_A, 7);    // PIN, frequency, octave for ESP core V3
  delay(900);
  
  ledcWrite(soundpin,0); // No sound 


  ledcWriteNote(soundpin,NOTE_C, 3);    // PIN, frequency, octave for ESP core V3
  delay(900);
  
  ledcWrite(soundpin,0); // No sound 
  
  ledcDetach(soundpin);  
  Serial.println("Buzzer Stop");
  
  }


/*

// Define the pin where the piezo is connected
const int piezoPin = 15; // Replace with your GPIO pin number

// Define the frequency for each note (in Hertz)
const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_G4 = 392;

// Set up LEDC PWM channel
const int pwmChannel = 0;
const int pwmResolution = 8;  // 8-bit resolution (0-255 duty cycle)
const int pwmFrequency = 2000; // Default frequency to set up

void setup() {
  // Initialize the PWM channel for the piezo
  // ledcSetup(pwmChannel, pwmFrequency, pwmResolution); // Set default frequency and resolution
  ledcAttach(piezoPin, NOTE_C4, pwmResolution);
}

void playNote(int frequency, int duration) {
  // Set the frequency to play the note
  ledcWriteNote(piezoPin, frequency, pwmFrequency); // Set frequency for note
  delay(duration);
  // Stop the tone after the duration
  ledcWrite(piezoPin, 0); // Stop sound by setting duty cycle to 0
  ledcDetach(piezoPin);
}

void playSlide(int startFreq, int endFreq, int duration) {
  // Play a sliding tone from startFreq to endFreq over the specified duration
  int steps = 50; // Number of steps for the slide
  int stepDuration = duration / steps;
  int freqStep = (endFreq - startFreq) / steps;

  for (int i = 0; i <= steps; i++) {
    int currentFreq = startFreq + (freqStep * i);
    ledcWriteTone(pwmChannel, currentFreq); // Set frequency to create slide effect
    ledcWrite(pwmChannel, 127); // Set duty cycle (50%)
    delay(stepDuration);
  }
  // Stop the tone after the slide
  ledcWrite(pwmChannel, 0);
}

void loop() {
  // Play individual notes
  playNote(NOTE_C4, 500);
  delay(100);
  playNote(NOTE_D4, 500);
  delay(100);
  playNote(NOTE_E4, 500);
  delay(100);
  playNote(NOTE_G4, 500);
  delay(300);

  // Play a sliding tone from C4 to G4
  playSlide(NOTE_C4, NOTE_G4, 1000);
  delay(1000);  // Wait before repeating
}

  */
