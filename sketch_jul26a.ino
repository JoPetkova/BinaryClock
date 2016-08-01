
int second = 0, minute = 0, hour = 0;
int m = 0;
int h = 0;
int buttonMinute = 46, buttonHour = 48;
int buttStM, buttStH;
bool flag = 0;
int ledStatus, i;
int switchButton = 50;
int piezo = 52;


void setup() {

  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);

  pinMode(piezo, OUTPUT);

  pinMode(switchButton, INPUT);
  pinMode(buttonMinute, INPUT);
  pinMode(buttonHour, INPUT);

}


void loop() {

  static unsigned long lastTick = 0;

  if (millis() - lastTick >= 1000) {
    lastTick = millis();
    second++;
    if (flag == 1) {
      digitalWrite(14, HIGH);
      flag = 0;
    }
    else {
      digitalWrite(14, LOW);
      flag = 1;
    }
  }

  if (second >= 60) {
    minute++;
    second = 0;
  }

  if (minute >= 60) {
    hour++;
    minute = 0;
  }

  if (hour >= 24) {
    hour = 0;
    minute = 0;
  }


  ledStatus = digitalRead(switchButton);

  if (ledStatus == LOW) {
    for (i = 1; i <= 14; i++) {
      digitalWrite(i, LOW);
      digitalWrite(piezo, LOW);
    }
  }
  else {

    m = minute % 10;

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 9) {
      digitalWrite(1, HIGH);
    } else digitalWrite(1, LOW);
    if (m == 2 || m == 3 || m == 6 || m == 7) {
      digitalWrite(2, HIGH);
    } else digitalWrite(2, LOW);
    if (m == 4 || m == 5 || m == 6 || m == 7) {
      digitalWrite(3, HIGH);
    } else digitalWrite(3, LOW);
    if (m == 8 || m == 9) {
      digitalWrite(4, HIGH);
    } else digitalWrite(4, LOW);

    if ((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) || (minute >= 50 && minute < 60)) {
      digitalWrite(5, HIGH);
    } else digitalWrite(5, LOW);
    if (minute >= 20 && minute < 40) {
      digitalWrite(6, HIGH);
    } else digitalWrite(6, LOW);
    if (minute >= 40 && minute < 60) {
      digitalWrite(7, HIGH);
    } else digitalWrite(7, LOW);

    if (minute == 0) {
      if (second == 1) {
        digitalWrite(piezo, HIGH);
      }
      if (second == 2) {
        digitalWrite(piezo, LOW);
      }
      if (second == 3) {
        digitalWrite(piezo, HIGH);
      }
      if (second == 4) {
        digitalWrite(piezo, LOW);
      }
    }


    h = hour % 10;

    if (h == 1 || h == 3 || h == 5 || h == 7 || h == 9) {
      digitalWrite(8, HIGH);
    } else digitalWrite(8, LOW);
    if (h == 2 || h == 3 || h == 6 || h == 7) {
      digitalWrite(9, HIGH);
    } else digitalWrite(9, LOW);
    if (h == 4 || h == 5 || h == 6 || h == 7) {
      digitalWrite(10, HIGH);
    } else digitalWrite(10, LOW);
    if (h == 8 || h == 9) {
      digitalWrite(11, HIGH);
    } else digitalWrite(11, LOW);

    if (hour >= 10 && hour < 20) {
      digitalWrite(12, HIGH);
    } else digitalWrite(12, LOW);
    if (hour >= 20 && hour < 24) {
      digitalWrite(13, HIGH);
    } else digitalWrite(13, LOW);

  }


  buttStM = digitalRead(buttonMinute);
  if (buttStM == HIGH) {
    minute++;
    second = 0;
    delay(250);
  }
  buttStH = digitalRead(buttonHour);
  if (buttStH == HIGH) {
    hour++;
    second = 0;
    delay(250);
  }

}

