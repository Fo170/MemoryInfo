// Exemple 1 : Surveillance simple
#include <MemoryInfo.h>

void setup() {
  Serial.begin(115200);
  
  // Alloue de la mémoire pour le test
  char* buffer = (char*)malloc(1024);
  
  // Affiche les informations
  printMemoryInfo();
  
  free(buffer);
}

void loop() {}
