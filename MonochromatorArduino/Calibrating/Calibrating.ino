const int PushBtn=10,PushBtn_G=8,FlipSwt=11,FlipSwt_G=9;
int inp=0;
long start_time,stop_time;
void setup(){
  //Setting up the pins for controlling the table
  pinMode(PushBtn,OUTPUT);
  pinMode(PushBtn_G,OUTPUT);
  pinMode(FlipSwt,OUTPUT);
  pinMode(FlipSwt_G,OUTPUT);
  digitalWrite(PushBtn_G,0);
  digitalWrite(FlipSwt_G,0);
  Serial.begin(9600);
}
void loop(){
 
  
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
