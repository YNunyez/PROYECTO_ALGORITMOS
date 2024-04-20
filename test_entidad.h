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
class entidad{
	private:
		string name;
		int PV;
		int PA;
		int * pos;
		entidad * aliado1,* aliado2,* aliado3;
	public:
		entidad(string,int,int,int*);
		void mostrar(int);
		bool enfrentar(entidad);
		string getName();
		int getPV();
		int getPA();
		int *getPos();
		void setAliado(entidad,int);
		void set_Name_PA_PV(string,int,int);
		void setPA(int);
		void setPV(int);
		void setPos(int*);	//RECIBE UN ENTERO Y USARÁ LA FUNCIÓN -genpos()- PARA GENERAR VARIAS POCISIONES ALEATORIAS E INSERTARLAS AUTOMÁTICAMENTE A -ListaDoble pos-
		void atacar();		//SE ENCARGARÁ DE LOS ENFRENTAMIENTOS(INCOMPLETO DE MOMENTO)
};

entidad::entidad(string _name,int _PV, int _PA,int *_pos){
	name=_name;
	PV=_PV;
	PA=_PA;
	pos=_pos;
	aliado1=NULL;
	aliado2=NULL;
	aliado3=NULL;	
}

bool entidad::enfrentar(entidad _en){
	int det = rand() % 2;
	while (_en.PV>0 && PV>0){
		if(det == 1){
			det=0;
			_en.PV=_en.PV-PA;
			if(_en.PV<=0){
				return true;
			}
		} 
		PV=(PV-_en.PA);
		if(PV<=0){
			return false;
		}
		_en.PV=_en.PV-PA;
		if(_en.PV<=0){
			return true;
		}
	}	
}



void entidad::mostrar(int t){
	if(t==1){
		cout<<"Posición: "<<ls[pos[0]-1]<<","<<pos[1];
		return;
	}
	cout<<"Nombre: "<<name<<endl<<"PV: "<<PV<<endl<<"PA: "<<PA<<endl;
	if(t==2){
		cout<<"Posición: "<<ls[pos[0]-1]<<","<<pos[1];
	}
	return;
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

int *entidad::getPos(){
	return pos;
}
void entidad::setAliado(entidad _aliado,int _campo){
	if(_campo == 1){
		aliado1=&_aliado;
		return;
	}
	if(_campo == 2){
		aliado2=&_aliado;
		return;
	}
	aliado3=&_aliado;
}

void entidad::set_Name_PA_PV(string _name,int _PA,int _PV){
	name=_name;
	PA=_PA;
	PV=_PV;
}

void entidad::setPV(int _PV){
	PV=_PV;
}


void entidad::setPA(int _PA){
	PA=_PA;
}

void entidad::setPos(int *_pos){
	pos=_pos;
}
