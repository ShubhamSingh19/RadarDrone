#include <NewPing.h> 
#include <Servo.h>   
#define TRIG_PIN A4  
#define ECHO_PIN A5  
#define MAX_DISTANCE 200  
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);  
Servo myservo;     
boolean goesForward=false; 
int distance = 100; 
int speedSet = 0;  
const int motorPin1  = 3;   
const int motorPin2  = 11;   
//Motor B 
const int motorPin3  = 6;  
const int motorPin4  = 9;    
void setup() {  
  myservo.attach(5);   
  myservo.write(90);  
  delay(2000); 
  distance = readPing(); 
  delay(100); 
  distance = readPing(); 
  delay(100); 
  distance = readPing(); 
  delay(100); 
  distance = readPing(); 
  delay(100); 
}  
void loop() { 
 int distanceR = 0; 
 int distanceL =  0; 
 delay(40); 
  
 if(distance<=10) 
 { 
  moveStop(); 
  delay(100); 
 // moveBackward(); 
  //delay(600); 
 // moveStop(); 
  //delay(200); 
  distanceR = lookRight(); 
  delay(200); 
  distanceL = lookLeft(); 
  delay(200);  
  if(distanceR>=distanceL) 
  { 
    turnRight(); 
    moveStop(); 
  }else 
  { 
    turnLeft(); 
    moveStop(); 
  } 
 }else 
 { 
  moveForward(); 
 } 
 distance = readPing(); 
}  
int lookRight() 
{ 
    myservo.write(10);  
    delay(500); 
    int distance = readPing(); 
    delay(100); 
    myservo.write(90);  
    return distance; 
}  
int lookLeft() 
{ 
    myservo.write(170);  
    delay(500); 
    int distance = readPing(); 
    delay(100); 
    myservo.write(90);  
    return distance; 
    delay(100); 
}  
int readPing() {  
  delay(70); 
  int cm = sonar.ping_cm(); 
  if(cm==0) 
  { 
    cm = 250; 
  } 
  return cm; 
}  
void moveStop() { 
  analogWrite(motorPin1, 0); 
    analogWrite(motorPin2, 0); 
    analogWrite(motorPin3, 0); 
    analogWrite(motorPin4, 0); 
  }  
   
void moveForward() {   
    analogWrite(motorPin1, 230); //the value 230 here is a PWM so you can change it depending ip on your motor speed
    analogWrite(motorPin2, 0); 
    analogWrite(motorPin3, 230); // this one too
    analogWrite(motorPin4, 0);   
   
}  
void moveBackward() { 
     
    analogWrite(motorPin1, 0); 
    analogWrite(motorPin2, 230);
    analogWrite(motorPin3, 0); 
    analogWrite(motorPin4, 230);
   
}    
void turnRight() { 
 analogWrite(motorPin1, 240); 
    analogWrite(motorPin2, 0); 
  analogWrite(motorPin3, 0); 
    analogWrite(motorPin4, 240);     
  delay(1000); 
 moveForward();       
   
}  
  
void turnLeft() { 
  analogWrite(motorPin1, 0); 
    analogWrite(motorPin2, 240);    
 analogWrite(motorPin3, 240); 
    analogWrite(motorPin4, 0);      
  delay(670); 
   moveForward(); 
}

