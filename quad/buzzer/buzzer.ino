// buzzer pin
int buzzerPin1 = 13;
int delayInMicrosec = 50;

void setup() {
  // to capture user input to toggle buzzer
  Serial.begin(9600);
  Serial.setTimeout(500);
  
  // buzzer
  pinMode(buzzerPin1, OUTPUT);
  digitalWrite(buzzerPin1, LOW);
}

void loop() {
  // wait for some input
  if (Serial.available() > 0) {
    int numClicks = Serial.parseInt(); // NUMBER OF CLICKS
    numClicks = normalize(numClicks);
    if (numClicks == 0) {
      Serial.println("Doing no clicks, pin is LOW\n");
      digitalWrite(buzzerPin1, LOW);
    }
    else {
      Serial.print("Doing " + String(numClicks) + " clicks\n");
      for (int i = 0; i < numClicks; i++) {
        doClick(buzzerPin1, delayInMicrosec);
      }
    }
  }
}

int normalize(int userInput) {
  // do not trust the user
  if (userInput < 0) {
    return 0; 
  }
  else if (userInput > 80) {
    return 80;
  }
  else {
    return userInput;
  }
}

void doClick(int pinNumber, int delayInMicrosec) {
  digitalWrite(pinNumber, HIGH);
  delay(delayInMicrosec);
  digitalWrite(pinNumber, LOW);
}
