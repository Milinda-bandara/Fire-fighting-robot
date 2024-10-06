#include <Servo.h>    // servo motor library
#include <AFMotor.h>    //for motor shild

//motors define
AF_DCMotor f_left(1);  //M1
AF_DCMotor f_right(2); //M2
AF_DCMotor r_right(3); //M3
AF_DCMotor r_left(4);  //M4

//ir sensors define
#define ir_r A1
#define ir_f A2
#define ir_l A3
int right , front , left;

//water pump
#define pump A4

//create servo object
Servo servo;


int  buzzer = 2;



void setup() {
 Serial.begin(9600);
 
  //pin for ir
  pinMode(ir_r,INPUT);
  pinMode(ir_f,INPUT);
  pinMode(ir_l,INPUT);
 

  //servo motor
  servo.attach(10);
  servo.write(90);

  for (int angle = 90; angle <= 140; angle += 5)  {
   servo.write(angle);  }
  for (int angle = 140; angle >= 40; angle -= 5)  {
   servo.write(angle); }
  for (int angle = 40; angle <= 95; angle += 5)  {
   servo.write(angle); }

  //pump
  pinMode(pump,OUTPUT);

 

  //motor speed defind
  f_left.setSpeed(50);
  f_right.setSpeed(50);
  r_right.setSpeed(50);
  r_left.setSpeed(50);


  //buzzer
  pinMode(buzzer,OUTPUT);

}

void loop() {

   right = analogRead(ir_r);
   front = analogRead(ir_f);
   left = analogRead(ir_l);


   Serial.print(right);
   Serial.print("\t");
   Serial.print(front);
   Serial.print("\t");
   Serial.print(left);

   delay(50);

   if(right<250){
    
    Stop();
    tone(2,2000);
    digitalWrite(pump,1);
    
    for(int angle = 90; angle >= 40; angle -= 3){
    servo.write(angle); 
    delay(30);
    }
    for(int angle = 40; angle <= 90; angle += 3){
    servo.write(angle);
    delay(30);
    }
  
    }
   else if(front<350){
      
    Stop();
    tone(2,2000);
    digitalWrite(pump,1); 

    for(int angle = 90; angle <= 140; angle += 3){
    servo.write(angle);
    delay(30);
    }
    for(int angle = 140; angle >= 40; angle -= 3){
    servo.write(angle); 
    delay(30); 
    }
    for(int angle = 40; angle <= 90; angle += 3){
    servo.write(angle);
    delay(30);
    } 
      
    }
   else if(left<250){

    Stop();
    tone(2,2000);
    digitalWrite(pump,1);
    
    for(int angle = 90; angle <= 140; angle += 3){
    servo.write(angle); 
    delay(30);
    }
    for(int angle = 140; angle >= 90; angle -= 3){
    servo.write(angle); 
    delay(30);
    } 
    
    }
   else if(right>=251 && right<=700){

    digitalWrite(pump,0);
    Backward();
    delay(100);
    moveRight();
    delay(200);
    
    }
   else if(front>=251 && front<=800){
    
    digitalWrite(pump,0);
    Forward();
    
    }
   else if(left>=251 && left<=700){

    digitalWrite(pump,0);
    Backward();
    delay(100);
    moveLeft();
    delay(200);
    
    }
   else{
    
    digitalWrite(pump,0);
    Stop();
   
    }
   
  delay(10);

 
  }




  

void sound(){
 digitalWrite(buzzer,HIGH);
 delay(1000);
 digitalWrite(buzzer,LOW);
  
  }

void Stop(){
   f_left.run(RELEASE);
   f_right.run(RELEASE);
   r_right.run(RELEASE);
   r_left.run(RELEASE);
}
void Forward(){
   
   f_left.run(FORWARD);
   f_right.run(FORWARD);
   r_right.run(FORWARD);
   r_left.run(FORWARD);
    
    }
void Backward(){
  
   f_left.run(BACKWARD);
   f_right.run(BACKWARD);
   r_right.run(BACKWARD);
   r_left.run(BACKWARD);
   
        }
void moveRight(){
  
   f_left.run(FORWARD);
   f_right.run(RELEASE);
   r_right.run(RELEASE);
   r_left.run(FORWARD);   
   
  }
 void moveLeft(){
  
   f_left.run(RELEASE);
   f_right.run(FORWARD);
   r_right.run(FORWARD);
   r_left.run(RELEASE);
   
    }
    
void sharpRight(){

   f_left.run(FORWARD);
   f_right.run(BACKWARD);
   r_right.run(BACKWARD);
   r_left.run(FORWARD);
    
}
void sharpLeft(){
  
   f_left.run(BACKWARD);
   f_right.run(FORWARD);
   r_right.run(FORWARD);
   r_left.run(BACKWARD);
  
}





        


  
