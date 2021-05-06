#include <iostream>
#include <cstdlib>
#include <ctime>

void quickSort(int*, int, int);

int main(){
    
}

void quickSort(int *p, int lefts, int rights){
    int i=lefts, j=rights, middle = p[(lefts+rights)/2], tem;

    while (i <= j){

        while(p[i] < middle) i++;
        while(p[j] > middle) j--;

        if (i <= j){
            tem = p[i];
            p[i] = p[j];
            p[j] = tem;
            i++, j--;
        }
    }

    if(lefts<j) quickSort(p, lefts, j);
    if(i<rights) quickSort(p, i, rights);
}
