#include "stdio.h"

int cari(int dicari, int kepala, int ekor){
	int base[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, indekstengah;
	
	indekstengah=(kepala+ekor)/2;
	
	if(dicari==base[indekstengah]){
		printf("\nAngka %d ditemukan pada indeks ke %d", base[indekstengah], indekstengah);
	}
	
	else if(dicari<base[indekstengah]){
		ekor=indekstengah-1;
		cari(dicari, kepala, ekor);
	}
	else{
		kepala=indekstengah+1;
		cari(dicari, kepala, ekor);
	}
}

int main(){
	int angka[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, dicari, kepala=0, ekor=10;
	
	printf("Menggunakan rekursif\n\nData : ");
	for(int indeks=0; indeks<10; indeks++){
		printf("%d ", angka[indeks]);
	}
	
	printf("\n\nMasukkan angka yang ingin dicari  : ");
	scanf("%d", &dicari);
	cari(dicari, kepala, ekor);
}
