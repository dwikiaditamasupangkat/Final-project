#include "stdio.h"
#include "stdlib.h"
#include "iostream"
using namespace std;

void heaping(int data[], int elemen, int indeks){
	int terbesar = indeks;
    int lchild = 2*indeks + 1;
    int rchild = 2*indeks + 2;
  
    if (lchild < elemen && data[lchild] > data[terbesar]){
    	terbesar = lchild; 
	}
    if (rchild < elemen && data[rchild] > data[terbesar]){
    	terbesar = rchild; 
	}
    if (terbesar != indeks) 
    { 
        swap(data[indeks], data[terbesar]); 
        heaping(data, elemen, terbesar); 
    } 
}

void sorting(int data[], int elemen){
	for (int indeks = elemen / 2 - 1; indeks >= 0; indeks--) 
        heaping(data, elemen, indeks); 
    for (int indeks=elemen-1; indeks>=0; indeks--) 
    {
        swap(data[0], data[indeks]); 
        heaping(data, indeks, 0); 
    } 
}

int main(){
	int data[10]={3, 6, 33, 654, 23, 74, 7, 75, 12, 9}, input, parent, lchild, rchild, child1, child2, terbesar, tukar, elemen;
	
	printf("Data : ");
	for(int indeks=0; indeks<10; indeks++){
		printf("\nAngka ke-%d : %d ",indeks+1 ,data[indeks]);
	}
	printf("\n\nAngka ke-berapa yang ingin dilihat? : ");
	scanf("%d", &input);
	
	parent = ((input-1)-1)/2;
	if (input==1) parent--;
	lchild = (2*(input-1)+1);
	rchild = (2*(input-1)+2);
	if (parent<0){
		printf("\n\nAngka yang anda pilih berada pada root");
		printf("\nLeft child : %d\nRight child : %d",data[lchild], data[rchild]);
	}
	else if (lchild>=10 || rchild>=10){
		printf("\n\nAngka yang anda pilih berada pada node terakhir");
		printf("\nParent : %d",data[parent]);
	}
	else{
		printf("\n\nParent : %d\nLeft child : %d\nRight child : %d",data[parent], data[lchild], data[rchild]);	
	}
	elemen = sizeof(data) / sizeof(data[0]);
	sorting(data, elemen);
	printf("\n\nData setelah shorting : ");
	for(int indeks=0; indeks<10; indeks++){
		printf("\nAngka ke-%d : %d ",indeks+1 ,data[indeks]);
	}
}
