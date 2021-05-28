#include<iostream>

using namespace std;

class Nodo
{
    private:
    int dato; //Dato del nodo
    Nodo* enlace; //Direccion a otro Nodo, o sea apunta a otro Nodo
    
    public:
    Nodo(int d){
        dato=d; //Asigna el dato=t a Este Nodo
        enlace=NULL; //Este nodo apunta a NULL
    }

    Nodo(int d,Nodo* n){
        dato=d;
        enlace=n;
    }

    int datoNodo(){ //Devuelve el dato
        return dato;
    }

    Nodo* enlaceNodo(){//Devuelve la direccion
        return enlace;
    }

    void ponerEnlace(Nodo* sgte){
        enlace=sgte;
    }
};
//La clase Lista
class Lista
{
    private:
    Nodo* primero;

    public:
    Lista(){ //Constructor
        primero = NULL;
    }

    void crearLista();
    void visualizarLista();
    //Continua las demás funciones
    void insertarCabeza(int);
    Nodo* ultimoNodo();
    void insertarUltimo(int);
    Nodo* buscarLista(int);
    void insertarDespues(int,int);
    void eliminar(int);
    void insertaOrden(int);
};

//Crear una lista
void Lista::crearLista(){
    int x;
    cout << "Termina con -1" << endl;
    do {
        cin >> x;
        if (x != -1){ //El nuevo primero
            //primero = new Nodo(x,primero);
            insertaOrden(x);
        }   
    }while (x != -1);
};

//Visualizar una lista
void Lista::visualizarLista(){
    Nodo* indice;
    cout<<"Direccion del nodo\tDato\tAdonde a punta"<<endl;
    for(indice=primero;indice!=NULL;indice=indice->enlaceNodo())
        cout<<indice<<"\t\t"<<indice->datoNodo()<<"\t"<<indice->enlaceNodo()<<endl;
}

//Insertar nodo en la cabeza de la lista
void Lista::insertarCabeza(int dato)
{
    Nodo* nuevo;
    nuevo=new Nodo(dato);
    nuevo->ponerEnlace(primero);
    primero=nuevo;
}

//Encontrar la Cola o sea el ultimo nodo de la lista
Nodo* Lista::ultimoNodo()
{
    Nodo* indice=primero;
    while (indice->enlaceNodo()!=NULL)
        indice=indice->enlaceNodo();
    return indice;
}

void Lista::insertarUltimo(int dato)
{
    Nodo* nuevo=new Nodo(dato);
    Nodo* ultimo=ultimoNodo();
    ultimo->ponerEnlace(nuevo);
}

Nodo* Lista::buscarLista(int dato)
{
    Nodo* indice;
    for (indice=primero;indice!=NULL;indice=indice->enlaceNodo())
        if (indice->datoNodo()==dato)
            return indice;
    return NULL; //Si no lo encuentra retorna un NULL
}

void Lista::insertarDespues(int datoAnt,int dato)
{
    Nodo* nuevo=new Nodo(dato);
    Nodo* anterior; //El nodo que quedara anterior al nuevo nodo
    anterior=Lista::buscarLista(datoAnt);
    nuevo->ponerEnlace(anterior->enlaceNodo());
    anterior->ponerEnlace(nuevo);
}

void Lista::eliminar(int dato)
{
    Nodo* indice, *anterior;
    indice=primero;
    anterior=NULL;
    //Encontrando al nodo que es igual al dato
    if (primero->datoNodo()==dato)
    {
        primero=primero->enlaceNodo();
        delete indice;
    }
    else
    {
        while(indice!=NULL)
        {
            if (indice->datoNodo()==dato)
                break;
            else
                anterior=indice;

            indice=indice->enlaceNodo();
        }
        if (indice!=NULL)
        {
            anterior->ponerEnlace(indice->enlaceNodo());
            delete indice;
        }
    }
}

void Lista::insertaOrden(int dato)
{
    Nodo* nuevo=new Nodo(dato);
    if (primero==NULL) //Lista vacia
        primero=nuevo;
    else if(dato<primero->datoNodo())
    {
        nuevo->ponerEnlace(primero);
        primero=nuevo;
    }
    else
    {
        Nodo* indice, *anterior;
        indice=primero;
        anterior=NULL;
        while(indice!=NULL)
        {
            if (dato>=indice->datoNodo()) //El dato es el menor de todos
            {
                anterior=indice;
            }
            else
                break;
            indice=indice->enlaceNodo();
        }
        if (indice!=NULL) //El dato esta en el interior
        {
            nuevo->ponerEnlace(anterior->enlaceNodo());
            anterior->ponerEnlace(nuevo);
        }
        else //El dato es mayor que todos
        {
            anterior->ponerEnlace(nuevo);
        }
    }
}
///////////////////////////
int main()
{
    Lista miLista;
    miLista.crearLista();
    miLista.visualizarLista();
    //miLista.insertarCabeza(777);
    //miLista.visualizarLista();
    //miLista.insertarUltimo(888);
    //miLista.visualizarLista();
    //miLista.insertarDespues(777,999);
    //miLista.visualizarLista();
    //miLista.eliminar(555);
    //miLista.visualizarLista();
    return 0;
}