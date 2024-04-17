#include <cstdlib>
#include <iostream>
using namespace std;
string ls="ABCDEFG";


//SE CREA LA CLASE NODODOBLE QUE CONTENDRÁ UN PUNTERO A UN ARREGLO DE DOS ELEMENTOS QUE REPRESENTARÁ UNA POSICIÓN EN EL PISO, EJ: {2,5}
class NodoDoble {
public:
	int *pos;
	NodoDoble * siguiente, * anterior;
	
	NodoDoble(int *_pos){
		pos = _pos;
		siguiente = anterior = NULL;
	}
};


/*
SE CREA LA CLASE LISTADOBLE CON EL EXTRA DE CONTENER ESTAS FUNCIONES: SUSTITUIR(CAMBIA LA POSICIÓN, SE USA SOLO CUANDO LA LISTA TIENE UN ELEMENTO),
GETPRI(RETORNA LA POSICIÓN (PUNTERO ARRAY) ALMACENADA EN NODO INICIO DE LA LISTA, TAMBIÉN SE USA CUANDO ES UN ELEMENTO) 
*/
class ListaDoble {
	
private:
	NodoDoble * inicio;

public:
	ListaDoble(){
		inicio = NULL;
	}
	void insertarOrdenado(int *_pos);
	NodoDoble * buscar(int *_pos);
	NodoDoble * eliminar(int *_pos);
	void sustituir(int *_pos);
	bool estaVacia();
	void imprimir();
	int * getPri();
};

void ListaDoble::insertarOrdenado(int *_pos){
	NodoDoble *nuevo = new NodoDoble(_pos);
	if (inicio==NULL){
		inicio = nuevo;
		return;
	}
	
	else{
		NodoDoble *tmp=inicio;
		NodoDoble *ant=inicio;
		while(tmp!=NULL){
			if (tmp->pos[0]>=_pos[0]){
				if(tmp->anterior!=NULL){
					ant->siguiente=nuevo;
					nuevo->anterior=ant;
				}
				else{
					inicio=nuevo;
				}
				nuevo->siguiente=tmp;
				tmp->anterior=nuevo;
				
				return;
			}
			ant=tmp;
			tmp=tmp->siguiente;
		}
		ant->siguiente=nuevo;
		nuevo->anterior=ant;
		return;
	}
}

void desligar(NodoDoble *  nodo){
	if (nodo->anterior != NULL)
		nodo->anterior->siguiente = nodo->siguiente;
	if (nodo->siguiente != NULL)
		nodo->siguiente->anterior = nodo->anterior;
}

NodoDoble * ListaDoble::eliminar(int *_pos){
	if (!estaVacia()){
		NodoDoble * eliminado = buscar(_pos);
		if (eliminado != NULL){
			if (eliminado == inicio)
				inicio = inicio->siguiente;
			desligar(eliminado);
			return eliminado;
		}
	}
	return NULL;
}

void ListaDoble::sustituir(int *_pos){
	NodoDoble *nuevo = new NodoDoble(_pos);
	inicio=nuevo;
}
	
NodoDoble * ListaDoble::buscar(int *_pos){
	NodoDoble * tmp = inicio;
	while (tmp != NULL){
		if (tmp->pos == _pos)
			return tmp;
		tmp = tmp->siguiente;
	}
	return NULL;
}

bool ListaDoble::estaVacia(){
	return inicio == NULL;
}

void ListaDoble::imprimir(){
	if (!estaVacia()){
		NodoDoble * tmp = inicio;
		while (tmp != NULL){
			cout<<ls[tmp->pos[0]-1]<<","<<tmp->pos[1]<<" ; ";
			tmp = tmp->siguiente;
		}
		//cout << endl;
	}
	else
		cout << "No hay elementos" ;//<< endl;
}

int *ListaDoble::getPri(){
	return inicio->pos;
}
