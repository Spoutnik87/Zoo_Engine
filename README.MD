# ZooEngine

## Installation

### Pré-requis

1. Un compilateur C/C++
1. CMake accessible par le terminal

### Installation des dépendances

#### SFML

1. [Téléchargé SFML](https://www.sfml-dev.org/files/SFML-2.5.0-sources.zip)
1. Décompresser le dans `/dependancies/SFML`
1. Ouvrez un terminal dans `/SFML` et tapez `cmake .`
1. Utiliser ensuite votre compilateur

> Pour **Linux** : tapez `make` dans le terminal

> Pour **Windows** : tapez `cmake -G "Visual Studio 15 2017 Win64"` et ouvrez `SFML.sln`

### Compilation de ZooEngine

1. Ouvrez le terminal à la racine du repos
1. tapez la commande `mkdir build` et `cd build`
1. puis tapez `cmake ..`

> Pour **Linux** : tapez `make` dans le terminal

> Pour **Windows** : tapez `cmake -G "Visual Studio 15 2017 Win64"` et ouvrez `ZooEngine.sln`

> **ATTENTION !** sous **Windows** les dlls doivent être à côté de l'executable généré

> **ATTENTION !** Par défaut **ZooEngine** est compilé en mode **RELEASE** pour compiler en mode **DEBUG** ajouté `cmake -DCMAKE_BUILD_TYPE=DEBUG`