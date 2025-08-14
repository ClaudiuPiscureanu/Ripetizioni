/*
il pulsante attiva e disattiva il sistema ( potenziometro)
il potenziometro regola la velocita di lampeggiamento del led, 
in posizione 0 -> spento 10->sempre accesso
*/


// Definizione dei pin
const int buttonPin = 2;     // pin del pulsante
const int potPin = A0;       // pin del potenziometro
const int ledPin = 13;       // pin del LED

// Variabili
int potValue = 0;            // valore letto dal potenziometro
int mappedValue = 0;         // valore mappato 0-10
bool systemActive = false;   // stato del sistema (on/off)
int buttonState = 0;         // stato attuale del pulsante
int lastButtonState = 0;     // stato precedente del pulsante
unsigned long lastDebounceTime = 0;  // ultimo tempo di debounce
unsigned long debounceDelay = 50;    // tempo di debounce

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // Solo per debug
}

void loop() {
  // Leggi lo stato del pulsante con debounce
  int reading = digitalRead(buttonPin);
  
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      
      // Se il pulsante è stato premuto (transizione da LOW a HIGH)
      if (buttonState == HIGH) {
        systemActive = !systemActive; // Inverti lo stato del sistema
      }
    }
  }
  
  lastButtonState = reading;

  if (systemActive) {
    // Leggi il valore del potenziometro e mappalo da 0 a 10
    potValue = analogRead(potPin);
    mappedValue = map(potValue, 0, 1023, 0, 10);
    
    // Controlla il LED in base al valore mappato
    if (mappedValue == 0) {
      digitalWrite(ledPin, LOW); // LED spento
    } else if (mappedValue == 10) {
      digitalWrite(ledPin, HIGH); // LED sempre acceso
    } else {
      // Calcola l'intervallo di lampeggio (da 1000ms a 100ms)
      int blinkInterval = map(mappedValue, 1, 9, 1000, 100);
      blinkLed(blinkInterval);
    }
    
    // Debug su seriale (opzionale)
    Serial.print("Sistema: ON | Valore: ");
    Serial.println(mappedValue);
  } else {
    digitalWrite(ledPin, LOW); // Spegni il LED quando il sistema è disattivato
    Serial.println("Sistema: OFF");
  }
}

// Funzione per far lampeggiare il LED con un determinato intervallo
void blinkLed(int interval) {
  static unsigned long previousMillis = 0;
  static bool ledState = LOW;
  
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
