#include<iostream>

using namespace std;

class NodoDoble
{
    private:
    int dato;
    NodoDoble* adelante; //A la derecha 
    NodoDoble* atras; //A la izquierda

    public:

    NodoDoble(int d){
        dato=d;
        adelante=atras=NULL;
    }

    int datoNodo(){return dato;}
    void fijarNodo(int a){dato=a;}
    NodoDoble* adelanteNodo(){return adelante;}
    NodoDoble* atrasNodo(){return atras;}
    void ponerAdelante(NodoDoble* a){adelante=a;}
    void ponerAtras(NodoDoble* a){atras=a;}
};
//Crear la clase ListaDoble
class ListaDoble{
    private:
    NodoDoble* cabeza;
    NodoDoble* cola;

    public:
    ListaDoble(){ //Constructor
        cabeza = cola=NULL;
    }
    void crearLista();
    void visualizarLista();
    void insertarCabeza(int);
    void insertarDespues(int, int);
    void eliminar(int);
    //Continua las demás funciones
    void insertarFinLista(int);
    void insertarAntes(int,int);
    void modificar(int,int);
    NodoDoble* buscarDato(int);
};

//Crear la lista doble
void ListaDoble::crearLista(){
    int x;
    cout << "Termina con -1" << endl;
    do 
    {
        cin >> x;
        if (x != -1)
        {
            insertarCabeza(x);
        }
    }while (x != -1);
};

//Insertar cabeza
void ListaDoble::insertarCabeza(int dato){
    NodoDoble* nuevo=new NodoDoble(dato);
    nuevo->ponerAdelante(cabeza);
    if (cabeza!=NULL)
        cabeza->ponerAtras(nuevo);
    else
        cola=nuevo;
    cabeza=nuevo;
}

//Visualizar lista doble
void ListaDoble::visualizarLista(){
    NodoDoble* indice;
    cout<<"Atras\tDirDelDato\tDato\tAdelante"<<endl;
    for(indice=cabeza;indice!=NULL;indice=indice->adelanteNodo())
        cout<<indice->atrasNodo()<<"\t\t"<<indice<<"\t"<<indice->datoNodo()<<"\t"<<indice->adelanteNodo()<<endl;
}

void ListaDoble::insertarDespues(int datoAnterior, int dato){
    NodoDoble* nuevo=new NodoDoble(dato);
    NodoDoble* anterior;
    //Busqueda de datoAnterior
    NodoDoble *indice;
    indice=cabeza;
    while(indice!=NULL){
        if(indice->datoNodo()==datoAnterior)
            break;
        else
            indice=indice->adelanteNodo();
    }

    //Insertar el nuevo nodo
    if (indice!=NULL){
        anterior=indice;
        nuevo->ponerAdelante(anterior->adelanteNodo());
        if (anterior->adelanteNodo()!=NULL)
            (anterior->adelanteNodo())->ponerAtras(nuevo);
        anterior->ponerAdelante(nuevo);
        nuevo->ponerAtras(anterior);

        if (anterior->adelanteNodo()==NULL)
            cola=nuevo;
    }
}
////Eliminar dato
void ListaDoble::eliminar(int dato)
{
    NodoDoble* indice;
    indice=cabeza;
    //Busqueda del dato
    while(indice!=NULL)
    {
        if (indice->datoNodo()==dato)
            break;
        else
            indice=indice->adelanteNodo();
    }
    //Eliminado el nodo
    if (indice!=NULL)
    {
        //Si el dato es la cabeza
        if (indice==cabeza){
            cabeza=indice->adelanteNodo();
            cabeza->ponerAtras(NULL);
        }
        else{ //El dato esta dentro o es la cola
            (indice->atrasNodo())->ponerAdelante(indice->adelanteNodo());
            if (indice->adelanteNodo()!=NULL)
                (indice->adelanteNodo())->ponerAtras(indice->atrasNodo());
            else
                cola=indice->atrasNodo();
        }
        delete indice;
    }
}
//InsertarFinLista
void ListaDoble::insertarFinLista(int dato)
{
    NodoDoble* nuevo=new NodoDoble(dato);
    if (cola!=NULL)
    {
        nuevo->ponerAtras(cola);
        cola->ponerAdelante(nuevo);
        cola=nuevo;
    }
    else
        cabeza=cola=nuevo;
}


///InsertarAntes
void ListaDoble::insertarAntes(int datoPosterior, int dato)
{
    NodoDoble* nuevo=new NodoDoble(dato);
    NodoDoble* indice;
    indice=cabeza;
    //Busqueda del dato
    while(indice!=NULL)
    {
        if (indice->datoNodo()==datoPosterior)
            break;
        else
            indice=indice->adelanteNodo();
    }
    //Insertar el dato antes
    if (indice!=NULL)
    {
        nuevo->ponerAdelante(indice);
        //Si indice es la cabeza
        if (indice->atrasNodo()==NULL)
        {
            cabeza=nuevo;
            //indice->ponerAtras(nuevo);
        }
        else
        {
            (indice->atrasNodo())->ponerAdelante(nuevo);
            nuevo->ponerAtras(indice->atrasNodo());
            //indice->ponerAtras(nuevo);
        }
        indice->ponerAtras(nuevo);
    }
}
//Busca el nodo que contiene el dato
NodoDoble* ListaDoble::buscarDato(int dato){
    NodoDoble* indice;
    indice=cabeza;
    //Busqueda del dato
    while(indice!=NULL){
        if (indice->datoNodo()==dato)
            break;
        else
            indice=indice->adelanteNodo();
    }
    return indice;
}
//Modificar dato del nodo
void ListaDoble::modificar(int datoAntiguo, int dato){
    NodoDoble* indice;
    indice=buscarDato(datoAntiguo);
    if (indice!=NULL)
        indice->fijarNodo(dato);
}

int main(){
    ListaDoble miLista;
    miLista.crearLista();
    miLista.visualizarLista();
    miLista.modificar(7,777);
    miLista.visualizarLista();
    return 0;
}