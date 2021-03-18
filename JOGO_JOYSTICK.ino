//Joystick variables
int sX = A0;
int sY = A1;
int sSX;
int sSY;
int sS;

//Game variables
int rNum;
int wins = 0;
int hightScore = 0;

const int easy = 1000;
const int medium = 500;
const int hard = 325;
const int stupid = 250;

int ledPins[] = {5,6,7,8,9,10};
int pinCount = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sX, INPUT);
  pinMode(sY, INPUT);

  for (int thisPin = 0; thisPin < pinCount; thisPin++) { //assigning all the pins as outputs in a for loop
    pinMode(ledPins[thisPin], OUTPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:

  rNum = random(4);
  delay(1000);
  digitalWrite(ledPins[rNum], HIGH);
  delay(medium); //dificuldade 

  sSX = analogRead(sX);
  delay(100);
  sSY = analogRead(sY);

  sS = 0;
  switch (sSX) {
    case 0:
    sS = 1; //left
    break;
    case 1023:
    sS = 2; //right
    break; 
  }
  switch (sSY) {
    case 0:
    sS = 3; //up
    break;
    case 1023:
    sS = 4; //down
    break; 
  }

  digitalWrite(ledPins[rNum], LOW);
  if ( sS-1 == rNum)
  {
    wins++;
    for (int k=0; k<=3; k++){
      digitalWrite(ledPins[4], HIGH);
      delay(50);
      digitalWrite(ledPins[4], LOW);
      delay(50);
      }
    }
else
  {
    if (wins>highScore) { //if the consecutive wins are more than the previous highscore, the new highscore is set.
        highScore=wins;
        wins=0;
    }
    for (int i=0; i<=3; i++) {       //blinking red light indicating incorrect choice
      digitalWrite(ledPins[5], HIGH);
      delay(50);
      digitalWrite(ledPins[5], LOW);
      delay(50);
    }
    for (int w=0; w<highScore; w++) { //displaying via counting and blinking the high score on a yellow bulb.
        digitalWrite(ledPins[6], HIGH);
        delay(200);
        digitalWrite(ledPins[6], LOW);
        delay(200);
    }  
  }  
  }
