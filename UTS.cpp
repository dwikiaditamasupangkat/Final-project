#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"

//buat cetakan
struct blok{
	int ukuran;
	int berat;
	char vendor[50];
	char jenis_muatan[50];
};
int main(){
	int isia = 9, isib = 0, isic = 0;
	
	//buat blok
	blok A[9];
	blok B[9];
	blok C[9];
	
	//isi blok
	A[0].ukuran = 20;
	A[0].berat = 100;
	strcpy(A[0].vendor, "Meratus");
	strcpy(A[0].jenis_muatan, "Electronics");
	
	A[1].ukuran = 40;
	A[1].berat = 150;
	strcpy(A[1].vendor, "Mearsk");
	strcpy(A[1].jenis_muatan, "Electronics");
	
	A[2].ukuran = 20;
	A[2].berat = 100;
	strcpy(A[2].vendor, "Meratus");
	strcpy(A[2].jenis_muatan, "Goods");
	
	A[3].ukuran = 60;
	A[3].berat = 200;
	strcpy(A[3].vendor, "Meratus");
	strcpy(A[3].jenis_muatan, "Goods");
	
	A[4].ukuran = 20;
	A[4].berat = 100;
	strcpy(A[4].vendor, "Mearsk");
	strcpy(A[4].jenis_muatan, "Chemical");
	
	A[5].ukuran = 60;
	A[5].berat = 200;
	strcpy(A[5].vendor, "Pelni Logistics");
	strcpy(A[5].jenis_muatan, "Electronics");
	
	A[6].ukuran = 40;
	A[6].berat = 150;
	strcpy(A[6].vendor, "Mearsk");
	strcpy(A[6].jenis_muatan, "Chemical");
	
	A[7].ukuran = 40;
	A[7].berat = 150;
	strcpy(A[7].vendor, "Pelni Logistics");
	strcpy(A[7].jenis_muatan, "Goods");
	
	A[8].ukuran = 20;
	A[8].berat = 100;
	strcpy(A[8].vendor, "Meratus");
	strcpy(A[8].jenis_muatan, "Electronics");
	
	//tampilkan blok awal
	system("cls");
	printf("Blok gabungan (Belum dipilah)\n\n");
	for(int indeks = 0; indeks<9; indeks++){
		printf("Ukuran	= %d", A[indeks].ukuran);
		printf("\tBerat	= %d", A[indeks].berat);
		printf("\tVendor	= %s", A[indeks].vendor);
		printf("\tMuatan	= %s\n\n", A[indeks].jenis_muatan);
	}
	printf("\n\nTekan sembarang tombol");
	getch();
	
	//pisahkan blok
	for(int indeks = 0; indeks<9; indeks++){
		if(strstr(A[indeks].jenis_muatan,"Goods")){
			B[isib] = A[indeks];			
			for(int indeksd = indeks; indeksd<9; indeksd++){
				if(strstr(A[indeksd+1].jenis_muatan,"Electronics")){
					A[indeks] = A[indeksd+1];
				}
			}
			isib++;
			isia--;
		}
		else if(strstr(A[indeks].jenis_muatan,"Chemical")){
			C[isic] = A[indeks];
			for(int indeksd = indeks; indeksd<9; indeksd++){
				if(strstr(A[indeksd+1].jenis_muatan,"Electronics")){
					A[indeks] = A[indeksd+1];
				}
			}
			isic++;
			isia--;
		}
	}
	
	//cetak hasil
	system("cls");
	printf("Blok A (Electronics)\n\n");
	for(int indeks = 0; indeks<isia; indeks++){
		printf("Ukuran	= %d", A[indeks].ukuran);
		printf("\tBerat	= %d", A[indeks].berat);
		printf("\tVendor	= %s", A[indeks].vendor);
		printf("\tMuatan	= %s\n\n", A[indeks].jenis_muatan);
	}
	printf("\n\nTekan sembarang tombol");
	getch();
	
	system("cls");
	printf("Blok B (Goods)\n\n");
	for(int indeks = 0; indeks<isib; indeks++){
		printf("Ukuran	= %d", B[indeks].ukuran);
		printf("\tBerat	= %d", B[indeks].berat);
		printf("\tVendor	= %s", B[indeks].vendor);
		printf("\tMuatan	= %s\n\n", B[indeks].jenis_muatan);
	}
	printf("\n\nTekan sembarang tombol");
	getch();
	
	system("cls");
	printf("Blok C (Chemical)\n\n");
	for(int indeks = 0; indeks<isic; indeks++){
		printf("Ukuran	= %d", C[indeks].ukuran);
		printf("\tBerat	= %d", C[indeks].berat);
		printf("\tVendor	= %s", C[indeks].vendor);
		printf("\tMuatan	= %s\n\n", C[indeks].jenis_muatan);
	}
	printf("\n\nTekan sembarang tombol");
	getch();
	
	system("cls");
	printf("Have a nice day :)");
	printf("\n\nTekan sembarang tombol");
	getch();
}

