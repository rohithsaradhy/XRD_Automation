//Equation got from Calibrating is time=13370*angle-3874 ms.
const int PushBtn=10,PushBtn_G=8,FlipSwt=11,FlipSwt_G=9;
float inp=0;
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
 
  inp=Serial.parseFloat();
 
 
 
  if (inp>0)
  {
    digitalWrite(FlipSwt,0);
    digitalWrite(PushBtn,1);
    long t;
    t= abs(13111.8 * inp);
    Serial.print(inp);
    Serial.println();
    delay(t);
    digitalWrite(PushBtn,0);
  
  }
  
  if (inp<0)
  {
    digitalWrite(FlipSwt,1);
    digitalWrite(PushBtn,1);
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
