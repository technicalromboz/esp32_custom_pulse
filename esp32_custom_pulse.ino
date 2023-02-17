
const int LEDPIN1 = 15; //led 1 as output
const int LEDPIN2 = 21; // led 2 as output
const int PushButton1 = 22; //pushbutton 1
const int PushButton2 = 23; // pushbutton 2

const int b=100; // intialize *b* value from calculation 
const int d=2000; // intialize *d* value from calculation 

void setup() // This Setup function is used to initialize everything 
{  
Serial.begin(9600);        // baud rate 9600
pinMode(LEDPIN1, OUTPUT);  // This statement will declare pin 15 as digital output 
pinMode(LEDPIN2, OUTPUT);  // This statement will declare pin 21 as digital output 
pinMode(PushButton1, INPUT); // This statement will declare pin 22 as digital input 
pinMode(PushButton2, INPUT); // This statement will declare pin 23 as digital output 
}

void loop()
{ 
  if(digitalRead(PushButton1)==LOW) // when button 1 not pressed pulse on
  { 
    if(digitalRead(PushButton2)==LOW) // when button 2 not pressed (NORMAL MODE)
    {
     int a=1000;                    //intialize *a* from calculation
     Serial.println("NORMAL MODE"); // serial print normal mode
     digitalWrite(LEDPIN2, HIGH);   // signal b (led 2 HIGH)
     delayMicroseconds(50);            
     digitalWrite(LEDPIN2, LOW);   // signal b (led 2 LOW)
     for(int i = 1; i<=6; i++)     // loop until 6 pulse 
     {
      digitalWrite(LEDPIN1, HIGH); //high pulse for a
      delayMicroseconds(a);
      digitalWrite(LEDPIN1, LOW); //low pulse for a
      delayMicroseconds(b);       // delayMicroseconds for b
      Serial.println(a);          //print a value 
      a=a+50;                     // increment a by 50 before exit loop
     }
    digitalWrite(LEDPIN1, LOW); //delayMicroseconds of d 
    delayMicroseconds(d);
    digitalWrite(LEDPIN2, HIGH); // signal b (led 2 high)
    delayMicroseconds(50);
    digitalWrite(LEDPIN2, LOW);  //signal b (led 2 low)
    } 
    else
    {
     Serial.println("Mode 1"); 
     int a=1000;
     digitalWrite(LEDPIN2, HIGH);
     delayMicroseconds(50);
     digitalWrite(LEDPIN2, LOW); 
     for(int i = 1; i<=3; i++)
     {
     digitalWrite(LEDPIN1, HIGH);
     delayMicroseconds(a);
     digitalWrite(LEDPIN1, LOW);
     delayMicroseconds(b);
     Serial.println(a);
     a=a+50; 
     } 
     digitalWrite(LEDPIN1, LOW); //delayMicroseconds of d
     delayMicroseconds(2000);
     digitalWrite(LEDPIN2, HIGH); // signal b 
     delayMicroseconds(50);
     digitalWrite(LEDPIN2, LOW); 
    }
   }
   else // if button 1 pressed off all pulse
   {
   digitalWrite(LEDPIN1,LOW);
   digitalWrite(LEDPIN2,LOW);
   }

}
