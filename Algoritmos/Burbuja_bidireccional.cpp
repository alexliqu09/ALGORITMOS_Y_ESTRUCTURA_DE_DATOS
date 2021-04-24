#include "iostream"
#include "ctime"
#include "cstdlib"

using namespace std;

void llenar(int [], int);
void print(int [], int);
void burbuja_bidireccional(int [100], int );

/*
<Documentación>

Para iniciar el programa debe digitar el tamaño del arreglo, esto generará un
arreglo aleatorio que posteriormente será ordenado e imprimiendo los pasos
que realiza de derecha hacia izquierda y pasos de izquierda hacia derecha.

*/
int main(){

/***********************************************************************************/
/*                       Inicialición de los datos                                   */
    
    srand(time(NULL)); //Inicializamos los números aleatorios.
    
    int dimension; //Creamos una variable para el tamaño del arreglo.
    cout << "\n********Ingrese el tamaño del arreglo********" << endl;
    cin >> dimension;
 
    cout << "**********Arreglo de Numeros**************"  << endl;
   
    int array[dimension]; //Inicialiazamos el array
    llenar(array, dimension); //Llamamos a la función llenar.
    print(array, dimension);//LLamamos a la función print.

/*************************************************************************************/   
/*                    Aplicando la función de ordenación                               */

    burbuja_bidireccional(array, dimension); //Usamos la función burbuja bidireccional.

    return 0;
}

/**************************** Creacion de Funciones *****************************************/

void llenar(int array[], int size){
    /*
    llenar: 
        -Esta función se encargara de llenar de número aleatorios un arreglo.
    Argumentos:
        - arreglo: El primer parámetro es un arreglo de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este arreglo.
    */
    for(int i=0; i < size; i++){
        array[i] =  rand()%(100 + 1 -1) + 1;
    }
}

void print(int  array [], int size){
    /*
    print: 
        -Esta función se encargara de imprimir el puntero que le pasemos por parámetro.
    Argumentos:
        - arreglo: El primer parámetro es un puntero de tipo (int).
        - size:    Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este arreglo.
    */
    for(int i=0; i < size; i++){
        cout <<array[i] <<" ";
    }
    cout << endl;
}


void burbuja_bidireccional(int array[], int size){
    /*
        burbuja_bidireccional:
            - Esta función se encargara de aplicar el ordenamiento burbuja bidireccional
              Se usara un for para hacer  el recorrido de  der hacia la izq usando un
              condicional de si el elemento anterior es mayor al posterior aplicamos un swap
              y actualizando la posición ultimo para asi acotar.
              de igual manera un segundo for para izq hacia la der y todo esto mientras 
              izq < der.
        Argumentos:
            - array : El arreglo que usaremos para ordenar.
            - size: El tamaño del arreglo.
    */

/*            Declaración e Inicialización de variable            */
    int i, j, izq = 1, der = size - 1, ultimo = size - 1, aux;

    do {

/*            Paso hacia la izquierda           */

        for(i = der; i >= izq; i--){
            if(array[i-1] > array[i]){
                aux = array[i];
                array[i] = array[i-1];
                array[i-1] = aux;
                ultimo = i;
            }
        }

        izq = ultimo + 1;
        cout<<"*********************************"<<endl;
        cout<<"Paso hacia la izquierda"<<endl;
        print(array, size);

/*           Paso hacia la derecha              */

        for(j = izq; j <= der; j++){
            if(array[j-1] > array[j]){
                aux = array[j];
                array[j] = array[j-1];
                array[j-1] = aux;
                ultimo = j;
            }
        }
        
        der = ultimo - 1;
        cout<<"Paso hacia la derecha"<<endl;
        print(array, size);   
        
    }while(izq < der);

}

/**********************************************************************************************/