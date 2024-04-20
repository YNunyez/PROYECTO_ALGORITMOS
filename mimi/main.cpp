#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_entidad.h"
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

// Función para guardar la partida en un archivo JSON
static void guardarPartida(const entidad& jugador, const std::string& nombreArchivo) {
	json partida;

	// Guardar los datos del jugador
	partida["jugador"]["nombre"] = jugador.getName();
	partida["jugador"]["PV"] = jugador.getPV();
	partida["jugador"]["PV_max"] = jugador.getPV_max();
	partida["jugador"]["PA"] = jugador.getPA();
	partida["jugador"]["posicion"] = { jugador.getPos()[0], jugador.getPos()[1] };

	// Guardar la partida en un archivo JSON
	std::ofstream archivo(nombreArchivo);
	archivo << std::setw(4) << partida << std::endl;
}

// Función para cargar la partida desde un archivo JSON
static void cargarPartida(entidad& jugador, const std::string& nombreArchivo) {
	std::ifstream archivo(nombreArchivo);
	if (!archivo.is_open()) {
		std::cerr << "Error: No se pudo abrir el archivo " << nombreArchivo << std::endl;
		return;
	}

	json partida;
	archivo >> partida;

	// Cargar los datos del jugador
	jugador.set_Name_PA_PV(partida["jugador"]["nombre"], partida["jugador"]["PA"], partida["jugador"]["PV"], partida["jugador"]["PV_max"]);
	int posX = partida["jugador"]["posicion"][0];
	int posY = partida["jugador"]["posicion"][1];
	int pos[] = { posX, posY };
	jugador.setPos(pos);

}
//

static void mapa(int* _pj) {
	cout << "   +---+---+---+---+---+---+---+---+---+---+" << endl << "10 |   |   |   |   |   |   |   |   |   |   |" << endl << "   +---+---+---+---+---+---+---+---+---+---+" << endl << "9  |   |   |   |   |   |   |   |   |   |   |" << endl;
	cout << "   +---+---+---+---+---+---+---+---+---+---+" << endl << "8  |   |   |   |   |   |   |   |   |   |   |" << endl << "   +---+---+---+---+---+---+---+---+---+---+" << endl;
	cout << "7  |   |   |   |   |   |   |   |   |   |   |" << endl << "   +---+---+---+---+---+---+---+---+---+---+" << endl << "6  |   |   |   |   |   |   |   |   |   |   |" << endl;
	cout << "   +---+---+---+---+---+---+---+---+---+---+" << endl << "5  |   |   |   |   |   |   |   |   |   |   |" << endl << "   +---+---+---+---+---+---+---+---+---+---+" << endl;
	cout << "4  |   |   |   |   |   |   |   |   |   |   |" << endl << "   +---+---+---+---+---+---+---+---+---+---+" << endl << "3  |   |   |   |   |   |   |   |   |   |   |" << endl;
	cout << "   +---+---+---+---+---+---+---+---+---+---+" << endl << "2  |   |   |   |   |   |   |   |   |   |   |" << endl << "   +---+---+---+---+---+---+---+---+---+---+" << endl;
	cout << "1  | P |   |   |   |   |   |   |   |   |   |" << endl << "   +---+---+---+---+---+---+---+---+---+---+" << endl << "     A   B   C   D   E   F   G   H   I   J  " << endl;
	system("pause");
	return;
}

//Genera una posiciÃ³n aleatoria
static int* _genpos() {
	int* o = new int;
	o[0] = 1 + rand() % 10;
	o[1] = 1 + rand() % 10;
	return o;
}

//RECIBE UN ENTERO Y RETORNA UNA LISTA DOBLE CON ESA CANTIDAD DE PARES ORDENADOS GENERADOS ALEATORIAMENTE
static ListaDoble genpos(int _n, ListaDoble _l) {
	ListaDoble l = ListaDoble();
	int i = 1;
	int a, b, * o;
	while (i <= _n) {
		o[0] = 1 + rand() % 10;
		o[1] = 1 + rand() % 10;
		if ((o[0] & o[1]) == 1) {
			o[1] = 2 + rand() % 9;
		}
		if (l.buscar(o) == NULL && _l.buscar(o) == NULL) {
			l.insertarOrdenado(o);
			i++;
		}
		o = new int;
	}
	return l;
}

static int* tirardados(int* y) {
	int x, a, b, u = 0;
	a = 1 + rand() % 6;
	b = 1 + rand() % 6;
	while (u < 2) {
		cout << endl << "NUMERO: " << a << endl;
		cout << endl << "SELECCIONE DIRECCION: " << endl << endl;
		cout << "1) DERECHA" << endl;
		cout << "2) IZQUIERDA" << endl;
		cout << "3) ADELANTE" << endl;
		cout << "4) ATRAS" << endl << endl;
		cout << "SELECCION: ";cin >> x;
		switch (x) {
		case 1:
			y[0] = y[0] + a;
			if (y[0] > 10) {
				y[0] = 10;
			}
			break;
		case 2:
			y[0] = y[0] - a;
			if (y[0] < 1) {
				y[0] = 1;
			}
			break;
		case 3:

			y[1] = y[1] + a;
			if (y[1] > 10) {
				y[1] = 10;
			}
			break;
		case 4:

			y[1] = y[1] - a;
			if (y[1] < 1) {
				y[1] = 1;
			}
			break;
		}
		u++;
		a = b;
	}
	return y;
}



// en main se crean los objetos(enemigos y jugador)
int main() {
	srand(time(NULL));
	setlocale(LC_CTYPE, "Spanish");
	int pos[] = { 1, 1 };
	int p, * o = pos;
	entidad en = entidad("a", 0, 0, 0, o);
	entidad j1 = entidad("Errësirë", 3, 3, 3, o);
	ListaDoble ens = ListaDoble();
	ListaDoble cofres = ListaDoble();
	string nen[10] = { "AraÃ±as","Golems de barro","Zorros oscuros","Duendes","Esqueletos","Orcos","Golems de piedra","Espectros","Demonios","Arcangel" };
	string aliados[10] = { "" };

	// Guardar el estado inicial del juego en un archivo JSON
	std::string nombreArchivo = "partida_guardada.json";
	guardarPartida(j1, nombreArchivo);
	

	// Cargar la partida guardada desde el archivo JSON
	cargarPartida(j1, nombreArchivo);

	for (int piso = 1;piso < 11;piso++) {
		mapa(o);
		o[0] = 1;o[1] = 1;
		cout << "Piso: " << piso << endl;
		en.set_Name_PA_PV(nen[piso - 1], piso, piso + 1, piso + 1);
		ens = genpos(16, ens);
		cofres = genpos(15, ens);
		int* y = _genpos();
		while (ens.buscar(y) != NULL) {
			y = _genpos();
		}
		cout << "___________" << endl;
		cout << endl << "Enemigos: " << endl;
		en.mostrar(0);
		cout << "Posiciones: ";
		ens.imprimir();
		cout << endl << "___________" << endl << "___________" << endl;
		cout << endl << "Cofres: ";
		cofres.imprimir();
		cout << endl << "___________" << endl;
		cout << "___________" << endl;
		cout << endl << "Jugador: " << endl;
		j1.mostrar(2);
		cout << endl << "___________" << endl;
		while (o[0] + o[1] < 20) {
			j1.setPos(tirardados(j1.getPos()));
			if (ens.buscar(o) != NULL) {
				cout << endl << "___________" << endl << endl;
				en.mostrar(0);
				cout << endl << "___________" << endl << endl;
				j1.mostrar(2);
				if (j1.enfrentar(en)) {
					ens.eliminar(o);
					cout << endl << "___________" << endl << endl << "Victoria" << endl << "___________" << endl;
				}
				else {
					cout << endl << "___________" << endl << endl << "Derrota" << endl << "___________" << endl;
					return 0;
				}
				j1.mostrar(2);
				cout << endl;
				ens.imprimir();cout << endl;
			}
			if (cofres.buscar(o) != NULL) {
				cout << endl << "ApareciÃ³ un cofre..." << endl;
				cout << "Encontraste :";
				int cont = rand() % 3;
				switch (cont) {
				case 0: {
					int selec = 2 * piso - rand() % 3;
					j1.setArma(selec);
					break;
				}
				case 1:
					cout << "Aumentar PS_MAX";
					j1.setPV_max(j1.getPV_max() + 1);
					break;
				case 2:
					cout << "Recuperar PS";
					int r = j1.getPV_max() / 10;
					if (r == 0) {
						r++;
					}
					j1.setPV(j1.getPV() + r);
					break;
				}
				j1.mostrar(2);
			}
			cout << "___________" << endl << endl;
			cout << "PosiciÃ³n actual: ";j1.mostrar(1);
			cout << endl << "___________" << endl;

		}
	}
	return 0;
}