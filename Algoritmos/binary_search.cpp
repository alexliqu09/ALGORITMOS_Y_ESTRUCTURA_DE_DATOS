#include "iostream"

using namespace std;

void print(int a[], int arraysize)
{
    /*
    print: Esta función retornara un impresion del arreglo.

    Argumentos: 
        - a : Arreglo que vamos a imprimir.
        - arraysize: Tamaño del arreglo a.
    */
    cout << endl;
    for (int i = 0; i <arraysize; i++)
    {
        if (i == arraysize - 1){
            /*
            Esta condicional hara que el ultimo elemento del array en vez
            de realizar ',' haremos un salto de linea. 
            */
            cout<< a[i] <<endl;
            break;    
        }
        cout<< a[i] <<" , ";
    }
}

int busqueda_binaria(int array[], int size, int clave)
{
    /*
    Busqueda_binaria: 
        - Realizara la busqueda binaria del arreglo para ello el arreglo debe estar ordenado.
    Argumentos:
        - array: Arreglo ordenado.
        - size: Tamaño del array.
        - clave: valor buscado.
    Return: 
        - central: indice donde se encuentra la clave.
        - -1 : Si no encuentra la clave en array.    
    */
    int central, alto, bajo, valor_central;

    bajo = 0; //actualizando variable bajo = 0
    alto = size - 1; //actualizando variable alto =size_array - 1

    while(bajo <= alto)
    {
        central = (bajo + alto)/2; //indice central
        valor_central = array[central];//ubicarnos en el centro actualizable

        if (clave == valor_central)
        {
        /*
        si valor_central es valor buscado return central.
        */
            return central;
        }
        else if (clave < valor_central)
        {
        /*
        Si la clave es menor que el valor central actualizamos el alto
        ya que no es necesario sigues buscando en los mayores.
        */
            alto = central - 1;
        }
        else
        {
        /*
        Pero si la clave es mayor entonces ya no es necesario buscar abajo, entonces
        actualizamos el bajo.
        */ 
            bajo = central + 1;
        }
    }

    return -1;//si no encuentra nada
}

int main()
{

    int array[] = {2, 3, 5, 7, 8, 9}, clave; //Crear un array de tamaño 7 y número buscado.
    int size = sizeof(array) / sizeof(array[0]);//Determinar el tamaño del arreglo

    cout<<"\nIngrese el número buscado en el array\n";
    cin>> clave;

    cout <<"\nEl arreglo es: \n";
    print(array, size); //Imprimir el arreglo  

    int index = busqueda_binaria(array, size, clave);
    //Retorna el indice si encuentra elemento o -1 si no lo encuentra.

    if (index == -1)
    {
        cout << "\nEl número no se encuentra.\n";
    }
    else
    {
        cout <<"\nEl número {" << array[index] <<"} se encuentra en el array\n";
    }
    
    return 0;
}
