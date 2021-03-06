#include "iostream"
#include "ctime"
#include "cstdlib"

void llenar(int *, int);
void print(int *, int);
void seleccion(int *, int );

int main(){

    srand(time(NULL)); //Inicializamos los números aleatorios.
    
    int n = 10, *puntero = new int [n]; //Inicialiazamos el puntero y su tamaño.
    
    std::cout <<"****Arreglo de Numeros****" <<std::endl;
    llenar(puntero, n);//LLamamos a la función llenar.
    print(puntero, n);//LLamamos a la función print.
    seleccion(puntero, n); //LLamamos ala función seleccion.
    std::cout <<"****Ordenación de Arreglo de Numeros****" <<std::endl;
    print(puntero, n);//LLamamos a la función print.

    delete [] puntero;//Liberando memoria.

    return 0;
}

void llenar(int* puntero, int size){
    /*
    llenar: 
        -Esta función se encargara de llenar de número aleatorios un puntero.
    Argumentos:
        - puntero: El primer parámetro es un puntero de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */
    for(int i=0; i < size; i++){
        puntero[i] = rand()%(100 + 1 -1) + 1;
    }
}

void print(int* puntero, int size){
    /*
    print: 
        -Esta función se encargara de imprimir el puntero que le pasemos por parámetro.
    Argumentos:
        - puntero: El primer parámetro es un puntero de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */
    for(int i=0; i < size; i++){
        std::cout <<puntero[i] <<" ";
    }
    std::cout <<std::endl;
}

void seleccion(int* puntero, int size){
    /*
    Selección: 
        -Esta función se encargara de realizar el ordenamiento del puntero mediante seleccion.
    Argumentos:
        - puntero: El primer parámetro es un puntero de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */
    int minimo_indice;
    for(int i=0; i < size - 1; i++){
        minimo_indice = i;
        for(int j= i + 1; j < size; j++){
            if(puntero[minimo_indice] > puntero[j]){
                minimo_indice = j;               
            }
        }
            if(i != minimo_indice){
                int aux = puntero[i];
                puntero[i] = puntero[minimo_indice]; 
                puntero[minimo_indice] = aux;               
            }
    }
}