# MemoryInfo pour les ESP8266, ESP32, AVR, ...

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979C?style=flat&logo=arduino)](https://docs.arduino.cc/software/ide/)
[![Arduino Badge](https://img.shields.io/badge/framework-arduino-brightgreen?logo=arduino.svg)](https://www.arduino.cc/)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-compatible-brightgreen.svg)](https://platformio.org/)
[![ESP8266](https://img.shields.io/badge/ESP8266-Supported-green.svg)](https://www.espressif.com/)
[![ESP32](https://img.shields.io/badge/ESP32-Supported-green.svg)](https://www.espressif.com/)
[![Arduino Library Badge](https://www.ardu-badge.com/badge/MemoryInfo.svg)](https://github.com/Fo170/MemoryInfo)
![GitHub release](https://img.shields.io/github/v/release/Fo170/MemoryInfo)
![GitHub last commit](https://img.shields.io/github/last-commit/Fo170/MemoryInfo)

Une bibliothèque Arduino légère et efficace pour surveiller l'utilisation de la mémoire (heap) sur les microcontrôleurs ESP8266, ESP32 et AVR.

# Fonctionnalités
📊 Surveillance de la mémoire heap : libre, utilisée, fragmentation

🏗️ Support multi-architecture : ESP8266, ESP32 et AVR

📝 Sortie formatée : Affichage clair via Serial

🔧 Interface simple : Fonctions faciles à utiliser

🚀 Léger : Header-only, pas de surcharge significative

# Installation
Méthode 1 : Gestionnaire de bibliothèques Arduino
Ouvrez l'IDE Arduino

Allez dans Croquis > Inclure une bibliothèque > Gérer les bibliothèques...

Recherchez "MemoryInfo"

Cliquez sur "Installer"

Méthode 2 : Installation manuelle
Téléchargez le code source depuis GitHub

Extrayez le fichier ZIP

Copiez le dossier MemoryInfo dans votre dossier libraries Arduino

Redémarrez l'IDE Arduino

### Via PlatformIO (recommandé)

Ajoutez la dépendance à votre `platformio.ini` :

```ini
lib_deps = 
    https://github.com/Fo170/MemoryInfo.git@^1.1.0
```

# Fonctions disponibles
`getFreeMemory()`
Retourne la quantité de heap libre en octets (-1 si non supporté).

`getTotalHeap()`
Retourne la taille totale du heap en octets (référence mesurée au premier appel sur ESP8266, RAM totale sur AVR).

`getHeapFragmentation()`
Retourne le pourcentage de fragmentation du heap (0 sur AVR, -1 si non supporté).

`getUsedMemory()`
Retourne la quantité de heap utilisée en octets.

`getMemoryUsagePercent()`
Retourne le pourcentage d'utilisation du heap (-1.0 si non supporté).

`getMemoryInfo()`
Retourne une structure `MemoryInfo` avec `freeMemory`, `totalMemory`, `fragmentation` et `isAvailable`.

`getMemoryStats()`
Retourne une structure `MemoryStats` avec `usedMemory`, `freeMemory`, `heapSize` et `fragmentation`.

`printMemoryInfo()`
Affiche un rapport complet de l'utilisation de la mémoire dans le moniteur série.

`printMemoryStats()`
Affiche un rapport détaillé (statistiques) dans le moniteur série.

# Support des plates-formes
ESP8266 : Support du heap via ESP.getFreeHeap()

ESP32 : Support du heap via esp_heap_caps

AVR : Support du heap (fragmentation non mesurée)

Autres plates-formes : Retournent -1

# Limitations
Sur ESP8266, le total du heap est la référence mesurée au premier appel

La précision peut varier selon le modèle d'ESP

La fragmentation n'est pas mesurée sur AVR

# Dépannage
Problème : "MemoryInfo.h: No such file or directory"
Vérifiez que la bibliothèque est correctement installée

Redémarrez l'IDE Arduino

Problème : Valeurs incohérentes
Attendez que le système soit stable avant de mesurer

Évitez de mesurer pendant les interruptions

# Contribution
Les contributions sont les bienvenues ! N'hésitez pas à :
- Signaler des bugs
- Proposer des nouvelles fonctionnalités
- Soumettre des pull requests

# Licence
Cette bibliothèque est distribuée sous GPL-3.0-only. Voir le fichier LICENSE pour plus de détails.

# Auteur
Développé par FOURNET Olivier. Retrouvez le projet sur GitHub.

# Support
Pour toute question ou problème :

Ouvrez une issue sur GitHub

Consultez la documentation Arduino

Rejoignez les forums Arduino officiels
