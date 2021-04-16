#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double recursivo (int a, int b, int c);

int main(){

    double a1_x, a1_y, a2_x, a2_y;
    double b1_x, b1_y, b2_x, b2_y;
    double m;

    cout << "\n       Primera recta";
    cout << "\nPrimer punto";
    cout << "\nx: "; cin >> a1_x;
    cout << "y: "; cin >> a1_y;
    cout << "Segundos punto";
    cout << "\nx: "; cin >> a2_x;
    cout << "y: "; cin >> a2_y;

    cout << "\n       Segunda recta";
    cout << "\nPrimer punto";
    cout << "\nx: "; cin >> b1_x;
    cout << "y: "; cin >> b1_y;
    cout << "Segundos punto";
    cout << "\nx: "; cin >> b2_x;
    cout << "y: "; cin >> b2_y;

    if (a1_x-a2_x==0){
        if (b1_x-b2_x==0){
            if (a1_x==b1_x){
                cout << "Son la misma recta.";
            }
            else cout << "son rectas paralelas";
            return 0;
        }
        else{

            m=(b1_y-b2_y)/(b1_x-b2_x);
            cout << "Interseccion\n";
            cout << "x:" << a1_x << "  y:" << b1_y+m*(a1_x-b1_x);
            return 0;
        }
    }

    if (b1_x-b2_x==0){
        if (a1_x-a2_x==0){
            if (a1_x==b1_x){
                cout << "Son la misma recta.";
            }
            else cout << "son rectas paralelas";
            return 0;
        }
        else{

            m=(a1_y-a2_y)/(a1_x-a2_x);
            cout << "Interseccion\n";
            cout << "x:" << b1_x << "  y:" << a1_y+m*(b1_x-a1_x);
            return 0;
        }
    }

    

    double m1, m2;
    double c;

    m1=(a1_y-a2_y)/(a1_x-a2_x);
    m2=(b1_y-b2_y)/(b1_x-b2_x);

    c= (a1_y-a1_x*m1) -(b1_y-b1_x*m2);
    m= m1-m2;

    if(m==0) {
        cout << "son rectas paralelas";
        return 0;
    }

    cout << "Interseccion\n";
    cout << "x:" << -c/m << "  y:" << a1_y+m1*(-c/m-a1_x);
}

