/*******************************************************************************************************
 * Tasterabfrage in Objektorientierter Programmierung (OOP)
 * Falk Sudkamp
 * 14.12.17
*******************************************************************************************************/

#ifndef __Taster__                          // Bedingte Compilierung in Abhängigkeit, ob ein Makroname nicht definiert ist
#define __Taster__                          // Definiert ein Makro

#include <Arduino.h>                        // Die "Arduino" C++ Header Datei wird aufgenommen

class Taster                                // Die Klasse "Taster" wird erstellt
{
  private:                                  // Private Struktur
    byte _pin = 0;                          // Deklarieren der Variablen
    bool _type = 0;
    unsigned long _lastTap = 0;

  public:                                   // Public Struktur
    Taster(byte pin, bool type);            // Deklarieren des Konstruktors zum Aufrufen der Objekte
    void begin();                           // Deklarieren der Objekte
    byte getPin();
    bool isClicked();
};

/*******************************************************************************************************
 * 
 * Definition der Objekte in C++
 * 
*******************************************************************************************************/

Taster::Taster(byte pin, bool type)         // Definieren der Konstruktors
{
  _pin = pin;                               // Public Variablen in Private Variablen schreiben
  _type = type;
}

void Taster::begin()                        // Definition der Objekte
{
  pinMode(_pin, INPUT);                     // Taster Pin als Input setzen
}

byte Taster::getPin()
{
  return _pin;                              // Private Variable übergeben
}

bool Taster::isClicked()
{
  bool _isClicked;                          // Deklaration einer lokalen Variable
  if (_type == 0)                           // If-Abfrage für Pull-Down
  {
    _isClicked = digitalRead(_pin);         // Taster Pin auslesen und abspeichern
  }
  if (_type == 1)                           // If-Abfrage für Pull-Up
  {
    _isClicked = digitalRead(_pin);
    _isClicked = !_isClicked;               // Invertiern der Variable
  }
  return _isClicked;                        // Private Variable übergeben
}

#endif                                      //  Beendet den Block mit bedingter Compilierung
