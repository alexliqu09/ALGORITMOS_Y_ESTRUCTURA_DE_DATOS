#include<iostream>
#include<ctime>
#include<cstdlib>


using namespace std;

/*******************************************************/
void printArray(int [5][7], int, int);
void swap(int* , int* );
int particionamiento (int [], int , int);
void quickSort(int [], int , int );
void llenar(int [5][7], int , int );
void ordenarLetra(int [5][7], int, int);

int matriz[5][7];
/********************************************************/

/*
<Documentación>
- Alumno: Lique Lamas Alexander Leonardo
- Código : 20192196K

- Acerca del programa: 
    Este programa se ejecuta de manera automatica los 3 primeros pasos 
    es decir las preguntas del examen posteriormente se tendra que
    ingresar números del 0 al 5 y se añadira una nueva columna
    para este programa en particular llegara desde la letra A hasta la G.
    Recordar que se hara deforma descendente como se especificó en clase.
*/

int main(){
/*****************************************************************************/
/*                      Inicio del Programa                                  */
    srand(time(NULL));//generamos los números aleatorios
    
    llenar(matriz, 5, 7);//llenaremos la matriz con numeros aleatorios con las filas y columnas
    printArray(matriz, 5, 6);//recordar que el problema solo usa las 6 primeras columnas de ahi viene 
    //la columna G
    
    int arreglo_aux[7];
    //crearemos un arreglo auxiliar que usaremos en el quicksor
    for (int i=0;i<7; i++){
        arreglo_aux[i]=matriz[1][i];
    }

    cout<<"\n"; 
    quickSort(arreglo_aux, 0, 5);//recordar que quicksort se va desde la elemento mása bajo al alto
    printArray(matriz, 5, 6);//imprimir
    cout<<"\n";
    ordenarLetra(matriz, 5, 7);//para la pregunta 3 ordenar por letra segundo criterio
    printArray(matriz, 5, 6);//imprimir solo  del A al F el G lo usaremos despues
    //lo que sigue es para el final agregar una columna más 
    cout<<'\n'<<"****Ingrese los elementos de la columna G:"<<endl;
    for (int j=1;j<5; j++){
        cout << "[" << j <<"]: "; cin >> matriz[j][6];
    } 
    cout <<endl;
/*
Aplicamos los mismos pasos que arriba solo que ahora con la fila G
mencionado por el profesor no es necesiario imprimir denuevo los pasos
*/
    for (int i=0;i<7; i++){
        arreglo_aux[i]=matriz[1][i];
    }
//estas 3 últimas funciones son repetivas
    quickSort(arreglo_aux, 0, 6);
    ordenarLetra(matriz, 5, 7);
    printArray(matriz, 5, 7);

    return 0; 
}
/**********************************************************************************/
/*                   Creación de todas las Funciones                              */
void swap(int a, int b)
{
    /*
        swap: 
            -función de intercambio modificado para trabajar con las matirces
        Argumentos:
            - a: primer parámetro.
            - b: segundo parámetro.
            - matriz: esta esta dado por una variable global para facilitar los calculos.
    */
    for (int i=0; i<5; i++) {
        int aux = matriz[i][a];
        matriz[i][a] = matriz[i][b];
        matriz[i][b] = aux;
    }

}
/*****************************************************************************************/
void printArray(int arr[5][7], int rown, int colum)
{
/*
    print: 
        -Esta función se encargara de imprimir el puntero que le pasemos por parámetro.
    Argumentos:
        - arr: El primer parámetro es un puntero de tipo (int).
        - rown: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de la fila este arreglo.
        - colum: el tercer parametro de tipo int  nos indicara el tamaño de la columna este arreglo 
*/
    int i, j;
    for (j=0; j<colum; j++) cout << char(arr[0][j]+65)<< "\t";
    cout << endl;

    for (i=1; i < rown; i++){
        for (j = 0; j<colum; j++){
            cout << arr[i][j] << "\t";
        }
        cout << endl;
        
    }
}
/*****************************************************************************************/
void llenar(int arreglo[5][7], int rown, int colum){
    /*
    llenar: 
        -Esta función se encargara de llenar de número aleatorios un puntero.
    Argumentos:
        - arreglo: El primer parámetro es un puntero de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */

    int i,j;
    for (j=0; j<colum; j++) arreglo[0][j]=j; // Asignaremos A=0, B=1, ...etc
    for (i=1; i < rown; i++){ // llena de numero aleatorios lo demás
        for (j = 0; j<colum; j++){
        arreglo[i][j] = rand()%(6) + 0;
        }
    }
}
/*****************************************************************************************/
void ordenarLetra(int arr[5][7], int rown, int colum){
    /*
        OrdenarLetra:
         -Esta función tiene como objetivo resolver el problema del segundo criterio
         usaremos 2 for y un condicional if donde evaluaremos si elementos son repiten 
         y aplicarle el swap.
        
        Arguemento:
        - arr: El arreglo a usar.
        - rown : el tamaño de las filas
        - colum: el tamaños de las columnas
    */
    int i, j;
    for (j=0; j<10; j++){
        for (i=0; i<colum-1;i++){
            if(arr[1][i]==arr[1][i+1] && arr[0][i]>arr[0][i+1]){
                swap(i,i+1);
            }
        }
    }
}
/*****************************************************************************************/
int particionamiento (int arr[], int low, int high)
{
    /* 
    -Pivote: 
        Esta función toma el último elemento como pivote coloca
        el elemento pivote en su posición correcta en ordenados
        matriz adicionalmente coloca todos más pequeños a la izquierda del pivote 
        y todos los elementos mayores a la derecha
        de pivote.
    - Argumentos:
       -arr : El arreglo a usar para quicksort 
       - low: elemenot minimo
       - high: elemento maximo
    */

    int aux;
    int pivot = arr[high];    // pivote
    int i = (low - 1);  // indice de elemento más pequeño
 
    for (int j = low; j <= high- 1; j++)
    {
        // Si el elemento actual es menor que o
        // igual a pivotar
        if (arr[j] >= pivot)
        {
            i++;    // índice de incremento del elemento más pequeño
            aux=arr[i];
            arr[i]=arr[j];
            arr[j]=aux;
            swap(i, j);
        }
    }

    aux=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=aux;
    swap(i + 1, high);
    return (i + 1);
}
/*****************************************************************************************/
void quickSort(int arr[], int low, int high)
{
/* 
    quickSort:
    - La función principal que implementa QuickSort
    Argumentos:
    - arr: Matriz a ordenar,
    - low: Índice de inicio,
    - high: Índice final 
*/
    if (low < high)
    {
        /* p_i es un índice de partición, arr [p] es ahora
            en el lugar correcto */
        int p_i = particionamiento(arr, low, high);
        // Ordena los elementos por separado antes
         // partición y después de la partición 
        quickSort(arr, low, p_i - 1);
        quickSort(arr, p_i + 1, high);
    }
}
/*****************************************************************************************/