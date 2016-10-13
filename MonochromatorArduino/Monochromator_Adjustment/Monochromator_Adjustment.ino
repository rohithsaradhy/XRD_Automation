
//This Programme is written by Rohith Saradhy

const int xpin = A3;
 int input = 5;
void setup()
{
 digitalWrite(2,1);
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(6, OUTPUT); 
digitalWrite(11,0);
digitalWrite(6,0);
digitalWrite(7,0);


}

void loop()
{
  analogReference(EXTERNAL);
  int ov1=0;
  //Serial.print(analogRead(xpin));
  //Serial.print("\t");
 ov1 = map(analogRead(xpin), 503, 521, 5, -5);
  Serial.print(ov1); 
 Serial.println();
 if(Serial.available()>0)
 {
  input =Serial.parseInt();
  ov1 = map(analogRead(xpin), 503, 521, 5, -5);
 

 
 
  while(input!=ov1){
ov1 = map(analogRead(xpin), 503, 521, 5, -5);
 Serial.print(ov1); 
 Serial.println();
 delay(1000);
 //decrease
 
 
 if(input<ov1)
 {
 digitalWrite(12,1);
 digitalWrite(7,1);
 
 }
 //increase
 else if(input>ov1)
 {
   digitalWrite(12,0);
 digitalWrite(7,1);
   
 }
 //stop
 else if(input==ov1)
 {
   delay(4500);
   digitalWrite(7,0);
   //resetting
   digitalWrite(2,0);
   break;
 }
 
 

 }
 }

 
 if(input==ov1)
 {
   digitalWrite(7,0);
   
 }
 
 
 
 /*
 //Calibratin Par
 //decrease
 if(input==1)
 {
 digitalWrite(12,1);
 digitalWrite(7,1);
 
 }
 //increase
 else if(input==-1)
 {
   digitalWrite(12,0);
 digitalWrite(7,1);
   
 }
 //stop
 else if(input==0)
 {
   digitalWrite(7,0);
 }
 */
  
 delay(1000);
}
