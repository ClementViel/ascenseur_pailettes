/*
duty cycle in arduino is represented by a 8 bit value: 0 - 255
0 --> 0%
127 -->50%
255 --> 100%
*/
#include <AStar32U4.h>
#include <Servo.h>
 #include <avr/io.h>


Servo myservo;
AStar32U4Motors motors;
AStar32U4ButtonA buttonA;
AStar32U4ButtonB buttonB;
AStar32U4ButtonC buttonC;

int pos = 0; 
int button_pressed = 0;


  
void setup() {
   
  // Timer 3 configuration
  // prescaler: clockI/O / 1
  // outputs enabled
  // phase-correct PWM
  // top of 400
  //
  // PWM frequency calculation
  // 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20kHz
  // TCCR3A = 0b10100000;
  // TCCR3B = 0b00010001;
  // ICR3 = 400;  
  // OCR3A = 0;  
  // OCR3B = 0;
  // pinMode(PWM_M2, OUTPUT);
  // pinMode(DIR_M2, OUTPUT);
  myservo.attach(6);
}

void loop() {

if (pos) {
  myservo.write(0);
  pos=0;
}

  if (buttonA.isPressed()) {
     do
     {
      Serial.println("coucou");
      motors.setM2Speed(-50);
    
    }  while(buttonA.isPressed());
  }
   
  if (buttonB.isPressed()) {
    do
    {

      motors.setM2Speed(50);
      
    } while(buttonB.isPressed());
  }

  if (buttonC.isPressed()) {
    do
    {
      pos = 1;
      myservo.write(105);
      
    } while(buttonC.isPressed());
  }
       motors.setM2Speed(0);


  
}