# Application Android

![Logo App Capteur](./Logo_Capteur-Graphite.png?raw=true "Logo" | width=100)

## Description de l'application

Cette application, réalisée à l'aide du MIT App Inventor, permet de se connecter en Bluetooth à la carte Arduino faisant tourner le capteur, et récupérer les mesures à la fois du capteur graphite et du flex sensor. 
Ensuite, un graphe permet de visualiser la variation en temps-réel de ces mesures, soit simultanément ou séparément.

<img src="Images/App_utilisation.png" alt="Différents écrans de l'application" width="900"> <br>


Les informations sont envoyées par l’Arduino via Bluetooth sous forme de chaîne de caractères toutes les 500ms. 
L’application s’occupe de séparer les chaînes, de répartir les informations et d’afficher les données correctes au bon endroit.

### Version 0.1.1

Corrigé la reconnaissance vocale, et les erreurs d'affichages des mesures

### Version 0.2

Ajout des graphiques de suivi des valeurs
