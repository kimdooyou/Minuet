#include "pitches.h"

// notes in the melody:
const int ACTIVE_BUZZER = 12;

int melody[] = {

 NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4,  NOTE_C5, NOTE_D5, 
 NOTE_G4, NOTE_G4, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5,   
 NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G4, NOTE_C5, NOTE_D5,
 NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, 
 NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4,
 NOTE_G4, NOTE_B4, NOTE_A4, NOTE_D5, NOTE_G4, NOTE_A4, 
 NOTE_B4,  NOTE_C5, NOTE_D5, NOTE_G4, NOTE_G4,     
 NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5,   
 NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G4, NOTE_C5, NOTE_D5,
 NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, 
 NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4
//  NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4,  NOTE_C5, NOTE_D5, 
//  NOTE_G4, NOTE_G4, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5,   
//  NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G4, NOTE_C5, NOTE_D5,
//  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_B4, 
//  NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
//  NOTE_FS4, NOTE_G4,
//  NOTE_B5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_G5,
//  NOTE_A5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_D5, NOTE_G5, NOTE_E5,
//  NOTE_FS5, NOTE_G5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_CS5,
//  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_E5,//77
//  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_A4, NOTE_CS5,
//  NOTE_D5, NOTE_D5, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_E5, NOTE_G4,
//  NOTE_FS4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4,
//  NOTE_G4, NOTE_A4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4,
//  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_G4, NOTE_FS4, NOTE_G4,
//  NOTE_B5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_G5,
//  NOTE_A5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_D5, NOTE_G5, NOTE_E5,
//  NOTE_FS5, NOTE_G5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_CS5,
//  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_E5,//77
//  NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_A4, NOTE_CS5,
//  NOTE_D5, NOTE_D5, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_E5, NOTE_G4,
//  NOTE_FS4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4,
//  NOTE_G4, NOTE_A4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4,
//  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_G4, NOTE_FS4, NOTE_G4     
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = { 4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,8,8,8,8,4,8,8,8,8,8,2.5,
                        4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,8,8,8,8,4,8,8,8,8,2.5
                        // 4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,8,8,8,8,4,8,8,8,8,8,2.5,
                        // 4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,8,8,8,8,4,8,8,8,8,2.5,
                        // 4,8,8,8,8,4,8,8,8,8,4,8,8,8,8,4,8,8,4,8,8,8,8,8,8,4,4,4,4,4,4,2.5,
                        // 4,8,8,4,4,8,8,4,4,4,4,8,8,8,8,4,8,8,8,8,8,8,4,4,4,8,8,4,4,2.5,
                        // 4,8,8,8,8,4,4,4,4,8,8,8,8,4,4,4,4,8,8,8,8,4,8,8,8,8,4,8,8,8,8,2.5,
                        // 4,8,8,8,8,4,8,8,8,8,4,8,8,8,8,4,8,8,4,8,8,8,8,8,8,4,4,4,4,4,4,2.5,
                        // 4,8,8,4,4,8,8,4,4,4,4,8,8,8,8,4,8,8,8,8,8,8,4,4,4,8,8,4,4,2.5
                        };


void setup() {
 
  pinMode(ACTIVE_BUZZER, OUTPUT);  //부저핀을 출력으로 설정

  for (int n = 0; n < 65; n++) {  

   int noteDuration = 1000 / noteDurations[n]; //음의 길이를 초단위로 변경

    tone(ACTIVE_BUZZER, melody[n], noteDuration); //해당 핀에서 주파수와 음의 길이를 피에조로 음을 출력

    int pauseBetweenNotes = noteDuration * 1.30; // 음과 음사이에 쉬는 것은 noteDuration의  30%

    delay(pauseBetweenNotes); // 음과 음사이의 갚으로 지연시킴

    
    noTone(ACTIVE_BUZZER); // 연주를 멈춘다

  }
}
 

void loop() {
 
}
