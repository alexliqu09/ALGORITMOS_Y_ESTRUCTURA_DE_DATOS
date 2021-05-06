#include "iostream"
#include "ctime"
#include "cstdlib"

int shell(int*, int);
void print(int *, int);
void llenar(int *, int);

int main (){
    int n=7, *p = new int[n]{6, 1, 5, 2, 3, 4 ,0};

    //llenar(p, n);
    print(p, n);
    shell(p, n);
    print(p, n);

}

int shell(int* puntero, int size){

    int aux, i, j;
    int paso=size/2;
    bool flag;

    int cont=1; //
    
    while (paso>0){
        flag=true;

        while (flag){
            std::cout << cont << "\t" << paso << "\t"; //
            for(i=0, flag=false; i+paso<size; i++){
                if(puntero[i+paso]<puntero[i]){
                    std::cout << "(" <<puntero[i] << " "<< puntero[i+paso] << ")"; //
                    aux = puntero[i];
                    puntero[i] = puntero[i+paso]; 
                    puntero[i+paso] = aux;
                    flag=true;
                }
            }

            std::cout << "\t\t";//
            print(puntero, size); //
            cont++; //
        }
        paso=paso/2;
    }
}

void llenar(int* puntero, int size){

    srand(time(NULL));
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