// Exemple 3 : Récupération de valeurs individuelles
#include <MemoryInfo.h>

void setup() {
  Serial.begin(115200);
  
  Serial.print("Heap usage: ");
  Serial.print(MemoryInfo.heapPercentage());
  Serial.println("%");
  
  Serial.print("Free heap: ");
  Serial.print(MemoryInfo.heapFree());
  Serial.println(" bytes");
  
  #ifdef ESP32
  if (MemoryInfo.psramTotal() > 0) {
    Serial.print("PSRAM free: ");
    Serial.print(MemoryInfo.psramFree());
    Serial.println(" bytes");
  }
  #endif
}

void loop() {}
