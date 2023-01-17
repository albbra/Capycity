#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Albert Brandt Capacity FProg

//Enum
enum Gebaeudetyp {
    Leer = 0,
    Rathaus = 1,
    Schule = 2,
    Geschaeftsgebaude = 3,
    Wohngebaeude = 4,
    Einkaufszentrum = 5,
    Krankenhaus = 6
};
//Funktionen
void Laufzeit();
void gplatzieren();
void bloeschen();
void bausgeben();


//globale Variablen
bool nbeendet = true;
int laenge;
int breite;
vector<vector<Gebaeudetyp>> Baubereich;


int main()
{
    cout << "Capacity Simulationstool startet nun ...\n" << endl;
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
        Baubereich.push_back(vector<Gebaeudetyp>());
        for (int j = 0; j < breite; ++j) {
            Baubereich[i].push_back(Gebaeudetyp::Leer);
        }
    }
    //Programm laufzeit
    while (nbeendet == true) {
        Laufzeit();
    }

    return 0;
}

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
        case  2: bloeschen();break;
        case  3: bausgeben();break;
        case  4: nbeendet=false ;break;
        default:
            cout << "Fehler! Aktion unbekannt! Bitte neu versuchen!" << endl;
            Laufzeit();
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
        for (int i = sstart; i <= send; ++i) {
            for (int j = rstart; j <= rend; ++j) {
                Baubereich[i][j] = Leer;
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
                case 1: Baubereich[i][j] = Rathaus; break;
                case 2: Baubereich[i][j] = Schule; break;
                case 3: Baubereich[i][j] = Geschaeftsgebaude; break;
                case 4: Baubereich[i][j] = Wohngebaeude; break;
                case 5: Baubereich[i][j] = Einkaufszentrum; break;
                case 6: Baubereich[i][j] = Krankenhaus; break;
                    default: {
                        Baubereich[i][j] = Leer;
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
    for (int i = 0; i < laenge; ++i) {
        for (int j = 0; j < breite; ++j) {
            cout << Baubereich[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nRathaus           = 1\nSchule            = 2\nGeschaeftsgebaude = 3\nWohngebaeude      = 4\nEinkaufszentrum   = 5\nKrankenhaus       = 6 " << endl;
};
