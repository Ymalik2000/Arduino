//Coded By: Yash Malik
//Voice Activated Arduino (Bluetooth + Android)
#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); // RX | TX

String voice;
int motorPin1  = 3;  
int motorPin2  = 5;  
int motorPin3  = 6;
int motorPin4  = 9;  

void setup() {
BT.begin(9600);
Serial.begin(9600);

}
//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  if (voice.length() > 0){
    if(voice == "*go forward"){
      forward_car();
      }
    else if(voice == "*go back"){
      back_car();
      }
    else if(voice == "*turn right") {
      right_car();
    }
    else if(voice == "*turn left") {
      left_car();
    }
    else if(voice == "*stop") {
      stop_car();
    }
    
  voice=""; //Reset the variable after initiating
  }
  
  
}


void forward_car()
{
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 157);
    analogWrite(motorPin4, 0);  
}
  
void back_car()
{
    
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 157); 
}
  
void right_car()
{
    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
    delay(1100);
    stop_car();    
}
  
void left_car()
{
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);   
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(1250);
    stop_car();       

}
void stop_car ()
{
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
}
