#include "stdio.h"
#include "conio.h"
#include "iostream"

using namespace std;

struct tanggal{
	int hari;
	char bulan[20];
	int tahun;
};

struct kendaraan{
   char no_tiket[100];
   char no_kendaraan[100];
   char jenis[100];
   float bobot;
   char tujuan[100];
   tanggal kendaraan;
};

int main(){
	kendaraan bermotor[100];
	int status=0, pilihan;
	while (status==0){
		system("CLS");
		printf("Aplikasi pelabuhan\n\n");
		printf("1. Tambah data\n");
		printf("2. Ubah data\n");
		printf("3. Cari data\n");
		printf("4. Tampilkan data\n");
		printf("5. Keluar");
		printf("\nMasukkan pilihan : ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1 :
				break;
			case 2 :
				break;
			case 3 :
				break;
			case 4 :
				break;
			case 5 :
				status=pilihan;
				system("CLS");
				printf("Have a nice day :)");
				break;
		}
	}
}
