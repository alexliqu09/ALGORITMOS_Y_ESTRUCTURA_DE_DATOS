#include "iostream"
#include "ctime"
#include "cstdlib"

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int main(){

}

void merge(int *p,int lefts, int middle, int rights){
	int n1 = middle-lefts+1;
	int n2 = rights-middle;
    int *p1 = new int[n1], *p2 = new int[n2];
	int i, j, k;

    for(i=0; i<n1; i++) p1[i] = p[lefts+i];
	for(j=0; j<n2; j++) p2[j] = p[middle+j+1];
	
	for(k=lefts, i=0, j=0; i<n1 && j<n2; k++){
		if (p1[i]<p2[j]) p[k] = p1[i++];
		else p[k] =p2[j++];
	}
    while(i<n1) p[k++] = p1[i++];
	while(j<n2)	p[k++] = p2[j++];

    delete p1, p2;
}

void mergeSort(int *p,int lefts,int rights){
	int middle;  

	if(lefts<rights){
		middle = (lefts+rights)/2;
        
		mergeSort(p, lefts, middle);
		mergeSort(p, middle+1, rights);
		merge(p, lefts, middle, rights);
	}
}