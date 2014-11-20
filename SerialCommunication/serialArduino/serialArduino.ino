#define IRSENSOR 0



 float raw;
 float volt;
 int distance;
void setup() {
 pinMode (IRSENSOR, INPUT);
  
  Serial.begin(9600);
  
}

void loop() {
 raw=analogRead(IRSENSOR);
 volt=map(raw, 0, 1023, 0, 5000);
 distance=(21.61/(volt-0.1696))*1000; 
  
 
     Serial.write(distance);
      delay(20); // make sure we give it a second to move
      


  
  
}
