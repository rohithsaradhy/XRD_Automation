//Equation got from Calibrating is time=13370*angle-3874 ms.
const int PushBtn=8,Motor_selector=9,FlipSwt=10;
float inp=0,motor;
long start_time,stop_time;
void setup(){
  //Setting up the pins for controlling the table
  pinMode(PushBtn,OUTPUT);//RY4
  pinMode(Motor_selector,OUTPUT);//RY2
  pinMode(FlipSwt,OUTPUT);//RY1 & RY3
  digitalWrite(Motor_selector,0);
  digitalWrite(FlipSwt,0);
  digitalWrite(PushBtn,0);
  Serial.begin(9600);
}
void loop(){
 while (Serial.available()==0);
 motor=Serial.parseFloat();
 if (motor==1){digitalWrite(Motor_selector,1);}//RY2
 else{digitalWrite(Motor_selector,0);}//RY2
 
 while (Serial.available()==0);
 
  inp=Serial.parseFloat();
 
 
 
  if (inp>0)
  {
    digitalWrite(FlipSwt,0);// RY1 & RY3
    digitalWrite(PushBtn,1);// RY4
    long t;
    t= abs(13111.8 * inp);
    Serial.print(inp);
    Serial.println();
    delay(t);
    digitalWrite(PushBtn,0);
  
  }
  
  if (inp<0)
  {
    digitalWrite(FlipSwt,1);RY1 & RY3
    digitalWrite(PushBtn,1);RY4
    long t;
    t= abs(13111.8 * inp);
    Serial.print(inp);
    Serial.println();
    delay(t);
    digitalWrite(PushBtn,0);
  }
  
  if (inp==0)
  {
    digitalWrite(PushBtn,0);
  }
  
  
}
