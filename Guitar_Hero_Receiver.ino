#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define NOTE_A4 440
#define NOTE_F4 349
#define NOTE_C5 523
#define NOTE_E5 659
#define NOTE_A5 880
#define NOTE_GS5 831
RF24 radio(9, 10);
const byte address[6] = "00007";
int button_pin1 = 5;
int button_pin2 = 6;
int button_pin3 = 7;
int potPin = 3;
int buzzerPin = 2;
boolean button_state1 = 0;
boolean button_state2 = 0;
boolean button_state3 = 0;
int potValue = 0;
int text ;
int note =0;
int newState;
int oldState =0;




void setup()
{
  //pinMode(6, OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}



void loop()
{ 
  //noTone(buzzerPin);
  //char text[32] = "";
  if (radio.available())
  {
    radio.read(&text, sizeof(text));
    newState = text;
    Serial.println (newState);
    if (text == 1 && oldState != newState)
    {
      tone(buzzerPin, NOTE_A4, 500);
      delay(1);
      oldState = newState;
      
    }
    if (text == 2 && oldState != newState)
    {
      tone(buzzerPin, NOTE_F4, 500);
      delay(1);
      oldState = newState;
    }

    if (text == 3 && oldState != newState)
    {
      tone(buzzerPin, NOTE_C5, 500);
      delay(1);
      oldState = newState;
    }
    if (text == 4 && oldState != newState)
    {
      tone(buzzerPin, NOTE_E5, 500);
      delay(1);
      oldState = newState;
    }

    if (text == 5 && oldState != newState)
    {
      tone(buzzerPin, NOTE_A5, 500);
      delay(1);
      oldState = newState;
    }
    if (text == 6 && oldState != newState)
    {
      tone(buzzerPin, NOTE_GS5, 500);
      delay(1);
      oldState = newState;
    }

    delay(100);
   
  }
}
