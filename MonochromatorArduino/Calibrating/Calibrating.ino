const int PushBtn=8,Motor_selector=9,FlipSwt=10;
int inp=0,motor;
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
 if (motor==1){digitalWrite(Motor_selector,1);}
 else{digitalWrite(Motor_selector,0);}
  
 while (Serial.available()==0);
 
  inp=Serial.parseInt();
 
 
 
  if (inp==0)
  {
    digitalWrite(PushBtn,0);
    stop_time=millis()-start_time;
    Serial.println(stop_time);
    
  }
  
  if (inp==-1)
  {
    digitalWrite(FlipSwt,1);
    digitalWrite(PushBtn,1);
    start_time=millis();
  }
  
  if (inp==1)
  {
    digitalWrite(FlipSwt,0);
    digitalWrite(PushBtn,1);
    start_time=millis();
  }
  
  
}
