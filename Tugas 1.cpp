#include "stdio.h"

int main(){
	int angka[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int cari, ketemu;
	printf("Tampilan data normal \n");
	for(int indeks = 0; indeks<20; indeks++){
		printf("%i ", angka[indeks]);
	}
	printf("\n\n");
	printf("Tampilan data terbalik \n");
	for(int indeks = 19; indeks>=0; indeks--){
		printf("%i ", angka[indeks]);
	}
	printf("\n\nPencarian data");
	printf("\n\nMasukkan data yang ingin dicari : ");
	scanf("%i", &cari);
	for(int indeks = 0; indeks<20; indeks++){
		printf("Loop ke-%i\n", (indeks+1));
		if(angka[indeks] == cari){
			printf("\nData Ditemukan pada indeks ke-%i\n", indeks);
			ketemu++;
			break;
		}
	}
	if(ketemu==0){
		printf("\nData tidak ditemukan!");
	}
}

