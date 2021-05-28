//Lista circular simplemente enlazada
#include<iostream>

using namespace std;

//La clase NodoCircular
class NodoCircular
{
    private:
    int dato;
    NodoCircular* enlace; // puntero al siguiente Nodo

    public:
    NodoCircular (int t){
        dato = t;
        enlace = this; // al principio se apunta a sí mismo
    }

    int datoNodo(){ // devuelve el dato
        return dato;
    }

    void fijarDato(int a){ // fija el dato
        dato=a;
    }

    NodoCircular* enlaceNodo(){ // devuelve nodo al que apunta
        return enlace; 
    }
    void ponerEnlace(NodoCircular* sgte){
        enlace = sgte; // enlaza con el nodo sgte
    }
};
//La clase ListaCircular
class ListaCircular
{
    private:
    NodoCircular* acceso; // Por donde se accede a la lista

    public:
    ListaCircular(){ // Constructor
        acceso=NULL; // Al principio la lista esta vacia
    }

    void crearLista();
    void visualizar();
    void insertarAcceso(int);
    void insertarDespues(int,int);
    void insertarAntes(int,int);
    void eliminar(int);
    void modificar(int,int);
};

//Crear una lista circular
void ListaCircular::crearLista()
{
    int x;
    cout << "Termina con -1" << endl;
    do {
        cin >> x;
        if (x != -1){
            insertarAcceso(x);
        }
    }while (x != -1);
};

//Inserta un dato
void ListaCircular::insertarAcceso(int dato){
    NodoCircular* nuevo;
    nuevo = new NodoCircular (dato);

    if (acceso != NULL ){
        nuevo -> ponerEnlace(acceso -> enlaceNodo());
        acceso -> ponerEnlace(nuevo); //Cierra el circulo
    }
    acceso = nuevo; //Ahora nuevo es el acceso
};

//Visualiza la lista
void ListaCircular:: visualizar(){
    NodoCircular* indice;

    if (acceso != NULL){
        indice = acceso; // siguiente nodo al de acceso
        cout<<"DirDelDato"<<"\t"<<"Dato"<<"\t"<<"Siguiente"<<endl;
        do {
            cout <<indice<< "\t" <<indice->datoNodo()<<"\t"<<indice->enlaceNodo()<<endl;
            indice = indice -> enlaceNodo();
        }while(indice != acceso);
    }
};


int main()
{
    ListaCircular miLista;
    miLista.crearLista();
    miLista.visualizar();
    return 0;
}