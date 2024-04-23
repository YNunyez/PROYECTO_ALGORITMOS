#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
string ls="ABCDEFGHIJ";

//SE CREA LA CLASE NODODOBLE QUE CONTENDRÁ UN PUNTERO A UN ARREGLO DE DOS ELEMENTOS QUE REPRESENTARÁ UNA POSICIÓN EN EL PISO, EJ: {2,5}
class NodoDoble {
public:
	int *pos;
	NodoDoble * siguiente, * anterior;
	
	NodoDoble(int *_pos){
		pos = _pos;
		siguiente = anterior = NULL;
	}
	
	 // Funci�n para serializar un nodo en un archivo binario
    void serializar(std::ofstream& archivo) {
        archivo.write(reinterpret_cast<const char*>(pos), sizeof(int) * 2);
    }

    // Funci�n para deserializar un nodo desde un archivo binario
    void deserializar(std::ifstream& archivo) {
        archivo.read(reinterpret_cast<char*>(pos), sizeof(int) * 2);
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
	// Funci�n para serializar la lista en un archivo binario
    void serializar(std::ofstream& archivo) {
        NodoDoble *tmp = inicio;
        while (tmp != NULL) {
            tmp->serializar(archivo);
            tmp = tmp->siguiente;
        }
    }

    // Funci�n para deserializar la lista desde un archivo binario
    void deserializar(std::ifstream& archivo) {
        NodoDoble *tmp = inicio;
        while (tmp != NULL) {
            tmp->deserializar(archivo);
            tmp = tmp->siguiente;
        }
    }
    
	void insertarOrdenado(int *_pos);
	NodoDoble * buscar(int *_pos);
	NodoDoble * eliminar(int *_pos);
	bool estaVacia();
	void imprimir();
	int *getPri();
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
	
NodoDoble * ListaDoble::buscar(int *_pos){
	NodoDoble * tmp = inicio;
	while (tmp != NULL){
		if (tmp->pos[0]==_pos[0]&&tmp->pos[1]==_pos[1])
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
	}
	else
		cout << "No hay elementos" ;
}
