

int pinVermelho = 12;
int pinAmarelo = 11;
int pinVerde = 10;
int pinBotao = 4;

int faseSemaforo;

int estadoBotao;

void setup() {
  // put your setup code here, to run once:

    pinMode(pinVerde, OUTPUT);
    pinMode(pinAmarelo, OUTPUT);
    pinMode(pinVerde, OUTPUT);
    pinMode(pinBotao, INPUT);

    faseSemaforo = 1;
    

}

void loop() {
  // put your main code here, to run repeatedly:

estadoBotao = digitalRead(pinBotao);

   if(estadoBotao == HIGH) {

   if(faseSemaforo < 3){
     faseSemaforo = faseSemaforo + 1;
   } else {
    faseSemaforo = 1;
   }
     
  }

  if(faseSemaforo == 1) {
    digitalWrite(pinVerde, HIGH);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, LOW);
  }

  if(faseSemaforo == 2) {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, HIGH);
    digitalWrite(pinVermelho, LOW);
  }

  if(faseSemaforo == 3) {
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAmarelo, LOW);
    digitalWrite(pinVermelho, HIGH);
  }
  delay(150);
}