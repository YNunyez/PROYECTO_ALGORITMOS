#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_entidad.h"
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
		u++;
		a=b;
	}
	return y;
}

// en main se crean los objetos(enemigos y jugador)
int main(){
	srand(time(NULL));				// para randomizar la funcion rand() ubicada en tirardados y otras funciones del código
	setlocale(LC_CTYPE, "Spanish");			// permite más carácteres en la consola
	int pos[]={1,1};	
	int p,*o=pos;
	ListaDoble posj1 = ListaDoble(),posen = ListaDoble();
	entidad en = entidad("a",0,0,posen);							
	posj1.insertarOrdenado(o);
	entidad j1 = entidad("Errësirë",3,3,posj1);
	string nen[10]={"Arañas","Golems de barro","Zorros oscuros","Duendes","Esqueletos","Orcos","Golems de piedra","Espectros","Demonios","Arcangel"};
	
	for(int piso=1;piso<11;piso++){
		cout<<"Piso: "<<piso<<endl;
		en.set_Name_PA_PV(nen[piso-1],piso,piso+1);
		cout<<"Enemigos: ";
		en.mostrar();
		cout<<"Jugador: ";
		j1.mostrar();
		j1.setPosP(tirardados(posj1.getPri()));	
		j1.mostrar();
	}	
	return 0;
}
