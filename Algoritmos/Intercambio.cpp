#include "iostream"
#include "ctime"
#include "cstdlib"

void llenar(int *, int);
void print(int *, int);
void intercambio(int *, int );

int main(){

    srand(time(NULL)); //Inicializamos los números aleatorios.
    
    int n = 10, *puntero = new int [n]; //Inicialiazamos el puntero y su tamaño.
    std::cout <<"****Arreglo de Numeros****" <<std::endl;
    llenar(puntero, n);//LLamamos a la función llenar.
    print(puntero, n);//LLamamos a la función print.
    intercambio(puntero, n); //LLamamos ala función intercambio.
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

void intercambio(int *puntero, int size){
    /*
    intercambio: 
        -Esta función se encargara de realizar el ordenamiento del puntero.
    Argumentos:
        - puntero: El primer parámetro es un puntero de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */
    for(int i=0; i < size - 1; i++){
        for(int j = i + 1; j < size ; j++){
            if(puntero[i] > puntero[j]){
                int aux = puntero[i];
                puntero[i] = puntero[j];
                puntero[j] = aux;
            }
        }
    }
}
