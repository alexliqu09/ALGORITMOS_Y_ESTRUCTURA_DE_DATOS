#include "iostream"
#include "ctime"
#include "cstdlib"

void llenar(int *, int);
void print(int *, int);
void intercambio(int *, int );
void burbuja(int* puntero, int size);
void seleccion(int* puntero, int size);
void insercion(int* puntero, int size);
int* anadir(int *, int );
void limpiar(int *);

int main(){

    srand(time(NULL)); //Inicializamos los números aleatorios.
    
    int n = 10, *puntero = new int [n]; //Inicialiazamos el puntero y su tamaño.
    
    llenar(puntero, n);//LLamamos a la función llenar.
    
    int opc=0;
    while(true){
        //llenar(puntero, n);
        std::cout <<"****Arreglo de Numeros****" <<std::endl;
        print(puntero, n);//LLamamos a la función print.
        std::cout << " **** Menu ****\n";
        std::cout << " 1) Anadir a lista\n";
        std::cout << " 2) Limpiar listas\n";
        std::cout << " 3) Intercambio\n";
        std::cout << " 4) seleccion\n";
        std::cout << " 5) Insercion\n";
        std::cout << " 6) burbuja\n";
        std::cout << " 7) salir\n";

        std::cin >> opc;

        switch (opc)
        {
        case 1: puntero=anadir(puntero, n);print(puntero, n); break;
        case 2: limpiar(puntero); break;
        case 3: intercambio(puntero, n); break;//LLamamos a la función intercambio.
        case 4: seleccion(puntero, n); break;//LLamamos a la función seleccion
        case 5: insercion(puntero, n); break;//LLamamos a la función insercion
        case 6: burbuja(puntero, n); break;//LLamamos a la función burbuja
        case 7: std::cout << "Hasta pronto :'v\n"; return 0;
        default:
            std:: cout << "Opcion incorrecta >:v\n";
            continue;
        }

        std::cout <<"****Ordenación de Arreglo de Numeros****" <<std::endl;
        print(puntero, n);//LLamamos a la función print.
        //delete [] puntero;//Liberando memoria.
    }

    return 0;
}

int * anadir(int * puntero , int size){
    /*
    anadir: 
        -Esta función se encargara de añadir un número aleatorios al arreglo que apunta
        el puntero.
    Argumentos:
        - puntero: El primer parámetro es un puntero de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */
    int *nuevo = new int [size+1];
    
    for (int i=0; i<size; i++) *(nuevo+i)=*(puntero+i), std::cout << *(nuevo+i);
    *(nuevo+size)= rand()%(100 + 1 -1) + 1;

    delete [] puntero;//Liberando memoria.
    
    return nuevo;
}

void limpiar(int* puntero){
    /*
    Limpiar:    
        -Esta función liberara de memoria el puntero.
    Argumentos:
        - puntero: Este es el puntero que vamos a liberar.
    */
    delete [] puntero;
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


void burbuja(int* puntero, int size){
    /*
    burbuja: 
        -Esta función realizara el ordenamiento burbuja.
    Argumentos:
        - puntero: El primer parámetro es un puntero de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */  
    bool flag = true;
    for (int i=0; i < size - 1 && flag; i++){
            flag = false;
        for (int j=0;j < size - 1 - i;j++){
            if(puntero[j] > puntero[j+1]){
                flag = true;
                int aux = puntero[j];
                puntero[j] =puntero[j+1];
                puntero[j+1] = aux;
            }
        }       
    }
}
void insercion(int* puntero, int size){
    /*
    Selección: 
        - Esta función se encargara de realizar el ordenamiento del puntero mediante insercion.
    Argumentos:
        - puntero: El primer parámetro es un puntero de tipo (int).
        - size: Este segundo parámetro de  tipo  (int) nos indicara el tamaño de este puntero.
    */
    int aux,j;
    
    for(int i = 1;i < size; i++){
        aux = puntero[i];
        for (j = i; j > 0 && aux < puntero[j-1]; j--){
                puntero[j] = puntero[j-1];
            }
        puntero[j] = aux;
       }
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