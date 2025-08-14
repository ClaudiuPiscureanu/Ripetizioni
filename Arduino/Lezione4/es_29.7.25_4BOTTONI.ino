#include <Adafruit_NeoPixel.h>
#define LED_PIN 6
#define NUM_STRIPS 4
#define LEDS_PER_STRIP 4
#define TOTAL_LEDS NUM_STRIPS * LEDS_PER_STRIP

Adafruit_NeoPixel matrix(TOTAL_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Definizione pulsanti
#define UP_BUTTON 2
#define DOWN_BUTTON 3
#define RIGHT_BUTTON 4
#define LEFT_BUTTON 5

// Posizione cursore
int currentStrip = 0;
int currentLed = 0;

void setup() {
  // Inizializzazione seriale
  Serial.begin(9600);
  Serial.println("Sistema inizializzato");
  Serial.print("Posizione iniziale: Strip ");
  Serial.print(currentStrip);
  Serial.print(", LED ");
  Serial.println(currentLed);

  // Configurazione pin
  pinMode(UP_BUTTON, INPUT);
  pinMode(DOWN_BUTTON, INPUT);
  pinMode(RIGHT_BUTTON, INPUT);
  pinMode(LEFT_BUTTON, INPUT);
  
  matrix.begin();
  matrix.show();
  updateCursor();
}

void loop() {
  if (digitalRead(UP_BUTTON) == HIGH) {
    moveCursor(0, 1);
    logMovement("SU");
    delay(200);
  }
  if (digitalRead(DOWN_BUTTON) == HIGH) {
    moveCursor(0, -1);
    logMovement("GIU");
    delay(200);
  }
  if (digitalRead(RIGHT_BUTTON) == HIGH) {
    moveCursor(1, 0);
    logMovement("DESTRA");
    delay(200);
  }
  if (digitalRead(LEFT_BUTTON) == HIGH) {
    moveCursor(-1, 0);
    logMovement("SINISTRA");
    delay(200);
  }
}

void moveCursor(int dx, int dy) {
  // Spegni LED corrente
  matrix.setPixelColor(getLedIndex(currentStrip, currentLed), matrix.Color(0, 0, 0));
  
  // Aggiorna posizione
  int newStrip = constrain(currentStrip + dy, 0, NUM_STRIPS - 1);
  int newLed = constrain(currentLed + dx, 0, LEDS_PER_STRIP - 1);

  // Verifica se la posizione è cambiata
  if (newStrip != currentStrip || newLed != currentLed) {
    currentStrip = newStrip;
    currentLed = newLed;
  }
  
  updateCursor();
}

int getLedIndex(int strip, int led) {
  return (strip * LEDS_PER_STRIP) + led;
}

void updateCursor() {
  matrix.setPixelColor(getLedIndex(currentStrip, currentLed), matrix.Color(0, 150, 0));
  matrix.show();
}

// Funzione per loggare i movimenti
void logMovement(String direction) {
  Serial.print("Movimento: ");
  Serial.print(direction);
  Serial.print(" | Nuova posizione: Strip ");
  Serial.print(currentStrip);
  Serial.print(", LED ");
  Serial.println(currentLed);
  
  Serial.print("Indice assoluto: ");
  Serial.println(getLedIndex(currentStrip, currentLed));
}