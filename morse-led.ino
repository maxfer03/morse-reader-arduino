
int led1 = 2;

String morse = ""; 

int timeUnit = 100;

int buzzer = 11;

int soundFreq = 150;



void setup() {
  // put your setup code here, to run once:

     pinMode(led1, OUTPUT);
     pinMode(buzzer, OUTPUT);

        tone(buzzer, soundFreq);
        delay(timeUnit);
        noTone(buzzer);

     
     Serial.begin(9600);
     
     
}

void loop() {
  Serial.println("Enter morse code:");
  while(Serial.available() == 0) {}
  morse = Serial.readString();
  for(int x = 0 ; x < morse.length() -1; x++){
    switch(morse[x]){
      case '.':
        digitalWrite(led1, HIGH);
        tone(buzzer, soundFreq);
        delay(timeUnit);
        digitalWrite(led1, LOW);
        noTone(buzzer);
        break;
      case '-':
        digitalWrite(led1, HIGH);
        tone(buzzer, soundFreq);
        delay(timeUnit * 3);
        noTone(buzzer);
        digitalWrite(led1, LOW);
        break;
      case ' ':
        delay(timeUnit * 3);
        break;
      case '/':
        delay(timeUnit * 7);
        break;
      default:
        Serial.println(' ');
        Serial.print("ERROR AT CHAR ");
        Serial.print(x);
        Serial.println(' ');
        break;
      }
    
    
    delay(timeUnit);
    }
}
  
  
      
      
      
