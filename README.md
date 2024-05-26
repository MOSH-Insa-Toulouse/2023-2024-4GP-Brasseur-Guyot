# 2023-2024-4GP-Brasseur-Guyot

Projet capteur low-tech en graphite par Damien Brasseur et Tristan Guyot

### Contexte

Ce capteur a été réalisé, instrumenté et caractérisé dans le cadre d'un projet de 4ème année au département du Génie Physique de l'INSA TOULOUSE, encadré par Jérémie Grisolia, Benjamin Mestre, Arnaud Biganzoli et Cathy Crouzet. Tout le code, schématiques et mesures sont *open source* et réutilisables à volonté.

### Contacts

Damien : brasseu@insa-toulouse.fr <br>
Tristan : tguyot@insa-toulouse.fr

### Table des matières

[Description générale du projet](#coo) <br>
[Caractéristiques techniques](#zozo) <br>
[Mode d'emploi](#pookie) <br>
[Tests du capteur graphite](#booboo)

## 1 - Description générale du projet <a name="coo">

### Principe

Les capteurs sont partout. Dès qu’on cherche à automatiser un système, quel qu’il soit, on a besoin de capteurs. Pourtant, la plupart sont très coûteux en énergie, et leur multiplication fait qu’ils sont de plus en plus impactants sur l’environnement. C’est pour ça que les capteurs low-tech représentent un atout non négligeable. 

Un dépôt de graphite sur du papier forme un système granulaire, composé de grains de plus ou moins grande taille espacés d'une certaine distance, appelée distance inter-grain.
Cette propriété fait que sa conductance dépend de façon exponentielle de la distance inter-grain, qui peut être modulée en repliant le papier.
Ainsi, on peut retrouver la contrainte appliquée au matériau directement en mesurant la résistance aux bornes du capteur.

### Contenu du banc

<img src="Images/Capteur_Shield.png" alt="Le projet dans son ensemble" width="900"> <br>

 - Le capteur graphite (interchangeable)
 - Un amplificateur permettant de mesurer avec précision les variations (cette amplification peut être modulée via la modification de la résistance R2 de la boucle de rétroaction de l'amplificateur, pilotée grâce à l'encodeur rotatoire)
 - Un capteur flex-sensor permettant de comparer les mesures du capteur graphite
 - Un écran OLED, sur lequel les mesures sont affichées en temps-réel
 - Une application Android, connectée en Bluetooth, sur laquelle les mesures et leur variation peuvent être visionnée

## 2 - Caractéristiques techniques <a name="zozo">

La *datasheet* est accessible [ici](./Datasheet/datasheet_capteur-graphite_final.pdf)

### Capteur

Le capteur est constitué d'une feuille de papier recouverte de graphite déposé au crayon selon un patterne spécifique :

<img src="Images/Dimensions_capteur.png" alt="Le capteur graphite" width="500"> <br>

L'épaisseur du papier utilisé est de 200 µm.

### Electronique

L'électronique analogique permettant d'amplifier et de filtrer le signal du capteur graphite est composé d'un amplificateur transimpédance et de trois filtres :
 - Un filtre passif en entrée permettant d'éviter la distortion dans l'étage d'entrée
 - Un filtre actif basé sur l'amplificateur permettant une efficacité maximale
 - Un filtre passif en sortie pour éliminer le bruit introduit lors du traitement.

<img src="./Images/Schema-elec.png" alt="Schéma de l'amplification" width="900"> <br>


### KiCad

Explications disponibles [ici](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Brasseur-Guyot/tree/main/KiCad)

### Code Arduino

Explications disponibles [ici](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Brasseur-Guyot/tree/main/Code%20Arduino)

### Application Android

Explications disponibles [ici](https://github.com/MOSH-Insa-Toulouse/2023-2024-4GP-Brasseur-Guyot/tree/main/Application%20Android)

## 3 - Mode d'emploi <a name="pookie">

### KiCad

Le dossier KiCad est à télécharger dans son intégralité.
Une fois téléchargé, il faudra recharger les librairies de symboles depuis le dossier Mods.

### Code Arduino

Pour charger le code sur la carte **Arduino UNO**, rien de plus facile ! Il suffit de l'ouvrir dans l'application Arduino IDE avec la carte branchée en USB, puis cliquer sur *Upload*.

### Application Android

L'application est à télécharger sur un téléphone Android. Après l'installation, aller dans les paramètres des applications Android et accorder l'accès au Bluetooth et au micro à l'application.
Pour assurer la connexion entre la carte Arduino et le téléphone, il faut d'abord se connecter au module Bluetooth de la carte avec l'interface générale Bluetooth du téléphone. Ensuite, on pourra sélectionner dans l'application le module et on pourra commencer à s'amuser.

## 4 - Tests du capteur graphite <a name="booboo">

Nous avons réalisé des mesures de compression et de détente avec des capteurs comportant différentes densités de graphite (variant avec le type de crayon : 4H, HB et 4B), ainsi que pour le Flex sensor.

Le banc de test sur lequel nous avons testé les mesures comporte 4 demi-cercles de diamètres 2cm, 3cm, 4cm et 5cm, respectivement. La déformation est calculée selon l'expression suivante : $\varepsilon = \frac{D}{e}$ avec $D$ diamètre du demi-cercle et $e$ épaisseur du papier.

Voici la caractéristique en détente : 

<img src="Banc de test/TestDétente.png" alt="Caractéristique en détente" width="700"> <br>

On remarque que la variation de résistance la plus marquée (pente la plus élevée) est cele du capteur au crayon 4H. De façon surprenante, le capteur au cayon HB est moins efficace que le capteur 4B.

Voici la caractéristique en compression : 

<img src="Banc de test/TestCompression.png" alt="Caractéristique en compression" width="700"> <br>

Même comportement, sauf qu'une limite a été atteinte en mesure de compression (demi-cercle de 2cm) avec le capteur 4H. Le flex sensor ne fonctionnant que dans un seul sens, nous n'avons pas pu le tester dans ces conditions.
