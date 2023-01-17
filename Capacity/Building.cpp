#include <string>
using namespace std;

class Building
{
public:
	int Grundpreis;
	char Label;
	int getGrundpreis();
	char getLabel();
	//MaterialListe: die Materialien sind geordnet in Holz , Metall , Kunststoff
	int Liste[3]; //also nur benötigte Anzahl jeweils von den 3Materialien
	int getAnzahl(int Position);
};
int Building::getGrundpreis() {
	return Grundpreis;
};
char Building::getLabel() {
	return Label;
};
int Building::getAnzahl(int Position) {
	return Liste[Position];
};

class Leer : public Building {
	Leer() {
		Grundpreis = 0;
		Label = '0';
		Liste[0] = 0;//Anzahl von Holz
		Liste[1] = 0;//Anzahl von Metall
		Liste[2] = 0;//Anzahl von Kunststoff
	};
};

class Rathaus : public Building {
	Rathaus() {
		Grundpreis = 100;
		Label = 'R';
		Liste[0] = 9;//Anzahl von Holz
		Liste[1] = 8;//Anzahl von Metall
		Liste[2] = 3;//Anzahl von Kunststoff
	};
};

class Schule : public Building {
	Schule() {
	Grundpreis = 50;
	Label = 'S';
	Liste[0] = 3;//Anzahl von Holz
	Liste[1] = 1;//Anzahl von Metall
	Liste[2] = 5;//Anzahl von Kunststoff
	};
};

class Geschaeftsgebaude : public Building {
	Geschaeftsgebaude() {
	Grundpreis = 40;
	Label = 'G';
	Liste[0] = 10;//Anzahl von Holz
	Liste[1] = 9;//Anzahl von Metall
	Liste[2] = 1;//Anzahl von Kunststoff
	};
};

class Wohngebaeude : public Building {
	Wohngebaeude() {
		Grundpreis = 10;
		Label = 'W';
		Liste[0] = 10;//Anzahl von Holz
		Liste[1] = 1;//Anzahl von Metall
		Liste[2] = 8;//Anzahl von Kunststoff
	};
};

class Einkaufszentrum : public Building {
	Einkaufszentrum() {
		Grundpreis = 20;
		Label = 'E';
		Liste[0] = 8;//Anzahl von Holz
		Liste[1] = 10;//Anzahl von Metall
		Liste[2] = 5;//Anzahl von Kunststoff
	};
};

class Krankenhaus : public Building {
	Krankenhaus() {
		Grundpreis = 80;
		Label = 'K';
		Liste[0] = 1;//Anzahl von Holz
		Liste[1] = 1;//Anzahl von Metall
		Liste[2] = 9;//Anzahl von Kunststoff
	};
};
