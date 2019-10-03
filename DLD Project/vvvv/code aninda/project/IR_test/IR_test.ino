byte flag=0;
#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(13,OUTPUT);
}
void loop() {
  if (irrecv.decode(&results)) 
  {
    if(results.value!=4294967295)
    {
    Serial.println(results.value, DEC);
    if((results.value==948321216)&&(flag==0))
    {
    digitalWrite(13,HIGH);
    flag=1;
    results.value=0;
    }
    if((results.value==948321216)&&(flag==1))
    {
    digitalWrite(13,LOW);
    flag=0;
    results.value=0;
    }
    }
    irrecv.resume();
  }
}
