# controle_tete_expressive

Contrôle d'une tête expressive simple avec une carte Pololu via Bluetooth.

Ceci est le résultat d'un mois de stage à l'université de Cergy-Pontoise en CMI SIC (L1) sur la mise en place d'une tête expressive.


------------------------------------------
Encadré par M. Philippe GAUSSIER         
 
Par :
Kévin BERNARD
Maria-Lorena POUPET 
Geoffroy KEIME

------------------------------------------

______________________________________________________
*********CARTE POLOLU MAESTRO*********
______________________________________________________
Fonctionne via un Arduino par Blueooth et via une application sur MIT APP INVENTOR.

  -> **APPLICATIONS**
       ROBOTO CONTROL : Application avec des sliders qui permet de modifier la postion d'un servomoteur sur le robot.
                        Possiblité de sauvegarde (fichier .rob) sur le téléphone (pas sur carte SD).
       ROBOTO READER : Application qui permet de faire une expressions parmis les cinq disponibles (Joie, Peur, Tristesse, Etonnement,               Colère) et de lire la sauvegarde venant de l'application Control (en cours).
        Compatibilité avec l'application Pololu Maestro Control Center.
        
  -> **ARDUINO**
        Code : Le code est écrit par Xavier Wiedmer (http://www.aranacorp.com)
        Branchement : Branchez la pin 3 de l'Arduino sur le rx de la carte Pololu 
                      Et le rx/tx sur le module Bluetooth.
  
_____________________________________________________
********CARTE MINI SSC-III********
_____________________________________________________

Un code simple permettant l'envoi d'une action au robot par l'intermédiaire d'un port Série RS-232
Documentation similaire à celle de la Mini SSC-II.
Le bon fonctionnement de l'application nécessite cependant Minicom sur Linux (ou configuration port série).





