#include "stdio.h"
#include "stdlib.h"

int rekursif(int hasil, int basis, int pangkat){
	if(pangkat==0){
		printf("Hasilnya	: 1");
	}
	else if(pangkat!=1){
		hasil = hasil*basis;
		pangkat--;
		rekursif(hasil, basis, pangkat);
	}
	else if(pangkat==1){
		printf("Hasilnya	: %i", hasil);
	}
}

int iteratif(int hasil, int basis, int pangkat){
	if(pangkat==0){
		printf("Hasilnya	: 1");
	}
	else if(pangkat>=1){
		while(pangkat>1){
			hasil = hasil*basis;
			pangkat--;
		}
		printf("Hasilnya	: %i", hasil);
	}
	else if(pangkat==1){
		printf("Hasilnya	: %i", hasil);
	}
}

int main(){
	int basis, pangkat, indeks=1, hasil, pilihan;
	while (indeks==1){
		system("cls");
		printf("========================================================================================================================");
		printf("\n					Penghitung bilangan berpangkat");
		printf("\n========================================================================================================================");
		printf("\n1. Metode rekursif");
		printf("\n2. Metode iteratif");
		printf("\n3. Keluar");
		printf("\nMasukkan pilihan : ");
		scanf("%i", &pilihan);
		switch(pilihan){
			case 1 :
				printf("\nMasukkan nilai basis	: ");
				scanf("%i", &basis);
				printf("\nMasukkan nilai pangkat	: ");
				scanf("%i", &pangkat);
				hasil=basis;
				rekursif(hasil, basis, pangkat);
				printf("\n\nIngin mengulang?\n1. Ya\n2. Tidak");
				printf("\nMasukkan pilihan : ");
				scanf("%i", &indeks);
				break;
			case 2 :
				printf("\nMasukkan nilai basis	: ");
				scanf("%i", &basis);
				printf("\nMasukkan nilai pangkat	: ");
				scanf("%i", &pangkat);
				hasil=basis;
				iteratif(hasil, basis, pangkat);
				printf("\n\nIngin mengulang?\n1. Ya\n2. Tidak");
				printf("\nMasukkan pilihan : ");
				scanf("%i", &indeks);
				break;
			case 3 :
				indeks++;
				break;
			default :
				printf("Pilihan tidak tersedia!");
				printf("\n\nIngin mengulang?\n1. Ya\n2. Tidak");
				printf("\nMasukkan pilihan : ");
				scanf("%i", &indeks);
				break;
		}
	}
	system("cls");
	printf("Have a nice day:)");
}
