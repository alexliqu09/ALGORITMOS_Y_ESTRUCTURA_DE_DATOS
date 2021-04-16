#include "iostream"

int  busqueda_lineal(int array[], int size, int clave)
{   
    /*
    Busqueda_lineal: 
        - Esta función hara una busqueda de la clave en el array.
    Argumentos:
        - array: Arreglo donde buscaremos el elemento pedido.
        - size : Tamaño del arreglo.
        - clave: Valor buscado.
    Return :
        - i: Si encuentra el elemento retornamremos el indice de este elemento.
        - -1: Retornara -1 sino lo encuentra.  
    */
    for(int i=0; i<size; i++)
    {
        if (clave == array[i])
        {   
            return i;
        }

    }

    return -1;
}

int main(){

    int array[] = {2, 4, 12, 5, 9, 3, 2, 1}, clave, index;
    //Arreglo de tamaño 8, valor buscado e indice en el arreglo respectivamente.
    int size = sizeof(array) / sizeof(array[0]);//calculamos el tamaño del array.

    std::cout <<"\n*****Busqueda Lineal*****\n";
    std::cout <<"\nIngrese un número a buscar\n";
    std::cin >>clave;

    index = busqueda_lineal(array, size, clave);//Buscamos el indice en el arreglo.

    if (index == -1)
    {
        /*
            Si el indice es -1, entonces no  encontramos el número en el arreglo de 
            lo contrario si lo encontro e imprimira este.
        */
        std::cout <<"El número no se encuentra en el array\n";
    }
    else
    {
        std::cout<<"El número {" <<array[index] <<"} se encuentra en el array\n";
    }

    return 0;
}

