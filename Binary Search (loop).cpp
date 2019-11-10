#include "stdio.h"

int main(){
	int angka[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, cari, temu, loop, pembilang, posisi, indekstengah, iloop;
	
	printf("isi : ");
	for(int i=0; i<10; i++){
		printf("%d ", angka[i]);
	}
	
	printf("\nMasukkan angka yang ingin dicari : ");
	scanf("%d", &cari);
	
	loop=sizeof(angka);
	int kepala=0, ekor=10;
	while(iloop<loop){
		pembilang=kepala+ekor;
		indekstengah=pembilang/2;
		
		if(cari==angka[indekstengah]){
			printf("\nAngka %d ditemukan pada indeks ke %d", angka[indekstengah], indekstengah);
			temu++;
			break;
		}
		
		else if(cari<angka[indekstengah]){
			ekor=indekstengah-1;
		}
		else{
			kepala=indekstengah+1;
		}
		iloop++;
	}
	
	if(temu==0){
		printf("\nData tidak ditemukan!!");
	}
}
