/******************************************************************************************************
   Tasterabfrage in Objektorientierter Programmierung (OOP) und Ausgabe des Wertes im Seriellen Monitor
   Falk Sudkamp
   14.12.17
******************************************************************************************************/
#include "Taster.h"                         // Die "Taster" C++ Header Datei wird aufgenommen

Taster taster1(2, 0);                       // Instanziieren des Tasters als Objekt
bool tasterStatus = 0;                      // Deklarieren von Variablen
byte tasterPin = 0;

void setup()
{
  Serial.begin(9600);
  taster1.begin();                          // Das Objekt "begin" aufrufen
}

void loop()
{
  tasterPin = taster1.getPin();             // Speichern des vom Objekt "getPin" ausgelesenden Pin 
  Serial.print("Taster Pin: ");
  Serial.println(tasterPin);                // Ausgeben des Pins

  delay(100);

  tasterStatus = taster1.isClicked();       // Speichern des vom Objekt "isClicked" ausgelesenden Zustand
  Serial.print("Taster Status: ");
  Serial.println(tasterStatus);             // Ausgeben des Zustandes

  delay(100);
}
