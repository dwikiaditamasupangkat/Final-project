#include "stdio.h"

int main(){
	int angka[11]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, cari, temu;
	
	printf("isi : ");
	for(int i=0; i<10; i++){
		printf("%d ", angka[i]);
	}
	
	printf("\nMasukkan angka yang ingin dicari : ");
	scanf("%d", &cari);
	
	printf("\nMetode squential :");
	for(int i=0; i<10; i++){
		printf("\nLooping ke-%d", i+1);
		if(angka[i]==cari){
			printf("\nAngka %d ditemukan pada indeks ke %d", angka[i], i);
			temu++;
			break;
		}
	}
	
	temu = 0;
	int i=0;
	printf("\n\nMetode Sentinel :");
	while(angka[i]!=NULL){
		printf("\nLooping ke-%d", i+1);
		if(angka[i]==cari){
			printf("\nAngka %d ditemukan pada indeks ke %d", angka[i], i);
			temu++;
			break;
		}
		i++;
	}
	
	if(temu==0){
		printf("\nData tidak ditemukan!!");
	}
}
