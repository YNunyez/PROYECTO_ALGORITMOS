#include <cstdlib>
#include <iostream>
using namespace std;

class NodoDoble {
public:
	int *pos;
	NodoDoble * siguiente, * anterior;
	
	NodoDoble(int *_pos){
		pos = _pos;
		siguiente = anterior = NULL;
	}
};

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
	bool estaVacia();
	void imprimir();
	NodoDoble * pri();
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
				nuevo->siguiente=tmp;
				tmp->anterior=nuevo;
				if(tmp->anterior!=NULL){
					ant->siguiente=nuevo;
					nuevo->anterior=ant;
				}
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
			cout<<tmp->pos[0]<<","<<tmp->pos[1]<<" ; ";
			tmp = tmp->siguiente;
		}
		cout << endl;
	}
	else
		cout << "No hay elementos" << endl;
}

NodoDoble *ListaDoble::pri(){
	return inicio;
}
