#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_listadoble.h"
#include <chrono>
#include <thread>
using namespace std;

void Esperar(int sec){
	this_thread::sleep_for(chrono::seconds(sec));
	return;
} 

string l_frs[]={" ofrecerá palizas junto a tí"," te acompañará por el calabozo"," y Errësirë se cuidarán las espaldas"};
/* 
CADENA NOMBRE, 
ENTERO PV, 
ENTERO PA , 
LISTA DOBLE POS(UN ELEMENTO PARA JUGADOR, 15 PARA LOS ENEMIGOS(SE IRï¿½N QUITANDO CONFORME SEAN DERROTADOS)) 

LOS Mï¿½TODOS GET RETORNA UN ATRIBUTO ACTUAL DEL OBJETO
LOS Mï¿½TODOS SET CAMBIAN ATRIBUTOS
*/

class entidad{
	private:
		string name;
		string arma;
		int PV;
		int PV_max;
		int PA;
		int * pos;
		
	public:
		entidad * aliado1,* aliado2,* aliado3;
		entidad(string,int,int,int,int*);
		void mostrar();
		void mostrarEquipo();
		bool enfrentar(entidad);
		void abrirCofre(int);
		string getName();
		int getPV();
		int getPV_max();
		int getPA();
		string getArma();
		int *getPos();
		string printAliado(int);
		void setAliado(entidad*);
		void set_Name_PA_PV(string,int,int,int);
		void setArma(int);
		void setPV(int);
		void aumento_PV_grupo();
		void setPV_max();
		void setPos(int*);	//RECIBE UN ENTERO Y USARï¿½ LA FUNCIï¿½N -genpos()- PARA GENERAR VARIAS POCISIONES ALEATORIAS E INSERTARLAS AUTOMï¿½TICAMENTE A -ListaDoble pos-
		void atacar();		//SE ENCARGARï¿½ DE LOS ENFRENTAMIENTOS(INCOMPLETO DE MOMENTO)
};

entidad::entidad(string _name,int _PV,int _PV_max,int _PA,int *_pos){
	name=_name;
	PV=_PV;
	PV_max=_PV_max;
	PA=_PA;
	pos=_pos;
	arma="Ninguna";
	aliado1=NULL;
	aliado2=NULL;
	aliado3=NULL;
}

bool entidad::enfrentar(entidad _en){
	while(true){
		cout<<"___________"<<endl;
		cout<<endl<<"Enemigo: "<<endl;
		_en.mostrar();
		entidad *_enf = this;
		entidad **p_enf = &_enf;
		cout<<endl;
		while(true){
			int p = rand() % 4;
			switch(p){
				case 1:
					p_enf=&aliado1;
					break;
				case 2:
					p_enf=&aliado2;
					break;
				case 3:
					p_enf=&aliado2;
					break;
			} 
			if ((*p_enf)!=NULL){
				break;
			}
			p_enf=&_enf;
		}
		int det = rand() % 2;
		while (true){
			if(det == 1){
				cout<<endl<<(*p_enf)->name<<" golpea *"<<endl;
				det=0;
				_en.PV=_en.PV-(*p_enf)->PA;
				if(_en.PV<=0){
					cout<<endl<<"___________"<<endl<<endl<<"Victoria!"<<endl<<"___________"<<endl<<endl;
					system("pause");
					system("cls");
					return 1;
				}
			}
			cout<<endl<<"Enemigo golpea *"<<endl;
			(*p_enf)->PV=(*p_enf)->PV-_en.PA;
			if((*p_enf)->PV<=0){
				if((*p_enf)->name=="Errësirë"){
					cout<<endl<<"___________"<<endl<<endl<<"Errësirë ha muerto, se acabó :("<<endl<<"___________"<<endl<<endl;
					system("pause");
					system("cls");
					return 0;
				}
				cout<<endl<<"___________"<<endl<<endl<<(*p_enf)->name<<" ha sido derrotado"<<endl<<"___________"<<endl<<endl;
				*p_enf=NULL;
				system("pause");
				system("cls");
				break;
			}
			cout<<endl<<name<<" golpea *"<<endl;
			_en.setPV(_en.PV-(*p_enf)->PA);
			if(_en.PV<=0){
				cout<<endl<<"___________"<<endl<<endl<<"Victoria!"<<endl<<"___________"<<endl<<endl;
				system("pause");
				system("cls");
				return 1;
			}
		}	
	}
	return 0;
}

void entidad::abrirCofre(int s){
	cout<<endl<<"Apareció un cofre..."<<endl;
	cout<<endl;
	cout<<"Encontraste :";
	int cont = rand() % 3;
	switch(cont){
		case 0:{
			s = 2*s - rand() % 3;
			setArma(s);
			break;
		}
		case 1:
			cout<<"Aumentar PS_MAX";
			setPV_max();
			break;
		case 2:
			cout<<"Recuperar PS";
			aumento_PV_grupo();
			break;
	}
}



void entidad::mostrar(){
	cout<<"Nombre: "<<name<<endl<<"PV: "<<PV<<endl;
	return;
}

void entidad::mostrarEquipo(){
	cout<<"_________________"<<endl<<endl<<"Equipo de Errësirë"<<endl<<"_________________"<<endl;
	cout<<endl<<"Nombre: Errësirë"<<endl<<"PV: "<<PV<<"/"<<PV_max<<endl<<"Arma: "<<arma<<" (PA: "<<PA<<")"<<endl<<"_________________"<<endl;
	if (aliado1!=NULL){
		cout<<endl<<"Nombre: "<<aliado1->name<<endl<<"PV: "<<aliado1->PV<<"/"<<aliado1->PV_max<<endl<<"Arma: "<<aliado1->arma<<" (PA: "<<aliado1->PA<<")"<<endl<<"_________________"<<endl;
	}
	if (aliado2!=NULL){
		cout<<endl<<"Nombre: "<<aliado2->name<<endl<<"PV: "<<aliado2->PV<<"/"<<aliado2->PV_max<<endl<<"Arma: "<<aliado2->arma<<" (PA: "<<aliado2->PA<<")"<<endl<<"_________________"<<endl;
	}
	if (aliado3!=NULL){
		cout<<endl<<"Nombre: "<<aliado3->name<<endl<<"PV: "<<aliado3->PV<<"/"<<aliado3->PV_max<<endl<<"Arma: "<<aliado3->arma<<" (PA: "<<aliado3->PA<<")"<<endl<<"_________________"<<endl;
	}
}

string entidad::getName(){
	return name;
}
	
int entidad::getPV(){
	return PV;
}

int entidad::getPV_max(){
	return PV_max;
}

int entidad::getPA(){
	return PA;
}

int *entidad::getPos(){
	return pos;
}

string entidad::printAliado(int _pos){
	string nombre;
	if(_pos == 1){
		if(aliado1!=NULL){
			nombre=aliado1->getName();
			return nombre;
		}
		return "Desocupado";
	}
	if(_pos == 2){
		if(aliado2!=NULL){
			nombre=aliado2->getName();
			return nombre;
		}
		return "Desocupado";
	}
	if(aliado3!=NULL){
		nombre=aliado3->getName();
		return nombre;
	}
	return "Desocupado";
}

void entidad::setAliado(entidad *_al){
	char p;
	int fr = rand() % 3;
	cout<<"\n¡Encontraste una taberna y entraste";
	Esperar(1);cout<<".";Esperar(1);cout<<".";Esperar(1);cout<<"."<<endl;
	system("cls");
	cout<<"Conociste a "<<_al->getName()<<" y lo puedes unir a tu grupo!"<<endl;
	while(true){
		cout<<"Selecciona donde ubicarlo: ";
		cout<<endl;
		cout<<endl<<"1) "<<printAliado(1)<<endl;
		cout<<endl<<"2) "<<printAliado(2)<<endl;
		cout<<endl<<"3) "<<printAliado(3)<<endl;
		cout<<endl<<"4) "<<"---No quiero unirlo---"<<endl<<endl;
		cout<<"Seleccion: ";cin>>p;	
	switch(p){
		case '1':
			cout<<_al->getName()<<l_frs[fr]<<endl;
			aliado1=_al;
			return;
		case '2':
			cout<<_al->getName()<<l_frs[fr]<<endl;
			aliado2=_al;
			return;
		case '3':
			cout<<_al->getName()<<l_frs[fr]<<endl;
			aliado3=_al;
			return;
		case '4':
			cout<<"No quisite unir a "<<_al->getName()<<" a tu grupo."<<endl;
			delete _al;
			return;	
	}	
	system("cls");
	cout<<"Comando inválido"<<endl;
	system("pause");
	}
}
void entidad::set_Name_PA_PV(string _name,int _PA,int _PV,int _PV_max){
	name=_name;
	PA=_PA;
	PV=_PV;
	PV_max=_PV_max;
}
void entidad::setPV(int _PV){
	PV=_PV;
}
void entidad::aumento_PV_grupo(){
	int a;
	a=PV/10;
	if(a==0){
		a=1;
	}
	PV+=a;
	if(aliado1!=NULL){
		a=aliado1->PV/10;
		if(a==0){
			a+=1;
		}
		aliado1->PV+=a;
	}
	if(aliado2!=NULL){
		a=aliado2->PV/10;
		if(a==0){
			aliado2->PV+=1;
		}
		aliado2->PV+=a;
	}
	if(aliado3!=NULL){
		a=aliado3->PV/10;
		if(a==0){
			aliado3->PV+=1;
		}
		aliado3->PV+=a;
	}
}

void entidad::setPV_max(){
	PV_max+=1;
	if(aliado1!=NULL){
		aliado1->PV+=1;
	}
	if(aliado2!=NULL){
		aliado2->PV+=1;
	}
	if(aliado3!=NULL){
		aliado3->PV+=1;
	}
}

			/*	  3  		2			4		4		4			4			5			5		5		6		6		  6			7			  			8			      8				8			 9			 	9					9			10			11				12								13*/
			/*	  1  		2			3		4		5			6			7		   8		9		10		11		  12					13			  		14			    15			16			 		17			 18			19					20						21				22								23*/
string Armas[]={"Papa","Matamoscas","Piedra","Palo","Botella","Boomerang","Espada Rota","Daga","Manopla","Machete","Arco","Espada Persa","Miniexplosivos Arrojables","Shurikens","Arco Largo","Mazo de Guerra","Hacha de Guerra","Katana","Super Arco","Espadï¿½n de Caballero Oscuro","Espadas del Caos"};
int PAs[]={3,2,4,4,4,4,5,5,6,6,6,7,8,8,8,9,9,10,11,12,13};

void entidad::setArma(int _sel){
	int x;
	string _arma=Armas[_sel];
	int _PA=PAs[_sel];
	cout<<_arma<<" (PA:"<<_PA<<")"<<endl<<"Deseas intercambiar tu arma actual por esta ?";
	cout<<endl<<"1) Si"<<endl<<"2) No"<<endl<<endl<<"Seleccion: ";cin>>x;
	if(x==1){
		arma=_arma;
		PA=_PA;
	}
}

void entidad::setPos(int *_pos){
	pos=_pos;
}
