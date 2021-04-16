#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

double recursivo (int a, int b, int c);

int main(){
    cout << 4/recursivo(1, 1, 9999);
}


double recursivo (int a, int b, int c){
    if (a>=c) return a;
    else return a+b*b/recursivo(a+2, b+1, c);
}