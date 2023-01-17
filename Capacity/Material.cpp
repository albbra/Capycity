#include <string>
using namespace std;

class Material
{
public:
	string Name;
	double Preis;
	string getName();
	double getPreis();
};
string Material::getName() {
	return Name;
}
double Material::getPreis() {
	return Preis;
}

class Holz : public Material {
	Holz() {
		Name = "MHolz";
		Preis = 5;
	};
};

class Metall : public Material {
	Metall() {
		Name = "MMetall";
		Preis = 10;
	};
};

class Kunststoff : public Material {
	Kunststoff() {
	Name = "MKunststoff";
	Preis = 15;
	};
};
