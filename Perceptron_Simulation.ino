#include <LiquidCrystal_I2C.h>

// Inizializza LCD (indirizzo 0x27, 16 colonne, 2 righe)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin collegati
const int potPin = A0;  // Pin del potenziometro

// Parametri del percettrone
float weight = 0.5;     // Peso iniziale
float bias = 0.1;       // Bias iniziale

// Funzione di attivazione (step)
int activationFunction(float input) {
  return input >= 0 ? 1 : 0;
}

void setup() {
  lcd.init();
  lcd.backlight();  // Accende la retroilluminazione LCD
  lcd.setCursor(0, 0);
  lcd.print("Percettrone:");
  delay(1000);
}

void loop() {
  // Leggi il valore del potenziometro
  int potValue = analogRead(potPin);
  float input = map(potValue, 0, 1023, -1.0, 1.0);  // Scala tra -1 e 1

  // Calcolo del risultato del percettrone
  float weightedSum = input * weight + bias;
  int output = activationFunction(weightedSum);

  // Mostra i risultati sul display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input: ");
  lcd.print(input, 2);  // Mostra 2 decimali
  lcd.setCursor(0, 1);
  lcd.print("Out: ");
  lcd.print(output);

  delay(500);  // Aggiorna ogni mezzo secondo
}
