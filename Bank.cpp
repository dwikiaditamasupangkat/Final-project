#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

struct nasabah{
	char nama[30];
	char norek[20];
	char bank [20];
	float saldo;
	struct alamat{
		char jalan[30];
		char kota[30];
		char provinsi[30];
	};
	struct ttlahir{
		int tanggal;
		char bulan[9];
		int tahun;
	};
	struct alamat alamat;
	struct ttlahir ttlahir;
};

int main(){
	struct nasabah nasabah[10];
	int ulang = 1, pilihan, jumlah = 0, terbesar, terkecil, ketemu, usia;
	float akumulasi = 0, sterbesar, sterkecil;
	char cari[30];
	while (ulang == 1){
		system("cls");
		printf("1. Tambah data nasabah\n");
		printf("2. Tampilkan data nasabah\n");
		printf("3. Cari data nasabah\n");
		printf("4. Hitung akumulasi saldo total\n");
		printf("5. Tampilkan nasabah tabungan junior (usia nasabah < 17 tahun)\n");
		printf("6. Keluar\n");
		printf("\nMasukkan pilihan : ");
		scanf("%i", &pilihan);
		fflush(stdin);
		switch(pilihan){
			case 1 :
				system("cls");
				printf("Masukkan nama nasabah		: ");
				gets(nasabah[jumlah].nama);
				printf("Masukkan nomor rekening nasabah	: ");
				gets(nasabah[jumlah].norek);
				printf("Masukkan nama bank		: ");
				gets(nasabah[jumlah].bank);
				printf("Masukkan saldo nasabah		: ");
				scanf("%f", &nasabah[jumlah].saldo);
				fflush(stdin);
				printf("Alamat\n");
				printf("Masukkan nama jalan		: ");
				gets(nasabah[jumlah].alamat.jalan);
				printf("Masukkan nama kota		: ");
				gets(nasabah[jumlah].alamat.kota);
				printf("Masukkan nama provinsi		: ");
				gets(nasabah[jumlah].alamat.provinsi);
				printf("Tanggal lahir\n");
				printf("Masukkan tanggal		: ");
				scanf("%i", &nasabah[jumlah].ttlahir.tanggal);
				fflush(stdin);
				printf("Masukkan bulan			: ");
				gets(nasabah[jumlah].ttlahir.bulan);
				fflush(stdin);
				printf("Masukkan masukkan tahun		: ");
				scanf("%i", &nasabah[jumlah].ttlahir.tahun);
				fflush(stdin);
				jumlah++;
				break;
			case 2 :
				system("cls");
				sterbesar = 0;
				sterkecil = nasabah[0].saldo;
				for(int index=0; index<jumlah; index++){
					printf("Nama nasabah	: %s\n", nasabah[index].nama);
					printf("Nomor rekening	: %s\n", nasabah[index].norek);
					printf("Nama bank	: %s\n", nasabah[index].bank);
					printf("Saldo		: %f\n", nasabah[index].saldo);
					printf("Alamat		: %s, %s, %s\n", nasabah[index].alamat.jalan, nasabah[index].alamat.kota, nasabah[index].alamat.provinsi);
					printf("Tanggal lahir	: %i %s %i\n", nasabah[index].ttlahir.tanggal, nasabah[index].ttlahir.bulan, nasabah[index].ttlahir.tahun);
					printf("========================================================================================================================\n");
					if(nasabah[index].saldo>sterbesar){
						terbesar = index;
						sterbesar = nasabah[index].saldo;
					}
					else if(nasabah[index].saldo<sterkecil){
						terkecil = index;
						sterkecil = nasabah[index].saldo;
					}
				}
				if(jumlah==0){
					printf("Data kosong!\n");
				}
				else{
					printf("\nNasabah dengan saldo terbesar adalah : %s, Rp%f", nasabah[terbesar].nama, nasabah[terbesar].saldo);
					printf("\nNasabah dengan saldo terkecil adalah : %s, Rp%f\n", nasabah[terkecil].nama, nasabah[terkecil].saldo);	
				}
				printf("\nTekan enter untuk kembali ke menu");
				getch();
				break;
			case 3 :
				if (jumlah == 0){
					system("cls");
					printf("Data kosong!");
					printf("\nTekan enter untuk kembali ke menu");
					getch();
				}
				ketemu = 0;
				system("cls");
				printf("1. Nama\n");
				printf("2. No. Rekening\n");
				printf("3. Nama bank\n");
				printf("4. Nama kota\n");
				printf("5. Nama provinsi\n");
				printf("Cari berdasarkan : ");
				scanf("%i", &pilihan);
				fflush(stdin);
				switch(pilihan){
					case 1 :
						system("cls");
						printf("Masukkan nama nasabah yang ingin dicari : ");
						gets (cari);
						for(int index=0; index<jumlah; index++){
							if(strstr(nasabah[index].nama,cari)){
								printf("Nama nasabah	: %s\n", nasabah[index].nama);
								printf("Nomor rekening	: %s\n", nasabah[index].norek);
								printf("Nama bank	: %s\n", nasabah[index].bank);
								printf("Saldo		: %f\n", nasabah[index].saldo);
								printf("Alamat		: %s, %s, %s\n", nasabah[index].alamat.jalan, nasabah[index].alamat.kota, nasabah[index].alamat.provinsi);
								printf("Tanggal lahir	: %i %s %i\n", nasabah[index].ttlahir.tanggal, nasabah[index].ttlahir.bulan, nasabah[index].ttlahir.tahun);
								printf("========================================================================================================================\n");
								ketemu++;
							}
						}
						if (ketemu == 0){
							system("cls");
							printf("Data tidak ditemukan!");
							printf("\nTekan enter untuk kembali ke menu");
							getch();
						}
						getch();
						printf("\nTekan enter untuk kembali ke menu");
						break;
						case 2 :
							system("cls");
							printf("Masukkan nomor rekening yang ingin dicari : ");
							gets (cari);
							for(int index=0; index<jumlah; index++){
								if(strstr(nasabah[index].norek,cari)){
									printf("Nama nasabah	: %s\n", nasabah[index].nama);
									printf("Nomor rekening	: %s\n", nasabah[index].norek);
									printf("Nama bank	: %s\n", nasabah[index].bank);
									printf("Saldo		: %f\n", nasabah[index].saldo);
									printf("Alamat		: %s, %s, %s\n", nasabah[index].alamat.jalan, nasabah[index].alamat.kota, nasabah[index].alamat.provinsi);
									printf("Tanggal lahir	: %i %s %i\n", nasabah[index].ttlahir.tanggal, nasabah[index].ttlahir.bulan, nasabah[index].ttlahir.tahun);
									printf("========================================================================================================================\n");
									ketemu++;
								}
							}
							if (ketemu == 0){
								system("cls");
								printf("Data tidak ditemukan!");
								printf("\nTekan enter untuk kembali ke menu");
								getch();
							}
							getch();
							printf("\nTekan enter untuk kembali ke menu");
							break;
						case 3 :
							system("cls");
							printf("Masukkan nama bank yang ingin dicari : ");
							gets (cari);
							for(int index=0; index<jumlah; index++){
								if(strstr(nasabah[index].bank,cari)){
									printf("Nama nasabah	: %s\n", nasabah[index].nama);
									printf("Nomor rekening	: %s\n", nasabah[index].norek);
									printf("Nama bank	: %s\n", nasabah[index].bank);
									printf("Saldo		: %f\n", nasabah[index].saldo);
									printf("Alamat		: %s, %s, %s\n", nasabah[index].alamat.jalan, nasabah[index].alamat.kota, nasabah[index].alamat.provinsi);
									printf("Tanggal lahir	: %i %s %i\n", nasabah[index].ttlahir.tanggal, nasabah[index].ttlahir.bulan, nasabah[index].ttlahir.tahun);
									printf("========================================================================================================================\n");
									ketemu++;
								}
							}
							if (ketemu == 0){
								system("cls");
								printf("Data tidak ditemukan!");
								printf("\nTekan enter untuk kembali ke menu");
								getch();
							}
							getch();
							printf("\nTekan enter untuk kembali ke menu");
							break;
						case 4 :
							system("cls");
							printf("Masukkan nama kota yang ingin dicari : ");
							gets (cari);
							for(int index=0; index<jumlah; index++){
								if(strstr(nasabah[index].alamat.kota,cari)){
									printf("Nama nasabah	: %s\n", nasabah[index].nama);
									printf("Nomor rekening	: %s\n", nasabah[index].norek);
									printf("Nama bank	: %s\n", nasabah[index].bank);
									printf("Saldo		: %f\n", nasabah[index].saldo);
									printf("Alamat		: %s, %s, %s\n", nasabah[index].alamat.jalan, nasabah[index].alamat.kota, nasabah[index].alamat.provinsi);
									printf("Tanggal lahir	: %i %s %i\n", nasabah[index].ttlahir.tanggal, nasabah[index].ttlahir.bulan, nasabah[index].ttlahir.tahun);
									printf("========================================================================================================================\n");
									ketemu++;
								}
							}
							if (ketemu == 0){
								system("cls");
								printf("Data tidak ditemukan!");
								printf("\nTekan enter untuk kembali ke menu");
								getch();
							}
							getch();
							printf("\nTekan enter untuk kembali ke menu");
							break;
						case 5 :
							system("cls");
							printf("Masukkan nama provinsi yang ingin dicari : ");
							gets (cari);
							for(int index=0; index<jumlah; index++){
								if(strstr(nasabah[index].alamat.provinsi,cari)){
									printf("Nama nasabah	: %s\n", nasabah[index].nama);
									printf("Nomor rekening	: %s\n", nasabah[index].norek);
									printf("Nama bank	: %s\n", nasabah[index].bank);
									printf("Saldo		: %f\n", nasabah[index].saldo);
									printf("Alamat		: %s, %s, %s\n", nasabah[index].alamat.jalan, nasabah[index].alamat.kota, nasabah[index].alamat.provinsi);
									printf("Tanggal lahir	: %i %s %i\n", nasabah[index].ttlahir.tanggal, nasabah[index].ttlahir.bulan, nasabah[index].ttlahir.tahun);
									printf("========================================================================================================================\n");
									ketemu++;
								}
							}
							if (ketemu == 0){
								system("cls");
								printf("Data tidak ditemukan!");
								printf("\nTekan enter untuk kembali ke menu");
								getch();
							}
							getch();
							printf("\nTekan enter untuk kembali ke menu");
							break;
					}
				break;
			case 4 :
				system("cls");
				for(int index = 0; index < jumlah; index++){
					akumulasi = akumulasi + nasabah[index].saldo;
					printf("%s,	%f\n", nasabah[index].nama, nasabah[index].saldo);
				}
				printf("\nAkumulasi saldo nasabah sebesar Rp%f\n", akumulasi);
				printf("\nTekan enter untuk kembali ke menu");
				getch();
				akumulasi = 0;
				break;
			case 5 :
				system("cls");
				for(int index = 0; index < jumlah; index++){
					usia = 2019-nasabah[index].ttlahir.tahun;
					if(usia<17){
						printf("Nama nasabah	: %s\n", nasabah[index].nama);
						printf("Nomor rekening	: %s\n", nasabah[index].norek);
						printf("Nama bank	: %s\n", nasabah[index].bank);
						printf("Saldo		: %f\n", nasabah[index].saldo);
						printf("Alamat		: %s, %s, %s\n", nasabah[index].alamat.jalan, nasabah[index].alamat.kota, nasabah[index].alamat.provinsi);
						printf("Tanggal lahir	: %i %s %i\n", nasabah[index].ttlahir.tanggal, nasabah[index].ttlahir.bulan, nasabah[index].ttlahir.tahun);
						printf("========================================================================================================================\n");
					}
				}
				printf("\nTekan enter untuk kembali ke menu");
				getch();
				break;
			case 6 :
				system("cls");
				ulang = pilihan;
				printf("Have a nice day :)");
				break;
		}
	}
}
