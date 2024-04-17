#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_listadoble.h"
using namespace std;


//RECIBE UN ENTERO Y RETORNA UNA LISTA DOBLE CON ESA CANTIDAD DE PARES ORDENADOS GENERADOS ALEATORIAMENTE
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
CADENA NOMBRE, 
ENTERO PV, 
ENTERO PA , 
LISTA DOBLE POS(UN ELEMENTO PARA JUGADOR, 15 PARA LOS ENEMIGOS(SE IRÁN QUITANDO CONFORME SEAN DERROTADOS)) 

LOS MÉTODOS GET RETORNA UN ATRIBUTO ACTUAL DEL OBJETO
LOS MÉTODOS SET CAMBIAN ATRIBUTOS
*/
class entidad{
	private:
		string name;
		int PV;
		int PA;
		ListaDoble pos;
	public:
		entidad(string,int,int,ListaDoble);
		void mostrar();
		string getName();
		int getPV();
		int getPA();
		ListaDoble getPos();
		void set_Name_PA_PV(string,int,int);
		void setPA(int);
		void setPV(int);
		void setPos(int);	//RECIBE UN ENTERO Y USARÁ LA FUNCIÓN -genpos()- PARA GENERAR VARIAS POCISIONES ALEATORIAS E INSERTARLAS AUTOMÁTICAMENTE A -ListaDoble pos-
		void setPosP(int *_n); // RECIBE UNA POSICIÓN Y CAMBIA LA ORIGINAL POR ESTA, ÚTIL PARA EL JUGADOR
		void atacar();		//SE ENCARGARÁ DE LOS ENFRENTAMIENTOS(INCOMPLETO DE MOMENTO)
};

entidad::entidad(string _name,int _PV, int _PA,ListaDoble _pos){
	name=_name;
	PV=_PV;
	PA=_PA;
	pos=_pos;	
}

void entidad::mostrar(){
	cout<<endl<<"___________________________________"<<endl<<endl;
	cout<<"Nombre: "<<name<<endl<<"PV: "<<PV<<endl<<"PA: "<<PA<<endl<<"Posición: ";
	pos.imprimir();
	cout<<endl<<"___________________________________"<<endl;
}

string entidad::getName(){
	return name;
}
	
int entidad::getPV(){
	return PV;
}

int entidad::getPA(){
	return PA;
}

ListaDoble entidad::getPos(){
	return pos;
}
void entidad::set_Name_PA_PV(string _name,int _PA,int _PV){
	name=_name;
	PA=_PA;
	PV=_PV;
}

void entidad::setPos(int _n){
	pos=genpos(_n);
}
void entidad::setPosP(int *_n){
	pos.sustituir(_n);
}
