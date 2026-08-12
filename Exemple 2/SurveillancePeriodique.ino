// Exemple 2 : Surveillance périodique
#include <MemoryInfo.h>

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Affiche les informations toutes les 10 secondes
  static unsigned long lastDisplay = 0;
  if (millis() - lastDisplay > 10000) {
    printMemoryInfo();
    lastDisplay = millis();
  }
  
  // Votre application ici
  delay(100);
}
