
int yellow = 13;
int red = 12;
int blue = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0); 
  
  if (value > 500) {
    Serial.println("Chuvada");
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(blue,LOW);}
   else if ((value > 300) && (value <= 500)); {
    Serial.println("Chuva molha parvos");
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    }
   else{
    Serial.println("Vamos dar um passeio");
    digitalWrite (blue,HIGH);
    digitalWrite (red,LOW);
    digitalWrite (yellow,LOW);
    delay(100);}
    
 
}
