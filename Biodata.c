#include <stdio.h>
#include <stdlib.h>

void main () {
	char nama[30];
	char npm[9];
	char alamat[50];
	char email[20];
	char notelp[13];
	char TTL[30];
	int ulang = 1;
	
	while (ulang == 1){
		printf("========================================================================================================================\n\n");
		printf("							INPUT DATA\n\n");
		printf("========================================================================================================================\n\n");
		printf("Masukkan nama 			: ");
		gets(nama);
		printf("Masukkan NPM 			: ");
		gets(npm);
		printf("Masukkan alamat 		: ");
		gets(alamat);
		printf("Masukkan tempat, tanggal lahir	: ");
		gets(TTL);
		printf("Masukkan email 			: ");
		gets(email);
		printf("Masukkan No.Telepon 		: ");
		gets(notelp);
		system("cls");
		printf("========================================================================================================================\n\n");
		printf("							VIEW DATA\n\n");
		printf("========================================================================================================================\n\n");
		printf("Nama 			: %s", nama);
		printf("\nNPM			: %s", npm);
		printf("\nTempat, tanggal lahir	: %s", TTL);
		printf("\nAlamat 			: %s", alamat);
		printf("\nEmail 			: %s", email);
		printf("\nNo.Telp 		: %s", notelp);
		printf("\n\nIngin Mengulang?\n");
		printf("1. Ya\t\t2. Tidak\n");
		scanf("%d", &ulang);
		system("cls");
		fflush(stdin);
	}
	printf("Have a nice day :)");
}
