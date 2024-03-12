#include <FastLED.h> // LED library

//const int buttonPin = 7;

#define LED_PIN     3 // Where 
#define NUM_LEDS    3 // Define the number of LEDs in your strip
#define BRIGHTNESS  255

CRGB leds[NUM_LEDS];   // Define an array for storing LED colors

const int rockerSwitch = 4;

//const int rockerSwitch2 = 2; // Where rocker switch digital input is located

void setup() {
  pinMode(rockerSwitch, INPUT); // pin where rocker switch is located
  //pinMode(buttonPin, INPUT);
 // pinMode(rockerSwitch2, INPUT);
  FastLED.addLeds<WS2812, LED_PIN, BRG>(leds, NUM_LEDS); // Use WS2812 as LED type right now BRG works best
  //pinMode(, OUTPUT);

  Serial.begin(9600); // serial monitor connection
}

//void printWithNewline(String message){
  //Serial.print(message);   
  //Serial.printIn();
//}

void loop() {
 
 int rockerswitchState = digitalRead(rockerSwitch);
 //int rockerswitchState2 = digitalRead(rockerSwitch2);

// check for neutral state is High and Low vs High or Low
// was (rockerswitchState == HIGH)
// rockerswitchState = !rockerswitchState 
  Serial.print("Rocker Switch State");
  Serial.println(rockerswitchState);
 if (!rockerswitchState == HIGH && !rockerswitchState == LOW) {
   // when the switch is in the common position, turn off or on black
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    Serial.print("Black = OFF");
    Serial.println();  
    } else if(rockerswitchState == LOW) {
    // when the switch is on the second position labelled 2, turn on color blue
    fill_solid(leds, NUM_LEDS, CRGB::Blue);
    FastLED.show();
    Serial.print("Blue = CHECK");
    Serial.println();
    //Serial.printIn("Blue"); // Wrong syntax
    // this is high position 
    } else {
   // // this is high position 
   // when the switch is on first position labelled 1, turn on color yellow
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
    Serial.print("Red = HELP");
    Serial.println();
    //Serial.printIn("Red"); // Wrong syntax
  }

   delay(1000);
 }
  //int buttonState = digitalRead(buttonPin);

  // check if the button got pressed
  //if (buttonState == HIGH){
   // Serial.print("Button!!");
   // Serial.println();
 // }
    //delay(1000);
  
    //printf_P();

    //digitalWrite(7, HIGH); // Turn on LED strip
  //} 
  //else {
    //digitalWrite(7, LOW); // Turn off LED strip

  //}
  // Set all LEDs to red
  //fill_solid(leds, NUM_LEDS, CRGB::Red);
  //FastLED.show();
  //delay(500);

  // Set all LEDs to green
  //fill_solid(leds, NUM_LEDS, CRGB::Green);
  //FastLED.show();
  //delay(1000);

  // Set all LEDs to blue
  //fill_solid(leds, NUM_LEDS, CRGB::Blue);
  //FastLED.show();
  //delay(1000);
//}