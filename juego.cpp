#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_entidad.h"
using namespace std;


void mapa(int* _pj){
	cout<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"10 |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"9  |   |   |   |   |   |   |   |   |   |   |"<<endl;
	cout<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"8  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl;
	cout<<"7  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"6  |   |   |   |   |   |   |   |   |   |   |"<<endl;
	cout<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"5  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl;
	cout<<"4  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"3  |   |   |   |   |   |   |   |   |   |   |"<<endl;
	cout<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"2  |   |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl;
	cout<<"1  | P |   |   |   |   |   |   |   |   |   |"<<endl<<"   +---+---+---+---+---+---+---+---+---+---+"<<endl<<"     A   B   C   D   E   F   G   H   I   J  "<<endl;
	system("pause");
	return;
}

//Genera una posición aleatoria
int *_genpos(){
	int *o= new int;
	o[0]=1 + rand() % 10;
	o[1]=1 + rand() % 10;
	return o;
}

//RECIBE UN ENTERO Y RETORNA UNA LISTA DOBLE CON ESA CANTIDAD DE PARES ORDENADOS GENERADOS ALEATORIAMENTE
ListaDoble genpos(int _n,ListaDoble _l){
	ListaDoble l = ListaDoble();
	int i=1;
	int *o;
	while (i<=_n){
		o[0]=1 + rand() % 10;
		o[1]=1 + rand() % 10;
		if (o[0]==1){
			o[1]=2 + rand() % 9;
		}
		if(!l.buscar(o)&&!_l.buscar(o)){
			l.insertarOrdenado(o);
			o=new int;
			i++;
		}		
	}
	return l;
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
		u++;
		a=b;
	}
	return y;
}


bool buscar(entidad j1,entidad otro){
	int *pj=j1.getPos();
}


// en main se crean los objetos(enemigos y jugador)
int main(){
	srand(time(NULL));						// para randomizar la funcion rand() ubicada en tirardados y otras funciones del código
	setlocale(LC_CTYPE, "Spanish");			// permite más carácteres en la consola
	int pos[]={1,1};	
	int p,*o=pos;
	entidad en = entidad("a",0,0,o);							
	entidad j1 = entidad("Errësirë",3,3,o);
	ListaDoble ens = ListaDoble();
	ListaDoble cofres = ListaDoble();
	string nen[10]={"Arañas","Golems de barro","Zorros oscuros","Duendes","Esqueletos","Orcos","Golems de piedra","Espectros","Demonios","Arcangel"};
	string aliados[10]={"Arañas","Golems de barro","Zorros oscuros","Duendes","Esqueletos","Orcos","Golems de piedra","Espectros","Demonios","Arcangel"};
	for(int piso=1;piso<11;piso++){
		mapa(o);
		o[0]=1;o[1]=1;
		cout<<"Piso: "<<piso<<endl;
		en.set_Name_PA_PV(nen[piso-1],piso,piso+1);
		ens = genpos(15,ens);
		cofres = genpos(15,ens);
		int *y=_genpos();
		while(ens.buscar(y)!=NULL){
			y=_genpos();
		}
		cout<<"___________"<<endl;
		cout<<endl<<"Enemigos: "<<endl;
		en.mostrar(0);
		cout<<"Posiciones: ";
		ens.imprimir();
		cout<<endl<<"___________"<<endl<<"___________"<<endl;
		cout<<endl<<"Cofres: ";
		cofres.imprimir();
		cout<<endl<<"___________"<<endl;
		cout<<"___________"<<endl;
		cout<<endl<<"Jugador: "<<endl;
		j1.mostrar(2);
		cout<<endl<<"___________"<<endl;
		while(o[0]+o[1]<20){
			j1.setPos(tirardados(j1.getPos()));	
			if(ens.buscar(o)!=NULL){
				cout<<endl<<"___________"<<endl<<endl;
				en.mostrar(0);
				cout<<endl<<"___________"<<endl<<endl;
				j1.mostrar(2);
				if(j1.enfrentar(en)){
					ens.eliminar(o);
					cout<<endl<<"___________"<<endl<<endl<<"Victoria"<<endl<<"___________"<<endl;
				}
				else{
					cout<<endl<<"___________"<<endl<<endl<<"Derrota"<<endl<<"___________"<<endl;
					return 0;
				}
				j1.mostrar(2);
				cout<<endl;
				ens.imprimir();
			}
			cout<<"___________"<<endl<<endl;
			cout<<"Posición actual: ";j1.mostrar(1);
			cout<<endl<<"___________"<<endl;
			
		}
	}	
	return 0;
}
