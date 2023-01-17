#include <iostream>
#include <vector>
#include <string>
#include "Material.cpp"
#include "Building.cpp"
using namespace std;

//globale Variablen
bool nbeendet = true;
int laenge;
int breite;
vector<vector<Building>> Baubereich;

//Funktionen
void Laufzeit();
void gplatzieren();
void bloeschen();
void bausgeben();
void start();

void Laufzeit() {
    cout << "\n" << endl;
    cout << "|------Hauptmenue------|" << endl;
    cout << "|Gebaeude setzen  (1)  |" << endl;
    cout << "|Bereich loeschen (2)  |" << endl;
    cout << "|Bauplan Ausgeben (3)  |" << endl;
    cout << "|Programm beenden (4)  |" << endl;
    cout << "|----------------------|" << endl;
    cout << "\nBitte neachste Aktion auswaehlen: " << endl;
    string Eingabe = "0";
    cin >> Eingabe;
    cout << "\n" << endl;
    int Zahl = atoi(Eingabe.c_str());
    //nun auswählen
    switch (Zahl) {
    case  1: gplatzieren(); break;
    case  2: bloeschen(); break;
    case  3: bausgeben(); break;
    case  4: nbeendet = false; break;
    default:
        cout << "Fehler! Aktion unbekannt! Bitte neu versuchen!" << endl;
        Laufzeit();
    }
};

void start() {
    //Eingabe der Länge und Breite
    cout << "Bitte Laenge der Stadt eingeben: " << endl;
    cin >> laenge;
    cout << "Bitte Breite der Stadt eingeben: " << endl;
    cin >> breite;
    cout << "\nDie Stadt hat eine Laenge von " << laenge << " und eine Breite von " << breite << " !" << endl;


    //Ausgabe der Gebäudedtypen
    cout << "\nDerzeit moegliche Gebaeude:\nRathaus           = 1\nSchule            = 2\nGeschaeftsgebaude = 3\nWohngebaeude      = 4\nEinkaufszentrum   = 5\nKrankenhaus       = 6 " << endl;

    //Array des Baubereichs // Ein multidimensionales dynamisches Array = Vector, also nehmne wir den
    for (int i = 0; i < laenge; ++i) {
        Baubereich.push_back(vector<Building>());
        for (int j = 0; j < breite; ++j) {
            Baubereich[i].push_back(Leer::Building);
        }
    }
};

void bloeschen() {
    cout << "\nZum loeschen von Gebaeudeteilen auf der Karte werden folgende Informationen gebraucht: " << endl;
    int rstart;
    int sstart;
    int rend;
    int send;
    cout << "\nGebauedebereich Startpunkt in Reihe: " << endl;
    cin >> rstart;
    cout << "\nGebauedebereich Startpunkt in Spalte: " << endl;
    cin >> sstart;
    cout << "\nGebauedebereich Endpunkt in Reihe:: " << endl;
    cin >> rend;
    cout << "\nGebauedebereich Endpunkt in Spalte:: " << endl;
    cin >> send;
    if ((rend >= rstart) and (send >= sstart) and ((rstart >= 0) and (rstart <= breite)) and ((rend >= 0) and (rend <= breite)) and ((sstart >= 0) and (sstart <= laenge)) and ((send >= 0) and (send <= laenge))) {
        for (int i = sstart; i < send; ++i) {
            for (int j = rstart; j < rend; ++j) {
                Baubereich[i][j] = Leer::Building;
            }
        }
    }
    else {
        cout << "\n Falsche Eingabe die Werte liegen nicht in der Stadt" << endl;
    }
};

void gplatzieren() {
    cout << "\nZum bauen von Gebaeude auf der Karte werden folgende Informationen gebraucht: " << endl;
    int art;
    int rstart;
    int sstart;
    int rend;
    int send;

    cout << "\nRathaus           = 1\nSchule            = 2\nGeschaeftsgebaude = 3\nWohngebaeude      = 4\nEinkaufszentrum   = 5\nKrankenhaus       = 6 " << endl;
    cout << "\nArt des Gebaeudes(Zahl 1 - 6): " << endl;
    cin >> art;

    cout << "\nGebauede in Reihe: " << endl;
    cin >> rstart;
    cout << "\nGebauede  in Spalte: " << endl;
    cin >> sstart;

    cout << "\nLaenge: " << endl;
    cin >> rend;
    rend = rstart + rend;
    cout << "\nBreite: " << endl;
    cin >> send;
    send = sstart + send;

    if ((rend >= rstart) and (send >= sstart) and ((rstart >= 0) and (rstart <= breite)) and ((rend >= 0) and (rend <= breite)) and ((sstart >= 0) and (sstart <= laenge)) and ((send >= 0) and (send <= laenge))) {
        for (int i = sstart; i < send; ++i) {
            for (int j = rstart; j < rend; ++j) {
                switch (art)
                {
                case 1: Baubereich[i][j] = Rathaus::Building; break;
                case 2: Baubereich[i][j] = Schule::Building; break;
                case 3: Baubereich[i][j] = Geschaeftsgebaude::Building; break;
                case 4: Baubereich[i][j] = Wohngebaeude::Building; break;
                case 5: Baubereich[i][j] = Einkaufszentrum::Building; break;
                case 6: Baubereich[i][j] = Krankenhaus::Building; break;
                default: {
                    Baubereich[i][j] = Leer::Building;
                    break;
                }
                }
            }
        }
    }
    else {
        cout << "\n Falsche Eingabe die Werte liegen nicht in der Stadt" << endl;
    }
};

void bausgeben() {
    int Gesamtpreis = 0;
    for (int i = 0; i < laenge; ++i) {
        for (int j = 0; j < breite; ++j) {
            cout << Baubereich[i][j].getLabel() << " ";
            Gesamtpreis = Gesamtpreis + Baubereich[i][j].getGrundpreis() + (Baubereich[i][j].getAnzahl(0)*5) + (Baubereich[i][j].getAnzahl(1)*10) + (Baubereich[i][j].getAnzahl(2)*15);
        }
        cout << endl;
    }
    cout << "\nRathaus           = R Einzelpreis:270" << endl;
    cout << "\nSchule            = S Einzelpreis:150" << endl;
    cout << "\nGeschaeftsgebaude = G Einzelpreis:195" << endl;
    cout << "\nWohngebaeude      = W Einzelpreis:190" << endl;
    cout << "\nEinkaufszentrum   = E Einzelpreis:190" << endl;
    cout << "\nKrankenhaus       = K Einzelpreis:230" << endl;
    cout << "\nGesamtpreis: "  << Gesamtpreis << endl;
};