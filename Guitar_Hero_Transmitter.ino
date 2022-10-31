#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10);
const byte address[6] = "00007";
int button_pin1 = 5;
int button_pin2 = 6;
int button_pin3 = 7;

int potValue = 0;
int buzzerPin = 4;
int text;
boolean button_state1 = 0;
boolean button_state2 = 0;
boolean button_state3 = 0;


void setup()
{
  pinMode(button_pin1, INPUT_PULLUP);
  pinMode(button_pin2, INPUT_PULLUP);
  pinMode(button_pin3, INPUT_PULLUP);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}



void loop()
{
  button_state1 = digitalRead(button_pin1);
  button_state2 = digitalRead(button_pin2);
  button_state3 = digitalRead(button_pin3);

  potValue = analogRead(A0);
  //Serial.println(potValue);
  
  if (button_state1 == LOW && potValue <= 500)
  {
    text = 1;
    radio.write(&text, sizeof(text));
    Serial.println(text);
    delay(10);
     
  }
  if (button_state1 == LOW && potValue >= 800)
  {
    text = 2;
    radio.write(&text, sizeof(text));
    Serial.println(text);
    delay(10);
  }

  if (button_state2 == LOW && potValue <= 500)
  {
    text = 3;
    radio.write(&text, sizeof(text));
    delay(10);
  }
  if (button_state2 == LOW && potValue >= 800)
  {
    text = 4;
    radio.write(&text, sizeof(text));
    delay(10);
  }

  if (button_state3 == LOW && potValue <= 500)
  {
    text = 5;
    radio.write(&text, sizeof(text));
    delay(10);
  }
  if (button_state3 == LOW && potValue >= 800)
  {
    text = 6;
    radio.write(&text, sizeof(text));
    delay(10);
  }
  


}
