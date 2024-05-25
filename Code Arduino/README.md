# Code Arduino

Ce code permet de réaliser l'interface entre les capteurs, le potentiomètre permettant de régler l'amplification, l'écran OLED et la connexion Bluetooth au téléphone.

Boucle de 50ms : 
 - Récupération des valeurs analogiques de tension du capteur graphite et du flex sensor
 - Réglage de la résistance R2 de l'amplification avec l'encodeur rotatoire
 - Affichage des valeurs de tension sur l'écran OLED
 - Envoi des valeurs de tension au module Bluetooth (1 fois sur 10 => toutes les 500ms)

### capteur_graphite.ino

C'est le code à envoyer sur la carte Arduino UNO pour faire fonctionner le banc.
