#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include "test_entidad.h"
#include <stdio.h>
using namespace std;
const int FILAS = 11;
const int COLUMNAS = 11;

string mapa[FILAS][COLUMNAS] = {
    {"  " , "A", "B", "C", "D", "E", "F", "G", "H", "I", "J"},
    {" 1", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" 2", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" 3", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" 4", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" 5", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" 6", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" 7", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" 8", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {" 9", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
    {"10"," ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
};

void _mapa(int *g,int *h) {
    // Agregar una letra en la posiciÃ³n C, 10
    
    mapa[g[1]][g[0]] = "P"; // Fila 10, Columna 3 (la indexaciÃ³n comienza desde 0)
	mapa[h[1]][h[0]] = "A";
    // Imprimir el mapa
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
	mapa[g[1]][g[0]] = " ";
	mapa[h[1]][h[0]] = " ";
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
	int a,b,*o;
	while (i<=_n){
		o[0]=1 + rand() % 10;
		o[1]=1 + rand() % 10;
		if((o[0]&&o[1])==1){
			o[1]=2 + rand() % 9;
		}
		if(l.buscar(o)==NULL&&_l.buscar(o)==NULL){
			l.insertarOrdenado(o);
			i++;
		}
		o=new int;		
	}
	return l;
}

int *tirardados(int *y,int *al,int h){
	char x;
	int a,b,u=0;
	a = 1 + rand() % 6;
	b = 1 + rand() % 6;
	while (u<2){
		cout<<"Piso: "<<h<<endl;
		_mapa(y,al);
		cout<<endl<<"Numero: "<<a<<endl;
		cout<<endl<<"Seleccione direccion: "<<endl<<endl;
		cout<<"1) Izquierda"<<endl;
		cout<<"2) Derecha"<<endl;
		cout<<"3) Atras"<<endl;
		cout<<"4) Adelante"<<endl<<endl;
		cout<<"Seleccion: ";cin>>x;
		switch (x){
			case '1':
				y[0]=y[0]-a;
				if (y[0]<1){
					y[0]=1;
				}
				u++;
				a=b;
				break;
			case '2':
				y[0]=y[0]+a;
				if (y[0]>10){
					y[0]=10;
				}
				u++;
				a=b;
				break;
			case '3':
				y[1]=y[1]+a;
				if (y[1]>10){
					y[1]=10;
				}
				u++;
				a=b;
				break;
			case '4':
				y[1]=y[1]-a;
				if (y[1]<1){
					y[1]=1;
				}
				u++;
				a=b;
				break;
			default:
				system("cls");
				cout<<"Comando inválido"<<endl;
				system("pause");
		}
		system("cls");		
	}
	return y;
}

void asignar_aliado(entidad al,entidad *j1){
	char p;
	cout<<"¡Encontraste una taberna y entraste..."<<endl<<endl;
	system("pause");system("cls");
	cout<<"Conociste a "<<al.getName()<<" y lo puedes unir a tu grupo!"<<endl;
	while(true){
		cout<<"Selecciona donde ubicarlo: ";
		cout<<endl;
		cout<<endl<<"1)"<<j1->printAliado(1)<<endl;
		cout<<endl<<"2)"<<j1->printAliado(2)<<endl;
		cout<<endl<<"3)"<<j1->printAliado(3)<<endl;
		cout<<endl<<"4)"<<"---No quiero unirlo---"<<endl<<endl;
		cout<<"Seleccion: ";cin>>p;	
		cout<<endl<<endl;
		if('0'<p<'4'){
			j1->setAliado(al,p);
			cout<<al.getName()<<" se ha unido a tu grupo!"<<endl;
			return;
		}
		if(p=='4'){
			cout<<"Decidiste no agregar a "<<al.getName()<<" a tu grupo";
			return;
		}
		system("cls");
		cout<<"Comando inválido"<<endl;
		system("pause");
	}
	
}


// en main se crean los objetos(enemigos y jugador)
int main(){
	srand(time(NULL));						// para randomizar la funcion rand() ubicada en tirardados y otras funciones del código
	setlocale(LC_CTYPE, "Spanish");			// permite más carácteres en la consola
	int pos[]={1,1};	
	int p,d,*o=pos,*k,*v;
	char m;
	entidad en = entidad("a",0,0,0,k);		
						
	entidad *j1 = new entidad("Errësirë",100,100,100,o);
	
	ListaDoble ens = ListaDoble();
	ListaDoble cofres = ListaDoble();
	string nen[10]={"Araña","Golem de barro","Zorro oscuros","Duende","Esqueleto","Orco","Golem de piedra","Espectro","Demonio","Arcangel"};
	string aliados[10]={"Juan","Pedro","Jose","Rodolfo","David","Arturo","Germán","Victor","Ignacio","Gonzalo"};
	for(int piso=1;piso<11;piso++){
		o[0]=1;o[1]=1;
		cout<<endl;
		en.set_Name_PA_PV(nen[piso-1],piso,piso+1,piso+1);
		ens = genpos(16,ens);
		cofres = genpos(15,ens);
		int *y=_genpos();
		while(ens.buscar(y)!=NULL or cofres.buscar(y)!=NULL){
			y=_genpos();
		}
		/*
		cout<<"___________"<<endl;
		cout<<endl<<"Enemigos: "<<endl;
		en.mostrar(0);
		cout<<"Posiciones: ";
		ens.imprimir();
		cout<<endl<<"___________"<<endlcout<<"___________"<<endl;
		cout<<endl<<"Cofres: ";
		cofres.imprimir();
		cout<<endl<<"___________"<<endl;
		cout<<"___________"<<endl;
		cout<<endl<<"Jugador: "<<endl;
		j1->mostrar(2);
		cout<<endl<<"___________"<<endl;*/
		system("cls");
		while(o[0]+o[1]<20){
			j1->setPos(tirardados(j1->getPos(),y,piso));	
			if(ens.buscar(o)!=NULL){
				cout<<"___________"<<endl;
				cout<<endl<<"Enemigo: "<<endl;
				en.mostrar(0);
				p = rand() % 4;
				entidad *enfrentado = new entidad("",0,0,0,o);
				switch(p){
					case 0:
						enfrentado=j1;
						break;
					case 1:
						enfrentado=j1->aliado1;
						break;
					case 2:
						enfrentado=j1->aliado2;
						break;
					case 3:
						enfrentado=j1->aliado2;
						break;
				} 
				if(j1->enfrentar(en)){
					ens.eliminar(o);
					cout<<endl<<"___________"<<endl<<endl<<"Victoria"<<endl<<"___________"<<endl<<endl;
				}
				else{
					cout<<endl<<"___________"<<endl<<endl<<"Derrota"<<endl<<"___________"<<endl<<endl;
					return 0;
				}
				j1->mostrar(0);
				system("pause");
				system("cls");
			}
			if(cofres.buscar(o)!=NULL){
				cout<<endl<<"Apareció un cofre..."<<endl;
				cout<<endl;
				cout<<"Encontraste :";
				int cont = rand() % 3;
				switch(cont){
					case 0:{
						p = 2*piso - rand() % 3;
						j1->setArma(p);
						break;
					}
					case 1:
						cout<<"Aumentar PS_MAX";
						j1->setPV_max(j1->getPV_max()+1);
						break;
					case 2:
						cout<<"Recuperar PS";

						p=j1->getPV_max()/10;
						if (p==0){
							p++;
						}
						j1->setPV(j1->getPV()+p);
						if(j1->getPV()>j1->getPV_max()){
							j1->setPV(j1->getPV_max());
						}
						break;
				}
				cout<<endl;
				j1->mostrar(0);
				system("pause");
				system("cls");
			}
			if(o[0]==y[0]&&o[1]==y[1]){
				entidad aly = entidad(aliados[piso-1],piso+1,piso+1,piso,o);
				asignar_aliado(aly,j1);
				/*if (p!=0){
					j1->setAliado(aly,p);
				}*/
			}
			
		}
	}	
	return 0;
}
