// ZAKLADNA LOGIKA VSTUPU PRE HRU MASTERMIND
// VYPIS DO SERIAL MONITOR-u.
// MOZNOST DOPLNIT O RGB LED, LED PASY, NEOPIXEL RING A INE.
// PRI ROZPINACICH PUSHBUTTONOCH OTOCIT LOGIKU - ACTIVE LOW
//#define DEBUG //odkomentuj pre DEBUG INFO
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
int lastButtonState1 = HIGH;
int buttonState2 = HIGH;
int lastButtonState2 = HIGH;
int buttonState3 = HIGH;
int lastButtonState3 = HIGH;
int buttonState4 = HIGH;
int lastButtonState4 = HIGH;
int buttonState5 = HIGH;
int lastButtonState5 = HIGH;

unsigned long lastDebounceTime1 = 0;
unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime3 = 0;
unsigned long lastDebounceTime4 = 0;
unsigned long lastDebounceTime5 = 0;
unsigned long debounceInterval = 50;

int pokus = 0;
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(buttonPin5, INPUT_PULLUP);

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
#ifdef DEBUG
  Serial.println("Hladane cislo: ");
  Serial.print(cielovecislo1);
  Serial.print(cielovecislo2);
  Serial.print(cielovecislo3);
  Serial.print(cielovecislo4);
  Serial.println("");
#endif
}

void loop() {
  if (pokus >= 10) {
    Serial.println("Prehrali ste! Prekroceny pocet pokusov!");
    return;
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
          Serial.println("Prve cislo: ");
          Serial.print(cislo1);
          if (cislo1 > 9) {
            cislo1 = 0;
          }
        }
      }
    }

    if ((millis() - lastDebounceTime2) > debounceInterval) {
      if (reading2 != buttonState2) {
        buttonState2 = reading2;
        if (buttonState2 == HIGH) {
          cislo2++;
          Serial.println("Druhe cislo: ");
          Serial.print(cislo2);
          if (cislo2 > 9) {
            cislo2 = 0;
          }
        }
      }
    }

    if ((millis() - lastDebounceTime3) > debounceInterval) {
      if (reading3 != buttonState3) {
        buttonState3 = reading3;
        if (buttonState3 == HIGH) {
          cislo3++;
          Serial.println("Tretie cislo: ");
          Serial.print(cislo3);
          if (cislo3 > 9) {
            cislo3 = 0;
          }
        }
      }
    }

    if ((millis() - lastDebounceTime4) > debounceInterval) {
      if (reading4 != buttonState4) {
        buttonState4 = reading4;
        if (buttonState4 == HIGH) {
          cislo4++;
          Serial.println("Stvrte cislo: ");
          Serial.print(cislo4);
          if (cislo4 > 9) {
            cislo4 = 0;
          }
        }
      }
    }

    if ((millis() - lastDebounceTime5) > debounceInterval) {
      if (reading5 != buttonState5) {
        buttonState5 = reading5;
        if (buttonState5 == HIGH) {
          pokus++;
          if (cislo1 == cielovecislo1) {
            //ROZSVIET DIODU NA ZELENO NA PRVEJ POZICII (UHADNUTA POZICIA AJ CISLO)
          } else if (cislo1 == cielovecislo2) {
            //ROZSVIET DIODU NA CERVENO NA PRVEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else if (cislo1 == cielovecislo3) {
            //ROZSVIET DIODU NA CERVENO NA PRVEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else if (cislo1 == cielovecislo4) {
            //ROZSVIET DIODU NA CERVENO NA PRVEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else {
            //ZHASNI DIODU NA PRVEJ POZICII (NEUHADNUTE CISLO, ANI POZICIA)
          }
          if (cislo2 == cielovecislo2) {
            //ROZSVIET DIODU NA ZELENO NA DRUHEJ POZICII (UHADNUTA POZICIA AJ CISLO)
          } else if (cislo2 == cielovecislo1) {
            //ROZSVIET DIODU NA CERVENO NA DRUHEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else if (cislo2 == cielovecislo3) {
            //ROZSVIET DIODU NA CERVENO NA DRUHEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else if (cislo2 == cielovecislo4) {
            //ROZSVIET DIODU NA CERVENO NA DRUHEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else {
            //ZHASNI DIODU NA DRUHEJ POZICII (NEUHADNUTE CISLO, ANI POZICIA)
          }
          if (cislo3 == cielovecislo3) {
            //ROZSVIET DIODU NA ZELENO NA TRETEJ POZICII (UHADNUTA POZICIA AJ CISLO)
          } else if (cislo3 == cielovecislo1) {
            //ROZSVIET DIODU NA CERVENO NA TRETEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else if (cislo3 == cielovecislo2) {
            //ROZSVIET DIODU NA CERVENO NA TRETEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else if (cislo3 == cielovecislo4) {
            //ROZSVIET DIODU NA CERVENO NA TRETEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else {
            //ZHASNI DIODU NA TRETEJ POZICII (NEUHADNUTE CISLO, ANI POZICIA)
          }
          if (cislo4 == cielovecislo4) {
            //ROZSVIET DIODU NA ZELENO NA STVRTEJ POZICII (UHADNUTA POZICIA AJ CISLO)
          } else if (cislo4 == cielovecislo1) {
            //ROZSVIET DIODU NA CERVENO NA STVRTEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else if (cislo4 == cielovecislo2) {
            //ROZSVIET DIODU NA CERVENO NA STVRTEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else if (cislo4 == cielovecislo3) {
            //ROZSVIET DIODU NA CERVENO NA STVRTEJ POZICII (UHADNUTE CISLO BEZ POZICIE)
          } else {
            //ZHASNI DIODU NA STVRTEJ POZICII (NEUHADNUTE CISLO, ANI POZICIA)
          }
          if ((cislo1 == cielovecislo1) && (cislo2 == cielovecislo2) && (cislo3 == cielovecislo3) && (cislo4 == cielovecislo4)) {
            Serial.println("VYHRALI STE!");
            return;
          }
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
