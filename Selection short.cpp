#include "stdio.h"

int main(){
	int angka [10] = {36, 24, 5, 63, 10, 32, 6, 80, 9, 64}, tukar, terkecil, terbesar;
	
	printf("Data : ");
	for(int indeks = 0; indeks < 10; indeks++){
		printf("%d ", angka[indeks]);
	}
	
	//ascending
	for(int proses = 0; proses<10; proses++){
		tukar = proses;
		terkecil = angka[proses];
		for(int indeks = proses; indeks < 10; indeks++){
			if(angka[indeks]<terkecil){
				tukar = indeks;
				terkecil = angka[indeks];
			}
		}
		angka[tukar] = angka[proses];
		angka[proses] = terkecil;
	}
	printf("\n\nData ascending setelah shorting : ");
	for(int indeks = 0; indeks < 10; indeks++){
		printf("%d ", angka[indeks]);
	}
	
	//descending
	for(int proses = 0; proses<10; proses++){
		tukar = proses;
		terbesar = angka[proses];
		for(int indeks = proses; indeks < 10; indeks++){
			if(angka[indeks]>terbesar){
				tukar = indeks;
				terbesar = angka[indeks];
			}
		}
		angka[tukar] = angka[proses];
		angka[proses] = terbesar;
	}
	printf("\n\nData descending setelah shorting : ");
	for(int indeks = 0; indeks < 10; indeks++){
		printf("%d ", angka[indeks]);
	}
}
