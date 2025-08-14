const int ledPins[3] = {13, 12, 11}; // LED da sinistra (MSB) a destra (LSB)

void setup() {
  // Imposta tutti i pin dei LED come output
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Inizializza la comunicazione seriale per debug (opzionale)
  Serial.begin(9600);

  // Seed per il generatore di numeri casuali
  randomSeed(analogRead(0));
}

void loop() {
  int dado = random(1, 7); // Valore casuale tra 1 e 6
  Serial.print("Lancio del dado: ");
  Serial.println(dado);

  // Accendi i LED in base alla rappresentazione binaria del valore
  for (int i = 0; i < 3; i++) {
    int bit = (dado >> (2 - i)) & 1;
    digitalWrite(ledPins[i], bit);
  }

  delay(1000); // Aspetta 1 secondo prima del prossimo lancio
}
