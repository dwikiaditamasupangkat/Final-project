#include "stdio.h"
#include <stdlib.h>

struct ipkmhs{
	char nim[11];
	char nama[30];
	float ipk;
};

int main(){
	struct ipkmhs mhs[5];
	for(int i=0; i<5; i++){
		printf("\nMasukkan nama	: ");
		gets(mhs[i].nama);
		printf("\nMasukkan NIM	: ");
		gets(mhs[i].nim);
		printf("\nMasukkan IPK	: ");
		scanf("%f", &mhs[i].ipk);
		fflush(stdin);
	}
	printf("\n\nMahasiswa IPK>=3.0");
	for(int i=0; i<5; i++){
		if(mhs[i].ipk >= 3){
			printf("\n");
			printf(mhs[i].nama);
		}
	}
	printf("\n\nMahasiswa IPK<3.0");
	for(int i=0; i<5; i++){
		if(mhs[i].ipk < 3){
			printf("\n");
			printf(mhs[i].nama);
		}
	}
}
