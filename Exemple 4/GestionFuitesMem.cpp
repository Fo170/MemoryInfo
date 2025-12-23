// Exemple 4 : Gestion des fuites mémoire
#include <MemoryInfo.h>

unsigned long lastHeap = 0;

void checkMemoryLeak() {
  unsigned long currentHeap = MemoryInfo.heapUsed();
  
  if (lastHeap > 0 && currentHeap > lastHeap) {
    Serial.print("Possible memory leak detected! Increase: ");
    Serial.println(currentHeap - lastHeap);
  }
  
  lastHeap = currentHeap;
}

void setup() {
  Serial.begin(115200);
  MemoryInfo.display();
  lastHeap = MemoryInfo.heapUsed();
}

void loop() {
  // Votre code qui pourrait avoir des fuites
  
  // Vérifie périodiquement
  static unsigned long lastCheck = 0;
  if (millis() - lastCheck > 5000) {
    checkMemoryLeak();
    lastCheck = millis();
  }
  
  delay(100);
}
