#include <M5StickCPlus2.h>

int buttonPresses = 0;
int boredomPoints = 0;

void playPointSound() {
  StickCP2.Speaker.tone(1000, 100);
  delay(120);
  StickCP2.Speaker.tone(1500, 100);
  delay(120);
  StickCP2.Speaker.tone(2000, 200);
}

void flashIR() {
  pinMode(9, OUTPUT);

  for (int i = 0; i < 5; i++) {
    digitalWrite(9, HIGH);
    delayMicroseconds(13);
    digitalWrite(9, LOW);
    delayMicroseconds(13);
  }
}

void setup() {
  auto cfg = M5.config();
  StickCP2.begin(cfg);

  StickCP2.Display.setRotation(1);
  StickCP2.Display.fillScreen(BLACK);

  pinMode(9, OUTPUT);

  randomSeed(millis());
}

void loop() {
  M5.update();

  
  if (M5.BtnA.wasPressed()) {
    buttonPresses++;

    StickCP2.Speaker.tone(2000, 100);

    flashIR();

    if (random(1, 101) <= 5) {
      boredomPoints++;
      playPointSound();
    }
  }

  
  if (M5.BtnB.wasPressed()) {
    buttonPresses = 0;
    boredomPoints = 0;

    StickCP2.Speaker.tone(800, 200);
  }


  StickCP2.Display.fillScreen(BLACK);

  StickCP2.Display.setTextSize(2);

  StickCP2.Display.setCursor(10, 10);
  StickCP2.Display.setTextColor(GREEN);
  StickCP2.Display.println("Boredom Clicker");

  StickCP2.Display.setCursor(10, 45);
  StickCP2.Display.setTextColor(WHITE);
  StickCP2.Display.print("Clicks: ");
  StickCP2.Display.println(buttonPresses);

  StickCP2.Display.setCursor(10, 75);
  StickCP2.Display.setTextColor(RED);
  StickCP2.Display.print("Points: ");
  StickCP2.Display.println(boredomPoints);

  
  StickCP2.Display.setTextSize(1);
  StickCP2.Display.setTextColor(GREEN);
  StickCP2.Display.setCursor(90, 120);
  StickCP2.Display.print("by planeguy");

  delay(20);
}