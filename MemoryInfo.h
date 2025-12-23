#ifndef MEMORY_INFO_H
#define MEMORY_INFO_H

#include <Arduino.h>
// MemoryInfo v1.0.0

// Structures de données
struct MemoryInfo {
    int freeMemory;
    int totalMemory;
    int fragmentation;
    bool isAvailable;
};

struct MemoryStats {
    int usedMemory;
    int freeMemory;
    int heapSize;
    int fragmentation;
};

// Pour ESP8266
#ifdef ESP8266
#include <Esp.h>

inline int getFreeMemory() { return ESP.getFreeHeap(); }
inline int getTotalHeap() { return 81920; } // 80KB pour ESP8266
inline int getHeapFragmentation() { return ESP.getHeapFragmentation(); }
inline int getUsedMemory() { return getTotalHeap() - getFreeMemory(); }

// Pour ESP32
#elif defined(ESP32)
#include <esp_heap_caps.h>

inline int getFreeMemory() { return heap_caps_get_free_size(MALLOC_CAP_DEFAULT); }
inline int getTotalHeap() { return heap_caps_get_total_size(MALLOC_CAP_DEFAULT); }
inline int getHeapFragmentation() { 
    size_t free = heap_caps_get_free_size(MALLOC_CAP_DEFAULT);
    size_t largest = heap_caps_get_largest_free_block(MALLOC_CAP_DEFAULT);
    return free == 0 ? 100 : (100 - (largest * 100 / free));
}
inline int getUsedMemory() { 
    return heap_caps_get_total_size(MALLOC_CAP_DEFAULT) - 
           heap_caps_get_free_size(MALLOC_CAP_DEFAULT); 
}

// Pour AVR
#elif defined(__AVR__) || defined(ARDUINO_ARCH_AVR)

extern "C" {
    extern char *__brkval;
    extern char __heap_start;
}

inline int getFreeMemory() {
    char top;
    return __brkval == 0 ? 
           (&top - &__heap_start) : 
           (&top - __brkval);
}

inline int getTotalHeap() {
    #if defined(RAMEND) && defined(RAMSTART)
        return RAMEND - RAMSTART;
    #elif defined(__AVR_ATmega328P__)
        return 2048;
    #elif defined(__AVR_ATmega2560__)
        return 8192;
    #else
        return 2048;
    #endif
}

inline int getHeapFragmentation() { return 0; }
inline int getUsedMemory() { return getTotalHeap() - getFreeMemory(); }

// Pour les autres plateformes
#else

inline int getFreeMemory() { return -1; }
inline int getTotalHeap() { return -1; }
inline int getHeapFragmentation() { return -1; }
inline int getUsedMemory() { return -1; }

#endif

// Fonctions génériques
inline MemoryInfo getMemoryInfo() {
    MemoryInfo info;
    info.freeMemory = getFreeMemory();
    info.totalMemory = getTotalHeap();
    info.fragmentation = getHeapFragmentation();
    info.isAvailable = (info.freeMemory >= 0 && info.totalMemory > 0);
    return info;
}

inline MemoryStats getMemoryStats() {
    MemoryStats stats;
    stats.freeMemory = getFreeMemory();
    stats.heapSize = getTotalHeap();
    stats.fragmentation = getHeapFragmentation();
    stats.usedMemory = getUsedMemory();
    return stats;
}

inline float getMemoryUsagePercent() {
    int total = getTotalHeap();
    int used = getUsedMemory();
    return (total <= 0 || used < 0) ? -1.0f : (used * 100.0f) / total;
}

// Fonctions d'affichage
inline void printMemoryInfo() {
    MemoryInfo info = getMemoryInfo();
    Serial.println(F("=== INFORMATION MÉMOIRE ==="));
    
    if (!info.isAvailable) {
        Serial.println(F("  Information mémoire non disponible"));
        return;
    }
    
    Serial.print(F("RAM Total (Taille du tas): "));
    Serial.print(info.totalMemory);
    Serial.println(F(" bytes"));

    Serial.print(F("  RAM utilisée: "));
    Serial.print(info.totalMemory - info.freeMemory);
    Serial.print(F(" bytes / "));

    Serial.print(F("RAM libre: "));
    Serial.print(info.freeMemory);
    Serial.println(F(" bytes"));
    
    if (info.fragmentation >= 0) {
        Serial.print(F("  Fragmentation: "));
        Serial.print(info.fragmentation);
        Serial.println(F("%"));
    }
    
    float usage = getMemoryUsagePercent();
    if (usage >= 0) {
        Serial.print(F("  Mémoire utilisée: "));
        Serial.print(usage, 2);
        Serial.println(F("%"));
    }
}

inline void printMemoryStats() {
    MemoryStats stats = getMemoryStats();
    Serial.println(F("=== STATISTIQUES MÉMOIRE ==="));
    Serial.print(F("  Taille du tas: ")); Serial.print(stats.heapSize); Serial.println(F(" bytes"));
    Serial.print(F("  Mémoire utilisée: ")); Serial.print(stats.usedMemory); Serial.println(F(" bytes"));
    Serial.print(F("  RAM libre: ")); Serial.print(stats.freeMemory); Serial.println(F(" bytes"));
    if (stats.fragmentation >= 0) {
        Serial.print(F("  Fragmentation: ")); Serial.print(stats.fragmentation); Serial.println(F("%"));
    }
}

#endif // MEMORY_INFO_H