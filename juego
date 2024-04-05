#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_listadoble.h"
using namespace std;


void mapa(){
	cout<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"10 |   |   |   | P |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"9  |   |   |   |   |   |   |   |   |   |   |"<<endl;
	cout<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"8  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl;
	cout<<"7  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"6  |   |   |   |   |   |   |   |   |   |   |"<<endl;
	cout<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"5  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl;
	cout<<"4  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"3  |   |   |   |   |   |   |   |   |   |   |"<<endl;
	cout<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"2  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl;
	cout<<"1  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"     A   B   C   D   E   F   G   H   I   J  "<<endl;
	system("pause");
	return;
}



int *tirardados(int *y){
	int x,a,b,u=0;
	a = 1 + rand() % 6;
	b = 1 + rand() % 6;
	while (u<2){
		cout<<endl<<"NUMERO: "<<a<<endl;
		cout<<endl<<"SELECCIONE DIRECCION: "<<endl<<endl;
		cout<<"1) DERECHA"<<endl;
		cout<<"2) IZQUIERDA"<<endl;
		cout<<"3) ADELANTE"<<endl;
		cout<<"4) ATRAS"<<endl<<endl;
		cout<<"SELECCION: ";cin>>x;
		switch (x){
			case 1:
				y[0]=y[0]+a;
				if (y[0]>10){
					y[0]=10;
				}
				break;
			case 2:
				y[0]=y[0]-a;
				if (y[0]<1){
					y[0]=1;
				}
				break;
			case 3:
				
				y[1]=y[1]+a;
				if (y[1]>10){
					y[1]=10;
				}
				break;
			case 4:
				
				y[1]=y[1]-a;
				if (y[1]<1){
					y[1]=1;
				}
				break;
		}
		cout<<endl<<endl<<y[0]<<","<<y[1]<<endl;
		u++;
		a=b;
	}
	return y;
}


int * genposind(){
	int y[2];
	int *u = y;
	u[0]=1 + rand() % 10;
	u[1]=1 + rand() % 10;
	return u;
}


ListaDoble genposmul(int _n){
	ListaDoble l = ListaDoble();
	int i=1;
	int a,b,*o;
	while (i<=_n){
		o = genposind();
		/*o = int[2];
		o[0]=1 + rand() % 10;
		o[1]=1 + rand() % 10;*/
		//l.imprimir();
		l.insertarOrdenado(o);
		//l.imprimir();
		i++;
	}
	return l;
}




class entidad{
	private:
		string name;
		int PV;
		int PA;
		ListaDoble pos;
	public:
		entidad(string,int,int,ListaDoble);
		void mostrar();
		string getname();
		int getPV();
		int getPA();
		void setPos(int);
		ListaDoble getPos();
		void atacar();
};

entidad::entidad(string _name,int _PV, int _PA,ListaDoble _pos){
	name=_name;
	PV=_PV;
	PA=_PA;
	pos=_pos;	
}

void entidad::mostrar(){
	cout<<"Nombre: "<<name<<endl<<"PV: "<<PV<<endl<<"PA: "<<PA<<endl<<"pos: ";
	pos.imprimir();
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
	pos=genposmul(_n);
}
ListaDoble entidad::getPos(){
	return pos;
}





int main(){
	
	setlocale(LC_CTYPE, "Spanish");
	int pos[]={0,0};
	int p,*o=pos;
	ListaDoble posj1 = ListaDoble(),posen = ListaDoble();
	entidad en = entidad("a",0,0,posen);
	posj1.insertarOrdenado(o);
	entidad j1 = entidad("Errësirë",2,3,posj1);
	j1.mostrar();
	string nen[10]={"Arañas","Golems de barro","Zorros oscuros","Duendes","Esqueletos","Orcos","Golems de piedra","Espectros","Demonios","Arcangel"};
	en = entidad(nen[1],2,5,genposmul(15));
	
	
	//string pos[2]={"A","0"};
	int posr[2]={1,1};
	srand(time(NULL));
	string fil[10]={"1","2","3","4","5","6","7","8","9","10"};
	string col[10]={"A","B","C","D","E","F","G","H","I","J"};
	
	/*int *o=posr;
	//int *o={1,1};
	cout<<"INICIO: "<<col[o[0]-1]<<fil[o[1]-1]<<endl<<endl;
	o = tirardados(o);
	cout<<"POSICION: "<<col[o[0]-1]<<fil[o[1]-1]<<endl<<endl;
	getch();*/
	return 0;
}
