#include "iostream"
#include "ctime"
#include "cstdlib"

using namespace std;

void llenar(int [], int);
void print(int [], int);
void burbuja_bidireccional(int [100], int );

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
    burbuja_bidireccional(array, dimension); //Usamos la función burbuja bidireccional.

    return 0;
}

/************************ Creacion de Funciones *****************************************/

void llenar(int array[], int size){
    /*
    llenar: 
        -Esta función se encargara de llenar de número aleatorios un arreglo.
    Argumentos:
        - arreglo: El primer parámetro es un arreglo de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
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
        - size:    Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */
    for(int i=0; i < size; i++){
        cout <<array[i] <<" ";
    }
    cout << endl;
}


void burbuja_bidireccional(int array[100], int size){

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