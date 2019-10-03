byte flag2=0,flag3=0,flag4=0,flag5=0;
uint32_t A=1;
uint32_t B=2;
uint32_t C=3;
uint32_t D=4;
#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() {
  if (irrecv.decode(&results)) 
  {
    if(results.value!=4294967295)
    {
    Serial.println(results.value, DEC);
    
    
    //A
    if((results.value==A)&&(flag2==0))        
    {
    digitalWrite(2,HIGH);
    flag2=1;
    results.value=0;
    }
    if((results.value==A)&&(flag2==1))       
    {
    digitalWrite(2,LOW);
    flag2=0;
    results.value=0;
    }


    
    
    
    //B
    if((results.value==B)&&(flag3==0))       
    {
    digitalWrite(3,HIGH);
    flag3=1;
    results.value=0;
    }
    if((results.value==B)&&(flag3==1))      
    {
    digitalWrite(3,LOW);
    flag3=0;
    results.value=0;
    }


    
    
    
    //C
    if((results.value==C)&&(flag4==0))     
    {
    digitalWrite(4,HIGH);
    flag4=1;
    results.value=0;
    }
    if((results.value==C)&&(flag4==1))    
    {
    digitalWrite(4,LOW);
    flag4=0;
    results.value=0;
    }


    
    
    
    //D
    if((results.value==D)&&(flag5==0))     
    {
    digitalWrite(5,HIGH);
    flag5=1;
    results.value=0;
    }
    if((results.value==D)&&(flag5==1))     
    {
    digitalWrite(5,LOW);
    flag5=0;
    results.value=0;
    }


    
    }
    irrecv.resume();
  }
}
