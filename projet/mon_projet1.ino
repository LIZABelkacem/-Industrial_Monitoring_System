
#include "LiquidCrystal.h" // on inclut la librairie

// les branchements
const int boutonGauche = 7; // le bouton de gauche
const int boutonDroite = 6; // le bouton de droite
const int potentiometreGauche = 0; // le potentiomètre de gauche (analogique 0)
const int potentiometreDroite = 1; // le potentiomètre de droite (analogique 1)
const int ledAlarme = 8; // la LED est branché sur la sortie 2

// initialise l'écran avec les bonnes broches
// ATTENTION, REMPLACER LES NOMBRES PAR VOS BRANCHEMENTS À VOUS !
LiquidCrystal lcd(11,10,5,4,3,2);

char messageHaut[16] = ""; // Message sur la ligne du dessus
char messageBas[16] = ""; // Message sur la ligne du dessous

unsigned long temps = 0; // pour garder une trace du temps qui s'écoule
boolean ecran = LOW; // savoir si on affiche les boutons ou les conversions

int etatGauche = LOW; // état du bouton de gauche
int etatDroite = LOW; // état du bouton de droite
int niveauGauche = 0; // conversion du potentiomètre de gauche
int niveauDroite = 0; // conversion du potentiomètre de droite

// les mêmes variables mais "old"
// servant de mémoire pour constater un changement
int etatGauche_old = LOW; // état du bouton de gauche
int etatDroite_old = LOW; // état du bouton de droite
int niveauGauche_old = 0; // conversion du potentiomètre de gauche
int niveauDroite_old = 0; // conversion du potentiomètre de droite

// -------------------------------------------------------------------------

void setup() {
    // réglage des entrées/sorties
    pinMode(boutonGauche, INPUT);
    pinMode(boutonDroite, INPUT);
    digitalWrite(boutonGauche, HIGH);
    digitalWrite(boutonDroite, HIGH);
    pinMode(ledAlarme, OUTPUT);
    digitalWrite(ledAlarme, HIGH);

    // paramétrage du LCD
    lcd.begin(16, 2); // règle la  taille du LCD
    lcd.noBlink(); // pas de clignotement
    lcd.noCursor(); // pas de curseur
    lcd.noAutoscroll(); // pas de défilement
}

void loop() {

    // commence par récupérer les données des boutons et capteurs
    recupererDonnees();

    if(ecran) // quel écran affiche-t'on ? (bouton ou potentiomètre ?)
    {
        if(boutonsChanged()) // si un bouton a changé d'état
            updateEcran();
    }
    else
    {
        if(potarChanged()) // si un potentiomètre a changé d'état
            updateEcran();
    }

    if(niveauDroite > niveauGauche)
        // RAPPEL : piloté à l'état bas donc on allume !
        digitalWrite(ledAlarme, LOW);
    else
        digitalWrite(ledAlarme, HIGH);

    // si ça fait 5s qu'on affiche la même donnée
    if(millis() - temps > 5000)
    {
        ecran = ~ecran;
        lcd.clear();
        updateEcran();
        temps = millis();
    }
}

// -------------------------------------------------------------------------

void recupererDonnees()
{
    // efface les anciens avec les "nouveaux anciens"
    etatGauche_old = etatGauche;
    etatDroite_old = etatDroite;
    niveauGauche_old = niveauGauche;
    niveauDroite_old = niveauDroite;

    etatGauche = digitalRead(boutonGauche);
    etatDroite = digitalRead(boutonDroite);
    niveauGauche = analogRead(potentiometreGauche);
    niveauDroite = analogRead(potentiometreDroite);
}

boolean boutonsChanged()
{
    if(etatGauche_old != etatGauche || etatDroite_old != etatDroite)
        return true;
    else
        return false;
}

boolean potarChanged()
{
    // si un potentiomètre affiche une différence de plus de 2 unités
    // entre ces deux valeurs, alors on met à jour
    if(abs(niveauGauche_old-niveauGauche) > 2 ||
       abs(niveauDroite_old-niveauDroite) > 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void updateEcran()
{
    if(ecran)
    {
        // prépare les chaines à mettre sur l'écran
        if(etatGauche)
            sprintf(messageHaut,"Bouton G : ON");
        else
            sprintf(messageHaut,"Bouton G : OFF");
        if(etatDroite)
            sprintf(messageBas,"Bouton D : ON");
        else
            sprintf(messageBas,"Bouton D : OFF");
    }
    else
    {
        // prépare les chaines à mettre sur l'écran
        sprintf(messageHaut,"gauche = %4d", niveauGauche);
        sprintf(messageBas,"droite = %4d", niveauDroite);
    }

    // on envoie le texte
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(messageHaut);
    lcd.setCursor(0,1);
    lcd.print(messageBas);
}




/*
void setup()
  
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
} 
*/
