void setup()
 {
//Starting a serial communication of baud rate 9600
Serial.begin(9600);

//initializing the pins being utilised
pinMode(7,1);
pinMode(8,1);
pinMode(9,1);
pinMode(10,1);

}

void loop()
{
   // waiting for user to input some character through
   //serial port
  while(Serial.available()!=0)
  //declaring time between each step
  int timedelay = 50;
  //declaring number of steps to be moved
  int steps=50;
  // for clockwise rotation

  for(int i =0;i<steps;i++)
 	 {
// creating a ttl pulse
    digitalWrite(7,1);
    digitalWrite(8,0);
    digitalWrite(9,0);
    digitalWrite(10,0);
    delay(timedelay);
    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,1);
    digitalWrite(10,0);
    delay(timedelay);
    digitalWrite(7,0);
    digitalWrite(8,1);
    digitalWrite(9,0);
    digitalWrite(10,0);
    delay(timedelay);
    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,0);
    digitalWrite(10,1);
    delay(timedelay);
    digitalWrite(10,0);
  }

  //anticlockwise pulse

  for(int i =0;i<steps;i++)
  {
    // creating a ttl pulse

    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,1);
    digitalWrite(10,0);
    delay(timedelay);
    digitalWrite(7,1);
    digitalWrite(8,0);
    digitalWrite(9,0);
    digitalWrite(10,0);
    delay(timedelay);
    delay(timedelay);
    digitalWrite(7,0);
    digitalWrite(8,0);
    digitalWrite(9,0);
    digitalWrite(10,1);
    delay(timedelay);
    digitalWrite(10,0);
    digitalWrite(7,0);
    digitalWrite(8,1);
    digitalWrite(9,0);
    digitalWrite(10,0);

  }

}
