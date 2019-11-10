#include "stdio.h"
int search (int angka[], int cari, int kepala, int ekor){
	int posisi=((cari-angka[kepala])/(angka[ekor]-angka[kepala])*(ekor-kepala))+kepala;
	
	if(posisi>9 || posisi<0){
		printf("\nAngka tidak ditemukan");
	}
	else if(cari==angka[posisi]){
		printf("\nAngka %d ditemukan pada indeks ke-%d", angka[posisi], posisi);
	}
	else if(cari<angka[posisi]){
		ekor--;
		search (angka, cari, kepala, ekor);
	}
	else if(cari>angka[posisi]){
		kepala++;
		search (angka, cari, kepala, ekor);
	}
}

int main(){
	int angka[10]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, cari=7, kepala=0, ekor=9;

	printf("Data : ");
	for(int indeks=0; indeks<10; indeks++){
		printf("%d ", angka[indeks]);
	}
	
	printf("\n\nMasukkan data yang ingin dicari : ");
	scanf("%d", &cari);
	
	search (angka, cari, kepala, ekor);
}
