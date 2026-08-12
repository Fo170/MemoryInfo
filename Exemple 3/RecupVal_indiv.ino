// Exemple 3 : Récupération de valeurs individuelles
#include <MemoryInfo.h>

void setup() {
  Serial.begin(115200);
  
  Serial.print("Heap usage: ");
  Serial.print(getMemoryUsagePercent());
  Serial.println("%");
  
  Serial.print("Free heap: ");
  Serial.print(getFreeMemory());
  Serial.println(" bytes");
  
  Serial.print("Total heap: ");
  Serial.print(getTotalHeap());
  Serial.println(" bytes");
  
  Serial.print("Fragmentation: ");
  Serial.print(getHeapFragmentation());
  Serial.println("%");
}

void loop() {}
