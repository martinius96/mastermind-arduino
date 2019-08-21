/*|----------------------------------------------------------------------------|*/
/*|SKETCH PRE MASTERMIND IMPLEMENTACIU                                         |*/
/*|VYHOTOVIL: MARTIN CHLEBOVEC                                                 |*/
/*|PODPOR PROJEKT PRE VIAC VARIANT, SUPPORT: https://paypal.me/chlebovec       |*/
/*|Doska: Arduino Uno / AtMega328P                                             |*/
/*|MAXIMALNY POCET POKUSOV: 10                                                 |*/
/*|POCET VSTUPOV: 5X PUSHBUTTON - SPINACIE TLACIDLA                            |*/
/*|VYGENEROVANE 4-CISLIE: KAZDE CISLO JE ROZNE V ROZSAHU 0-9 BEZ OPAKOVANIA!   |*/
/*|PRE ZOBRAZENIE VYGENEROVANEHO CISLA POUZITE DEBUG (ODKOMENTOVAT)            |*/
/*|----------------------------------------------------------------------------|*/
/*|VYSVETLIVKY PRE ZNAČKY NA DISPLEJI:                                         |*/
/*| C --> uhadnute cislo na inej pozicii                                       |*/
/*| = --> uhadnute cislo aj s poziciou (SPRAVNE CISLO!)                        |*/
/*| - --> neuhadnute cislo, ani pozicia                                        |*/
/*|----------------------------------------------------------------------------|*/

//#define DEBUG //odkomentuj pre DEBUG INFO (ZOBRAZENIE HLADANEHO CISLA)
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20, 4);

const int buttonPin1 = 6;
const int buttonPin2 = 5;
const int buttonPin3 = 4;
const int buttonPin4 = 3;
const int buttonPin5 = 2;

int cislo1 = 0;
int cislo2 = 0;
int cislo3 = 0;
int cislo4 = 0;

int cielovecislo1 = 0;
int cielovecislo2 = 0;
int cielovecislo3 = 0;
int cielovecislo4 = 0;

int buttonState1 = HIGH;
int buttonState2 = HIGH;
int buttonState3 = HIGH;
int buttonState4 = HIGH;
int buttonState5 = HIGH;

int lastButtonState1 = HIGH;
int lastButtonState2 = HIGH;
int lastButtonState3 = HIGH;
int lastButtonState4 = HIGH;
int lastButtonState5 = HIGH;

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;
unsigned long lastDebounceTime5 = 0;
unsigned long debounceInterval = 50;
int pokus = 0;

void setup() {
  lcd.begin(); //incializacia displeja na I2C zbernici
  lcd.backlight(); //zapnutie podsvietenia
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);
  randomSeed(analogRead(0));
  lcd.setCursor(0, 0); //nastav kurzor pre zapis na 1. riadok, 1. stlpec
  lcd.print("ZADANE CISLO: 0000");
  generuj_cisla();
#ifdef DEBUG
  lcd.setCursor(0, 2);
  lcd.print("DEBUG ON:");
  lcd.setCursor(0, 3);
  lcd.print("HLADANE CISLO: ");
  lcd.print(cielovecislo1);
  lcd.print(cielovecislo2);
  lcd.print(cielovecislo3);
  lcd.print(cielovecislo4);
#endif
}

void loop() {
  if (pokus >= 10) {
    lcd.setCursor(0, 2);
    lcd.print("PREHRALI STE!");
    lcd.setCursor(0, 3);
    lcd.print("KONIEC HRY          ");
    while (1);
  } else {
    int reading1 = digitalRead(buttonPin1);
    int reading2 = digitalRead(buttonPin2);
    int reading3 = digitalRead(buttonPin3);
    int reading4 = digitalRead(buttonPin4);
    int reading5 = digitalRead(buttonPin5);

    if (reading1 != lastButtonState1) {
      lastDebounceTime1 = millis();
    }

    if (reading2 != lastButtonState2) {
      lastDebounceTime2 = millis();
    }

    if (reading3 != lastButtonState3) {
      lastDebounceTime3 = millis();
    }

    if (reading4 != lastButtonState4) {
      lastDebounceTime4 = millis();
    }

    if (reading5 != lastButtonState5) {
      lastDebounceTime5 = millis();
    }

    if ((millis() - lastDebounceTime1) > debounceInterval) {
      if (reading1 != buttonState1) {
        buttonState1 = reading1;
        if (buttonState1 == HIGH) {
          cislo1++;
          if (cislo1 > 9) {
            cislo1 = 0;
          }
        }
      }
      updateLCD();
    }

    if ((millis() - lastDebounceTime2) > debounceInterval) {
      if (reading2 != buttonState2) {
        buttonState2 = reading2;
        if (buttonState2 == HIGH) {
          cislo2++;
          if (cislo2 > 9) {
            cislo2 = 0;
          }
        }
      }
      updateLCD();
    }

    if ((millis() - lastDebounceTime3) > debounceInterval) {
      if (reading3 != buttonState3) {
        buttonState3 = reading3;
        if (buttonState3 == HIGH) {
          cislo3++;
          if (cislo3 > 9) {
            cislo3 = 0;
          }
        }
      }
      updateLCD();
    }

    if ((millis() - lastDebounceTime4) > debounceInterval) {
      if (reading4 != buttonState4) {
        buttonState4 = reading4;
        if (buttonState4 == HIGH) {
          cislo4++;
          if (cislo4 > 9) {
            cislo4 = 0;
          }
        }
      }
      updateLCD();
    }

    if ((millis() - lastDebounceTime5) > debounceInterval) {
      if (reading5 != buttonState5) {
        buttonState5 = reading5;
        if (buttonState5 == HIGH) {
          pokus++;
          updateLCD();
          over_cisla();
          cislo1 = 0;
          cislo2 = 0;
          cislo3 = 0;
          cislo4 = 0;
        }
      }
    }
    lastButtonState1 = reading1;
    lastButtonState2 = reading2;
    lastButtonState3 = reading3;
    lastButtonState4 = reading4;
    lastButtonState5 = reading5;
  }
}

void updateLCD() {
  lcd.setCursor(14, 0);
  lcd.print(cislo1);
  lcd.print(cislo2);
  lcd.print(cislo3);
  lcd.print(cislo4);
  lcd.setCursor(0, 1);
  lcd.print("POKUS: ");
  lcd.print(pokus);
}

void generuj_cisla() {
  cielovecislo1 = random(0, 9);
  cielovecislo2 = random(0, 9);
  while (cielovecislo2 == cielovecislo1) {
    cielovecislo2 = random(0, 9);
  }
  cielovecislo3 = random(0, 9);
  while ((cielovecislo3 == cielovecislo1) || (cielovecislo3 == cielovecislo2)) {
    cielovecislo3 = random(0, 9);
  }
  cielovecislo4 = random(0, 9);
  while ((cielovecislo4 == cielovecislo1) || (cielovecislo4 == cielovecislo2) || (cielovecislo4 == cielovecislo3)) {
    cielovecislo4 = random(0, 9);
  }
}

void over_cisla() {
  if (cislo1 == cielovecislo1) {
    lcd.setCursor(10, 1);
    lcd.print("="); //UHADNUTE CISLO VRATANE POZICIE
  } else if ((cislo1 == cielovecislo2) || (cislo1 == cielovecislo3) || (cislo1 == cielovecislo4)) {
    lcd.setCursor(10, 1);
    lcd.print("C"); //UHADNUTE CISLO BEZ POZICIE
  } else {
    lcd.setCursor(10, 1);
    lcd.print("-"); //NEUHADNUTE CISLO, ANI POZICIA
  }

  if (cislo2 == cielovecislo2) {
    lcd.setCursor(11, 1);
    lcd.print("="); //UHADNUTE CISLO VRATANE POZICIE
  } else if ((cislo2 == cielovecislo1) || (cislo2 == cielovecislo3) || (cislo2 == cielovecislo4)) {
    lcd.setCursor(11, 1);
    lcd.print("C"); //UHADNUTE CISLO BEZ POZICIE
  } else {
    lcd.setCursor(11, 1);
    lcd.print("-"); //NEUHADNUTE CISLO, ANI POZICIA
  }

  if (cislo3 == cielovecislo3) {
    lcd.setCursor(12, 1);
    lcd.print("="); //UHADNUTE CISLO VRATANE POZICIE
  } else if ((cislo3 == cielovecislo1) || (cislo3 == cielovecislo2) || (cislo3 == cielovecislo4)) {
    lcd.setCursor(12, 1);
    lcd.print("C"); //UHADNUTE CISLO BEZ POZICIE
  } else {
    lcd.setCursor(12, 1);
    lcd.print("-"); //NEUHADNUTE CISLO, ANI POZICIA
  }

  if (cislo4 == cielovecislo4) {
    lcd.setCursor(13, 1);
    lcd.print("="); //UHADNUTE CISLO VRATANE POZICIE
  } else if ((cislo4 == cielovecislo1) || (cislo4 == cielovecislo2) || (cislo4 == cielovecislo3)) {
    lcd.setCursor(13, 1);
    lcd.print("C"); //UHADNUTE CISLO BEZ POZICIE
  } else {
    lcd.setCursor(13, 1);
    lcd.print("-"); //NEUHADNUTE CISLO, ANI POZICIA
  }

  if ((cislo1 == cielovecislo1) && (cislo2 == cielovecislo2) && (cislo3 == cielovecislo3) && (cislo4 == cielovecislo4)) {
    lcd.setCursor(0, 2);
    lcd.print("VYHRALI STE!");
    lcd.setCursor(0, 3);
    lcd.print("KONIEC HRY          ");
    while (1);
  }
}
