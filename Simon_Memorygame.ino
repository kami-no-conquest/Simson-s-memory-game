#include <Tone.h>
Tone speakerpin;
int starttune[] = { NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_C4,
                    NOTE_F4, NOTE_C4, NOTE_F4, NOTE_G4, NOTE_F4,
                    NOTE_E4, NOTE_F4, NOTE_G4 };
int duration[] = { 100, 200, 100, 200, 100, 400, 100, 100, 100, 100,
                   200, 100, 500 };
int note[] = { NOTE_C4, NOTE_C4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5 };
int duration2[] = { 100, 100, 100, 300, 100, 300 };
int button[] = { 2, 3, 4, 5 };
int ledpin[] = { 8, 9, 10, 11 };
int turn = 0;
int buttonstate = 0;
int randomArray[100];
int inputArray[100];

void setup() {
  Serial.begin(9600);
  speakerpin.begin(12);

  for (int x = 0; x < 4; x++) {
    pinMode(ledpin[x], OUTPUT);
  }

  for (int x = 0; x < 4; x++) {
    pinMode(button[x], INPUT);
    digitalWrite(button[x], HIGH);
  }
  randomSeed(analogRead(0));
  for (int thisNote = 0; thisNote < 13; thisNote++) {
    speakerpin.play(starttune[thisNote]);
    if (thisNote == 0 || thisNote == 2 || thisNote == 4 || thisNote == 6) {
      digitalWrite(ledpin[0], HIGH);
    }
    if (thisNote == 1 || thisNote == 3 || thisNote == 5 || thisNote == 7 || thisNote == 9 || thisNote == 11) {
      digitalWrite(ledpin[1], HIGH);
    }
    if (thisNote == 8 || thisNote == 12) {
      digitalWrite(ledpin[2], HIGH);
    }
    if (thisNote == 10) {
      digitalWrite(ledpin[3], HIGH);
    }
    delay(duration[thisNote]);
    speakerpin.stop();
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
    delay(25);
  }
  delay(1000);
}

void loop() {
  //Array player would match
  for (int y = 0; y <= 99; y++) {
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], HIGH);
    for (int thisNote = 0; thisNote < 6; thisNote++) {
      speakerpin.play(note[thisNote]);
      delay(duration2[thisNote]);
      speakerpin.stop();
      delay(25);
    }

    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
    delay(1000);

    for (int y = turn; y <= turn; y++) {
      Serial.println("");
      Serial.print("Turn: ");
      Serial.print(y);
      Serial.println("");
      randomArray[y] = random(1, 5);

      for (int x = 0; x <= turn; x++) {
        Serial.print(randomArray[x]);

        for (int y = 0; y < 4; y++) {
          if (randomArray[x] == 1 && ledpin[y] == 8) {
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_G3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
          if (randomArray[x] == 2 && ledpin[y] == 9) {
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_A3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
          if (randomArray[x] == 3 && ledpin[y] == 10) {
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_B3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
          if (randomArray[x] == 4 && ledpin[y] == 11) {
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_C4, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
        }
      }
    }
    input();
  }
}
void input() {
  for (int x = 0; x <= turn;) {
    for (int y = 0; y < 4; y++) {
      buttonstate = digitalRead(button[y]);
      if (buttonstate == LOW && button[y] == 2) {
        digitalWrite(ledpin[0], HIGH);
        speakerpin.play(NOTE_G3, 100);
        delay(200);
        digitalWrite(ledpin[0], LOW);
        inputArray[x] = 1;
        delay(250);
        Serial.print(" ");
        Serial.print(1);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }
      if (buttonstate == LOW && button[y] == 3) {
        digitalWrite(ledpin[1], HIGH);
        speakerpin.play(NOTE_A3, 100);
        delay(200);
        digitalWrite(ledpin[1], LOW);
        inputArray[x] = 2;
        delay(250);
        Serial.print(" ");
        Serial.print(2);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }
      if (buttonstate == LOW && button[y] == 4) {
        digitalWrite(ledpin[2], HIGH);
        speakerpin.play(NOTE_B3, 100);
        delay(200);
        digitalWrite(ledpin[2], LOW);
        inputArray[x] = 3;
        delay(250);
        Serial.print(" ");
        Serial.print(3);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }
      if (buttonstate == LOW && button[y] == 5) {
        digitalWrite(ledpin[3], HIGH);
        speakerpin.play(NOTE_C4, 100);
        delay(200);
        digitalWrite(ledpin[3], LOW);
        inputArray[x] = 4;
        delay(250);
        Serial.print(" ");
        Serial.print(4);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }
    }
  }
  delay(500);
  turn++;
}

void fail() {
  for (int y = 0; y <= 2; y++) {
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
    digitalWrite(ledpin[2], HIGH);
    digitalWrite(ledpin[3], HIGH);
    speakerpin.play(NOTE_G3, 300);
    delay(200);
    digitalWrite(ledpin[0], LOW);
    digitalWrite(ledpin[1], LOW);
    digitalWrite(ledpin[2], LOW);
    digitalWrite(ledpin[3], LOW);
    speakerpin.play(NOTE_C3, 300);
    delay(200);
  }
  delay(500);
  turn = -1;
}