# ZooEngine

## Installation

### Pré-requis

1. Un compilateur C/C++
1. CMake accessible par le terminal

### Installation des dépendances

#### SFML

1. [Téléchargez SFML](https://www.sfml-dev.org/files/SFML-2.5.0-sources.zip)
1. Décompressez le dans `/dependencies/SFML`
1. Ouvrez un terminal dans `/SFML` et tapez `cmake .`
1. Utilisez ensuite votre compilateur

   > Pour **Linux** : tapez `make` dans le terminal

   > Pour **Windows** : tapez `cmake -G "Visual Studio 15 2017 Win64"` et ouvrez `SFML.sln`

### Boost

1. [Téléchargez Boost](https://www.boost.org/users/download/)
1. Décompressez le dans `/dependencies/Boost`
1. > Pour **Linux** : tapez la commande `./bootstrap.sh`

   > Pour **Windows** : tapez la commande `./bootstrap.bat`

1. Tapez ensuite la commande `./bjam`

### Compilation de ZooEngine

1. Ouvrez le terminal à la racine du repos
1. Tapez la commande `mkdir build` et `cd build`
1. Tapez la commande `cmake ..`

> Pour **Linux** : tapez `make` dans le terminal

> Pour **Windows** : tapez `cmake -G "Visual Studio 15 2017 Win64"` et ouvrez `ZooEngine.sln`

> **ATTENTION !** sous **Windows** les dlls doivent être à côté de l'exécutable généré

> **ATTENTION !** Par défaut **ZooEngine** est compilé en mode **RELEASE**, pour compiler en mode **DEBUG** ajoutez `cmake -DCMAKE_BUILD_TYPE=DEBUG`
