/*|----------------------------------------------------------|*/
/*|SKETCH FOR SIMPLE GUESSER                                 |*/
/*|Author: Bc. MARTIN CHLEBOVEC (martinius96)                |*/
/*|EMAIL: martinius96@gmail.com                              |*/
/*|WEB: https://arduino.php5.sk?lang=en                      |*/
/*|----------------------------------------------------------|*/

const int greenLed = 4;
const int redLed_1 = 5;
const int redLed_2 = 6;
const int yellowLed = 7;
int secretNumber;
void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.println("New Game!");
  delay(700);
  Serial.println("Goal: Guess the secret number.");
  delay(700);
  Serial.println("What is your guess?");

  // initialize each of the digital pins as an output
  pinMode(greenLed, OUTPUT);
  pinMode(redLed_1, OUTPUT);
  pinMode(redLed_2, OUTPUT);
  pinMode(yellowLed, OUTPUT);

  randomSeed(analogRead(A0)); // This seeds the secret number.
  secretNumber = random(101); // Secret number from range: 0-100
  Serial.println("SECRET NUMBER IS: ");
  Serial.println(secretNumber);
  while (Serial.available() <= 0) {
    Serial.println(" GUESS THE NUMBER! ");
    delay(1000);
  }
}

void loop()
{
  digitalWrite(redLed_1, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed_2, LOW);
  digitalWrite(yellowLed, LOW);
  if (Serial.available() > 0) {
    // read the input from keyboard (the guess)
    long theGuess = Serial.parseInt(); //long because of parseInt is long!!!
    // The Guess is printed to the serial monitor
    Serial.print("You Guessed ");
    Serial.println(theGuess);
    if (theGuess == secretNumber) {
      digitalWrite(greenLed, HIGH);
      Serial.println("You won !");
      while (1);
    }
    if (theGuess > secretNumber) {
      digitalWrite(redLed_1, HIGH);
     Serial.println("Your number is higher than secret number !");
    }
    if (theGuess < secretNumber) {
      digitalWrite(redLed_2, HIGH);
      Serial.println("Your number is lower than secret number !");
    }
    if (theGuess >= (secretNumber - 2)) {
      digitalWrite(yellowLed, HIGH);
      Serial.println("Your are so close! Keep trying");
    }
  }
}
