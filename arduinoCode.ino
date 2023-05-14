//Arduino Bluetooth Controlled Car
//Before uploading the code you have to install the necessary library
//Note - Disconnect the Bluetooth Module before hiting the upload button otherwise you'll get compilation error message.
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install 
//After downloading the library open Arduino IDE >> go to sketch >> Include Libray >> ADD. ZIP Libray >> Select the downloaded 
//ZIP File >> Open it >> Done
//Now You Can Upload the Code without any problem but make sure the bt module isn't connected with Arduino while uploading code

#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_64KHZ); 
AF_DCMotor motor2(2, MOTOR12_64KHZ); 
AF_DCMotor motor3(3, MOTOR34_64KHZ);
AF_DCMotor motor4(4, MOTOR34_64KHZ);



char command; 

int speeed = 200;

void setup() 
{  
  Serial.begin(9600);  
  pinMode(2, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
 
  
  
    //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
//    Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case '0':
      speeed = 50;
      break;
    case '1':
      speeed = 70;
      break;
    case '2':
      speeed = 90;
      break;
    case '3':
      speeed = 110;
      break;
    case '4':
      speeed = 130;
      break;
    case '5':
      speeed = 150;
      break;
    case '6':
      speeed = 170;
      break;
    case '7':
      speeed = 190;
      break;
    case '8':
      speeed = 210;
      break;
    case '9':
      speeed = 230;
      break;
    case 'q':
      speeed = 255;
      break;
    case 'B':  
       back();
      break;
    case 'R':  
      left();
      break;
    case 'L':
      right();
      break;
    case 'W':
      hl();
      break;
    case 'w':
      hloff();
      break;
    case 'U':
      bl();
      break;
    case 'u':
      bloff();
      break;
    case 'V':
      horn();
      break;
    case 'v':
      hornoff();
      break;   
    case 'G':  
      forleft();
      break;
    case 'I':  
      forright();
      break;
    case 'H':
      backleft();
      break;
    case 'J':
      backright();
      break;
    
    }
  } 
}

void forward()
{

  motor1.setSpeed(speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(speeed);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(speeed);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void forright()
{

  motor1.setSpeed(speeed/4); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(speeed/4); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(speeed);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(speeed);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}
void forleft()
{

  motor1.setSpeed(speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(speeed/4);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(speeed/4);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void back()
{ 
 
  motor1.setSpeed(speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
void backright()
{ 
 
  motor1.setSpeed(speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speeed/4); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speeed/4); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
void backleft()
{ 
 
  motor1.setSpeed(speeed/4); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speeed/4); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(speeed); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(speeed); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}

void hl()
{
  digitalWrite(2,HIGH);
}
void hloff()
{
  digitalWrite(2,LOW);
}
void bl()
{
  digitalWrite(13,HIGH);
}
void bloff()
{
  digitalWrite(13,LOW);
}
void horn()
{
  digitalWrite(10,HIGH);
}
void hornoff()
{
  digitalWrite(10,LOW);
}
