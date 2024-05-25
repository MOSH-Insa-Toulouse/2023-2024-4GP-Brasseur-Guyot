# 2023-2024-4GP-Brasseur-Guyot
Projet capteur low-tech en graphite par Damien Brasseur et Tristan Guyot

## 1 - Description générale du projet

### Principe

Un dépôt de graphite sur du papier forme un système granulaire, composé de grains de plus ou moins grande taille espacés d'une certaine distance, appelée distance inter-grain.
Cette propriété fait que sa conductance dépend de façon exponentielle de la distance inter-grain, qui peut être modulée en repliant le papier.
Ainsi, on peut retrouver la contrainte appliquée au matériau directement en mesurant la résistance aux bornes du capteur.

### Contenu du banc

 - Le capteur graphite (interchangeable)
 - Un amplificateur permettant de mesurer avec précision les variations (cette amplification peut être modulée via la modification de la résistance R2 de la boucle de rétroaction de l'amplificateur, pilotée grâce à l'encodeur rotatoire)
 - Un capteur flex-sensor permettant de comparer les mesures du capteur graphite
 - Un écran OLED, sur lequel les mesures sont affichées en temps-réel
 - Une application Android, connectée en Bluetooth, sur laquelle les mesures et leur variation peuvent être visionnée

## 2 - Caractéristiques techniques

La *datasheet* est accessible à l'adresse suivante : https://google.com

### Electronique

### KiCad

Explications disponibles [ici]("KiCad/")

### Code Arduino

Explications disponibles [ici]("Code Arduino/")

### Application Android

Explications disponibles [ici]("Application Android/")

## 3 - Mode d'emploi

### KiCad

Le dossier KiCad est à télécharger dans son intégralité.
Une fois téléchargé, il faudra recharger les librairies de symboles depuis le dossier Mods.

### Code Arduino

Pour charger le code sur la carte **Arduino UNO**, rien de plus facile ! Il suffit de l'ouvrir dans l'application **Arduino IDE** avec la carte branchée en USB, puis cliquer sur *Upload*.

### Application Android

L'application est à télécharger sur téléphone.
