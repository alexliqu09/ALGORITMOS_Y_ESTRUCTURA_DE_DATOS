#include "iostream"
#include "cstring"

//using namespace std;

std::string artefacto;
int opcion, cant;
std::string productos[25];
int Stock[25];
int indEle = 0;


int buscar(std::string);
void insertar();
void modificar();
void eliminar();
void consulta();
void incrementar();
void estadistica();
void listar(); 


int main(){

    do
    {
        std::cout <<"\nQue desea hacer\n";
        std::cout <<"1. Insertar\n";
        std::cout <<"2. Modificar\n";
        std::cout <<"3. Eliminar\n";
        std::cout <<"4. Consulta\n";
        std::cout <<"5. Incrementar\n";
        std::cout <<"6. Estadistica\n";
        std::cout <<"7. Lista\n";
        std::cout <<"8. Salir\n";
        std::cin >> opcion;

        switch(opcion)
        {
            case 1: insertar(); break;
            case 2: modificar(); break;
            case 3: eliminar(); break;
            case 4: consulta(); break;
            case 5: incrementar(); break;
            case 6: estadistica(); break;
            case 7: listar(); break;
            case 8: std::cout<<"Gracias. Saliendo del curso :v\n"; break;
            default:
                std::cout<<"\nError en el programa \n";
        }  
    } while (opcion != 8);

    return 0;    
}



void insertar()
{
    std::cout << "\ningrese el artefacto " << indEle << std::endl;
    std::cin >> artefacto;
    std::cout << "\nIngrese la cantidad " <<indEle << std::endl; 
    std::cin >> cant;

    productos[indEle]=artefacto;
    Stock[indEle] = cant;
    indEle++;
}

int buscar(std::string artefacto){
    for (int i=0;i< indEle;i++){
        if (productos[i]==artefacto)return i;
    }
    return -1;
}

void modificar(){
    int pos;
    listar();
    std::cout << "Cual producto desea modificar: ";
    std::cin >> cant;
    pos = buscar(artefacto);
    Stock[pos]=cant;
    listar();
}

void eliminar(){
    int pos;
    listar();
    std::cout << "Cual producto desea eliminar: ";
    std::cin >> artefacto;
    pos = buscar(artefacto);

    for(int i=pos; i>indEle; i++){
        productos[i]=productos[i+1];
        Stock[i]=Stock[i+1];
    }
    listar();
}
//aqui
void consulta(){
    
    std::cout << "Cual producto desea consultar: ";
    std::cin >> artefacto;
    int pos = buscar(artefacto);

    if (pos != -1){
        std::cout <<"El producto: "<<productos[pos] <<std::endl;
        std::cout << "Cantidad del producto: "<< Stock[pos]<<std::endl;
	}
	else
	{
		std::cout <<"\nError, no se encontro su numero\n";
	}

}

void incrementar(){
    std::cout << "Cual producto desea consultar: ";
    std::cin >> artefacto;
    int pos = buscar(artefacto);

    if (pos != -1){
		int incremento;
		std::cout <<"ingrse el incremento" <<std::endl;
		std::cin >> incremento;
        Stock[pos]+= incremento;
		std::cout<< "El incremento es: " <<Stock[pos]<<std::endl;
	}
	else
	{
		std::cout <<"\nError, no se encontro su producto\n";
	}
}

void estadistica()
{	
	int sum = 0;
    listar();
    for (int i=0; i<indEle; i++){
		sum += Stock[i];
    }

    std::cout << "Suma: " << sum << std::endl;

}


void listar()
{
    std::cout << "\tProducto\t\tStock\n";
    for (int i=0; i < indEle; i++){
        std::cout << productos[i] << "\t" << Stock[i] << std::endl;
    }
}

