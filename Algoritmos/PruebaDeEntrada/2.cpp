#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void losetas (int medida1, int medida2);

int main(){
    int largo, altura;
    cout << "Ingresa longitud de la base: "; cin >> largo;
    cout << "Ingresa longitud de la altura: "; cin >> altura;
    losetas(largo, altura);
}

void losetas (int medida1, int medida2){
    int n_losetas, mayor, menor;
    if(medida1==0 || medida2==0) return;
    else if(medida1>medida2){
        mayor=medida1;
        menor=medida2;
    }
    else{
        mayor=medida2;
        menor=medida1;
    }

    n_losetas= mayor/menor;
    mayor%=menor;
    cout << n_losetas << " loseta(s) de " << menor << " m de lado.\n";
    losetas (mayor, menor);
}