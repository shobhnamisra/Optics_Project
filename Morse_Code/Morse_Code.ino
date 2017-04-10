 
//**************************************************//
//   Type the String to Convert to Morse Code Here  //
//**************************************************//
char stringToMorseCode[6];

// Create variable to define the output pins
int led12 = 12;      // blink an led on output 12
int led6 = 6;        // blink an led on output 6

#include <Arduino.h>
#include "BasicStepperDriver.h"

// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200

// All the wires needed for full functionality
#define DIR 8
#define STEP 9
//Uncomment line to use enable/disable functionality
//#define ENBL 7

// Since microstepping is set externally, make sure this matches the selected mode
// 1=full step, 2=half step etc.
#define MICROSTEPS 1

// 2-wire basic config, microstepping is hardwired on the driver
BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP);

//Uncomment line to use enable/disable functionality
//BasicStepperDriver stepper(MOTOR_STEPS, DIR, STEP, ENBL);

/*
  Set the speed of your morse code
  Adjust the 'dotlen' length to speed up or slow down your morse code
    (all of the other lengths are based on the dotlen)

  Here are the ratios code elements:
    Dash length = Dot length x 3
    Pause between elements = Dot length
      (pause between dots and dashes within the character)
    Pause between characters = Dot length x 3
    Pause between words = Dot length x 7
  
      
*/

int dotLen = 100;     // length of the morse code 'dot'
int dashLen = dotLen * 3;    // length of the morse code 'dash'
int elemPause = dotLen*2;  // length of the pause between elements of a character
int Spaces = dotLen * 3;     // length of the spaces between characters
int wordPause = dotLen * 7;  // length of the pause between words

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output for LED lights.
  pinMode(led12, OUTPUT); 
  pinMode(led6, OUTPUT);
  Serial.begin(9600); 
    /*
     Set target motor RPM.
     These motors can do up to about 200rpm.
     Too high will result in a high pitched whine and the motor does not move.
  */
  stepper.setRPM(120);
}

// Create a loop of the letters/words you want to output in morse code (defined in string at top of code)
void loop()
{ 
   
 
  // Loop through the string and get each character one at a time until the end is reached
  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)
  { stringToMorseCode[i]= Serial.read();
    // Get the character in the current position
  char tmpChar = stringToMorseCode[i];
  // Set the case to lower case
  tmpChar = toLowerCase(tmpChar);
  // Call the subroutine to get the morse code equivalent for this character
  GetChar(tmpChar);
  }
  
  // At the end of the string long pause before looping and starting again
  LightsOff(500);      
}

// DOT
void MorseDot()
{
  digitalWrite(led12, HIGH);    // turn the LED on 
  digitalWrite(led6, LOW); 
 // tone(audio8, note, dotLen); // start playing a tone
  delay(dotLen*5);              // hold in this position
  
  stepper.setMicrostep(MICROSTEPS);

  /*
     Moving motor one full revolution using the degree notation
  */
  stepper.rotate(90);
  delay(2000);
  stepper.rotate(-90);
  /*
     Moving motor to original position using steps
  */
}

// DASH
void MorseDash()
{
  digitalWrite(led12, LOW);    // turn the LED on 
  digitalWrite(led6, HIGH);
  //tone(audio8, note, dashLen);  // start playing a tone
  delay(dashLen*5);               // hold in this position
  
  stepper.setMicrostep(MICROSTEPS);
  delay(1000);
  /*
     Moving motor one full revolution using the degree notation
  */

  /*
     Moving motor to original position using steps
  */
}

// Turn Off
void LightsOff(int delayTime)
{
  digitalWrite(led12, LOW);     // turn the LED off   
  digitalWrite(led6, LOW);
 // noTone(audio8);             // stop playing a tone
  delay(delayTime);             // hold in this position
}

// *** Characters to Morse Code Conversion *** //
void GetChar(char tmpChar)
{
  // Take the passed character and use a switch case to find the morse code for that character
  switch (tmpChar) {
    case 'a': 
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'b':
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'c':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'd':
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'e':
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'f':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'g':
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'h':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'i':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'j':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
      case 'k':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'l':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
      case 'm':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'n':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'o':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'p':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 'q':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'r':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 's':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    case 't':
      MorseDash();
    LightsOff(elemPause);
    break;
    case 'u':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'v':
      MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'w':
      MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'x':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'y':
      MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    break;
    case 'z':
      MorseDash();
    LightsOff(elemPause);
    MorseDash();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    MorseDot();
    LightsOff(elemPause);
    break;
    default: 
    // If a matching character was not found it will default to a blank space
    LightsOff(Spaces);      
  }
}

