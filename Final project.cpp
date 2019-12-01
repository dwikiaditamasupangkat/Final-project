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
				//no_tiket, no_kendaraan, jenis, bobot, tujuan(KETAPANG, PADANG BAI, LEMBAR, TANJUNG PERAK)
				break;
			case 2 :
				//bisa ubah semua 
				break;
			case 3 :
				//cari berdasarkan NOMOR KENDARAAN, NOMOR TIKET, BOBOT KENDARAAN
				break;
			case 4 :
				//tampilkan ascending / descending berdasarkan NOMOR TIKET, NOMOR KENDARAAN, JENIS KENDARAAN, OBOT, TUJUAN, TANGGAL
				break;
			case 5 :
				status=pilihan;
				system("CLS");
				printf("Have a nice day :)");
				break;
		}
	}
}
