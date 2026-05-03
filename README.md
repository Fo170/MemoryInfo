# MemoryInfo pour les ESP8266, ESP32, ...

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![Arduino](https://img.shields.io/badge/Arduino-IDE-00979C?style=flat&logo=arduino)](https://docs.arduino.cc/software/ide/)
[![Arduino Badge](https://img.shields.io/badge/framework-arduino-brightgreen?logo=arduino.svg)](https://www.arduino.cc/)
[![PlatformIO](https://img.shields.io/badge/PlatformIO-compatible-brightgreen.svg)](https://platformio.org/)
[![ESP8266](https://img.shields.io/badge/ESP8266-Supported-green.svg)](https://www.espressif.com/)
[![ESP32](https://img.shields.io/badge/ESP32-Supported-green.svg)](https://www.espressif.com/)
[![Arduino Library Badge](https://www.ardu-badge.com/badge/PreciseTime-ESP.svg)](https://github.com/Fo170?tab=repositories)
![GitHub release](https://img.shields.io/github/v/release/Fo170/PreciseTime-ESP)
![GitHub last commit](https://img.shields.io/github/last-commit/Fo170/PreciseTime-ESP)

Une bibliothèque Arduino légère et efficace pour surveiller l'utilisation de la mémoire sur les microcontrôleurs ESP8266 et ESP32. Cette bibliothèque fournit des informations détaillées sur la mémoire heap, stack et PSRAM (si disponible).

# Fonctionnalités
📊 Surveillance complète de la mémoire : Heap, stack et PSRAM

🏗️ Support multi-architecture : ESP8266 et ESP32

📝 Sortie formatée : Affichage clair via Serial

🔧 Interface simple : Méthodes faciles à utiliser

🚀 Léger : Pas de surcharge significative

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
    https://github.com/Fo170/MemoryInfo.git@^1.0.0
```

# Méthodes disponibles
MemoryInfo.display()
Affiche un rapport complet de l'utilisation de la mémoire dans le moniteur série.

MemoryInfo.heapPercentage()
Retourne le pourcentage d'utilisation du heap.

MemoryInfo.heapTotal()
Retourne la taille totale du heap en octets.

MemoryInfo.heapUsed()
Retourne la quantité de heap utilisée en octets.

MemoryInfo.heapFree()
Retourne la quantité de heap libre en octets.

MemoryInfo.maxBlock()
Retourne la taille du plus grand bloc mémoire disponible.

MemoryInfo.stackUsed()
Retourne la quantité de stack utilisée en octets.

MemoryInfo.psramTotal() (ESP32 seulement)
Retourne la taille totale de la PSRAM en octets.

MemoryInfo.psramUsed() (ESP32 seulement)
Retourne la quantité de PSRAM utilisée en octets.

MemoryInfo.psramFree() (ESP32 seulement)
Retourne la quantité de PSRAM libre en octets.

# Support des plates-formes
ESP8266 : Support complet du heap et stack

ESP32 : Support complet du heap, stack et PSRAM

Autres plates-formes : Non supportées actuellement

# Limitations
Les mesures de stack sont des estimations

La précision peut varier selon le modèle d'ESP

L'utilisation de la PSRAM n'est disponible que sur les ESP32 avec PSRAM

# Dépannage
Problème : "MemoryInfo.h: No such file or directory"
Vérifiez que la bibliothèque est correctement installée

Redémarrez l'IDE Arduino

Problème : Valeurs incohérentes
Attendez que le système soit stable avant de mesurer

Évitez de mesurer pendant les interruptions

Problème : PSRAM non détectée
Vérifiez que votre ESP32 a de la PSRAM

Activez la PSRAM dans les options de compilation

# Contribution
Les contributions sont les bienvenues ! N'hésitez pas à :

# Signaler des bugs

Proposer des nouvelles fonctionnalités

Soumettre des pull requests

# Licence
Cette bibliothèque est distribuée sous GPL-3.0 license. Voir le fichier LICENSE pour plus de détails.

# Auteur
Développé par Fo170. Retrouvez le projet sur GitHub.

# Support
Pour toute question ou problème :

Ouvrez une issue sur GitHub

Consultez la documentation Arduino

Rejoignez les forums Arduino officiels
