#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_listadoble.h"
using namespace std;

/*
CADENA NOMBRE,
ENTERO PV,
ENTERO PA ,
LISTA DOBLE POS(UN ELEMENTO PARA JUGADOR, 15 PARA LOS ENEMIGOS(SE IRÁN QUITANDO CONFORME SEAN DERROTADOS))

LOS MÉTODOS GET RETORNA UN ATRIBUTO ACTUAL DEL OBJETO
LOS MÉTODOS SET CAMBIAN ATRIBUTOS
*/
class entidad {
private:
	string name;
	string arma;
	int PV;
	int PV_max;
	int PA;
	int* pos;
	entidad* aliado1, * aliado2, * aliado3;
public:
	entidad(string, int, int, int, int*);
	void mostrar(int);
	bool enfrentar(entidad);
	string getName() const;
	int getPV() const;
	int getPV_max() const;
	int getPA() const;
	int getPA();
	string getArma();
	int* getPos() const;
	void setAliado(entidad, int);
	void set_Name_PA_PV(string, int, int, int);
	void setArma(int);
	void setPV(int);
	void setPV_max(int);
	void setPos(int*);	//RECIBE UN ENTERO Y USARÁ LA FUNCIÓN -genpos()- PARA GENERAR VARIAS POCISIONES ALEATORIAS E INSERTARLAS AUTOMÁTICAMENTE A -ListaDoble pos-
	void atacar();		//SE ENCARGARÁ DE LOS ENFRENTAMIENTOS(INCOMPLETO DE MOMENTO)
};

entidad::entidad(string _name, int _PV, int _PV_max, int _PA, int* _pos) {
	name = _name;
	PV = _PV;
	PV_max = _PV_max;
	PA = _PA;
	pos = _pos;
	aliado1 = NULL;
	aliado2 = NULL;
	aliado3 = NULL;
}

bool entidad::enfrentar(entidad _en) {
	int det = rand() % 2;
	while (_en.PV > 0 && PV > 0) {
		if (det == 1) {
			det = 0;
			_en.PV = _en.PV - PA;
			if (_en.PV <= 0) {
				return true;
			}
		}
		PV = (PV - _en.PA);
		if (PV <= 0) {
			return false;
		}
		_en.PV = _en.PV - PA;
		if (_en.PV <= 0) {
			return true;
		}
	}
}

inline string entidad::getName() const
{
	return string();
}

inline int entidad::getPV() const
{
	return 0;
}

inline int entidad::getPV_max() const
{
	return 0;
}

inline int entidad::getPA() const
{
	return 0;
}



void entidad::mostrar(int t) {
	if (t == 1) {
		cout << "Posicion: " << ls[pos[0] - 1] << "," << pos[1];
		return;
	}
	cout << "Nombre: " << name << endl << "PV: " << PV << "/" << PV_max << endl << "PA: " << PA << endl;
	if (t == 2) {
		cout << "Posicion: " << ls[pos[0] - 1] << "," << pos[1];
	}
	return;
}

string entidad::getName() const {
	return name;
}

int entidad::getPV() const {
	return PV;
}

int entidad::getPV_max() const {
	return PV_max;
}

int entidad::getPA() {
	return PA;
}

inline string entidad::getArma()
{
	return string();
}

inline int* entidad::getPos() const
{
	return nullptr;
}

int* entidad::getPos() const {
	return pos;
}
void entidad::setAliado(entidad _aliado, int _campo) {
	if (_campo == 1) {
		aliado1 = &_aliado;
		return;
	}
	if (_campo == 2) {
		aliado2 = &_aliado;
		return;
	}
	aliado3 = &_aliado;
}

void entidad::set_Name_PA_PV(string _name, int _PA, int _PV, int _PV_max) {
	name = _name;
	PA = _PA;
	PV = _PV;
	PV_max = _PV_max;
}

void entidad::setPV(int _PV) {
	PV = _PV;
}
void entidad::setPV_max(int _PV_max) {
	PV_max = _PV_max;
}
/*	  3  		2			4		4		4			4			5			5		5		6		6		  6			7			  			8			      8				8			 9			 	9					9			10			11				12								13*/
/*	  1  		2			3		4		5			6			7		   8		9		10		11		  12					13			  		14			    15			16			 		17			 18			19					20						21				22								23*/
string Armas[] = { "Papa","Matamoscas","Piedra","Palo","Botella","Boomerang","Espada Rota","Daga","Manopla","Machete","Arco","Espada Persa","Miniexplosivos Arrojables","Shurikens","Arco Largo","Mazo de Guerra","Hacha de Guerra","Katana","Super Arco","Espadón de Caballero Oscuro","Espadas del Caos" };
int PAs[] = { 3,2,4,4,4,4,5,5,6,6,6,7,8,8,8,9,9,10,11,12,13 };

void entidad::setArma(int _sel) {
	int x;
	string _arma = Armas[_sel];
	int _PA = PAs[_sel];
	cout << _arma << " (PA:" << _PA << ")" << endl << "Deseas intercambiar tu arma actual por esta ?";
	cout << endl << "1) Sí" << endl << "2) No" << endl << endl << "Seleccion: ";cin >> x;
	if (x == 1) {
		arma = _arma;
		PA = _PA;
	}
}

void entidad::setPos(int* _pos) {
	pos = _pos;
}

inline void entidad::atacar()
{
}

void entidad::setPos(int* _pos) {
	pos = _pos;
}