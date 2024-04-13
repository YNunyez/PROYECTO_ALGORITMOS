#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_listadoble.h"
using namespace std;

/*
ESTA FUNCIÓN RECIBE UN NÚMERO ENTERO Y REGRESA UNA LISTADOBLE CON UNA CANTIDAD ORDENADA DE POSICIONES ALEATORIAS DE ACUERDO AL NÚMERO RECIBIDO
*/
ListaDoble genpos(int _n){
	ListaDoble l = ListaDoble();
	int i=1;
	int a,b,*o;
	while (i<=_n){
		o[0]=1 + rand() % 10;
		o[1]=1 + rand() % 10;
		if(!l.buscar(o)){
			l.insertarOrdenado(o);
		}
		o=new int;
		i++;
	}
	return l;
}

/*
LA CLASE ENTIDAD VA A DEFINIR EL COMPORTAMIENTO DE ENEMIGOS, ALIADOS Y JUGADOR. SUS ATRIBUTOS SON LAS CARACTERÍSTICAS QUE TODA ENTIDAD DEBE DE TENER
*/
class entidad{
	private:
		string name;
		int PV;
		int PA;
		ListaDoble pos;
	public:

//CONSTRUCTOR
		entidad(string,int,int,ListaDoble);
//FUNCIONES
		void mostrar();
    void atacar();
//GETTERS(OBTENER INFORMACION DEL OBJETO) Y SETTERS(CAMBIAR INFORMACION)
		string getname();
		int getPV();
		int getPA();
		void setPos(int);
		void setPosP(int *_n);
		ListaDoble getPos();
		
};

entidad::entidad(string _name,int _PV, int _PA,ListaDoble _pos){
	name=_name;
	PV=_PV;
	PA=_PA;
	pos=_pos;	
}

void entidad::mostrar(){
	cout<<"Nombre: "<<name<<endl<<"PV: "<<PV<<endl<<"PA: "<<PA<<endl<<"Posición: ";
	pos.imprimir();
	cout<<endl<<"___________________________________"<<endl;
}

string entidad::getname(){
	return name;
}
	
int entidad::getPV(){
	return PV;
}

int entidad::getPA(){
	return PA;
}

void entidad::setPos(int _n){
	pos=genpos(_n);
}
void entidad::setPosP(int *_n){
	pos.sustituir(_n);
}

ListaDoble entidad::getPos(){
	return pos;
}
