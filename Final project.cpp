#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct tanggal{
	int hari;
	char bulan[20];
	int tahun;
};

struct kendaraan{
   int no_tiket;
   char no_kendaraan[100];
   char jenis[100];
   float bobot;
   char tujuan[100];
   tanggal tanggal;
};

kendaraan bermotor[100];
int status=0, pilihan, i=0, kriteria;

void input();
void ubah();
void lihat();
void caribobot();
void carinopol();
void caritiket();

main(){
	while (status==0){
		system("CLS");
		printf("================================\n");
		printf("| Aplikasi Pendataan Pelabuhan |\n");
		printf("================================\n");
		printf("| 1. Tambah data               |\n");
		printf("| 2. Ubah data                 |\n");
		printf("| 3. Cari data                 |\n");
		printf("| 4. Tampilkan data            |\n");
		printf("| 5. Sorting data              |\n");
		printf("| 6. Keluar                    |\n");
		printf("--------------------------------\n");
		printf("| Masukkan pilihan : ");
		scanf("%d", &pilihan);
		system("CLS");
		switch(pilihan){
			case 1 :
				input();
				break;
			case 2 :
				ubah();
				break;
			case 3 :
				printf("cari berdasarkan kriteria : \n");
				printf("1. no tiket \n2. nopol kendaraan \n3. bobot kendaraan\n");
				printf("masukkan pilihan : ");
				scanf("%d",&kriteria);
				switch(kriteria){
					case 1 :
						caritiket();		
					break;
					case 2 :
						carinopol();
					break;
					case 3 :
						caribobot();
					break;
				}
				break;
			case 4 :
				lihat();
				break;
			case 5 :
				printf("sorting berdasarkan kriteria : \n");
				printf("1. no tiket \n2. nopol kendaraan \n3. jenis kendaraan \n4. bobot kendaraan \n5. tujuan \n6. tanggal");
				printf("masukkan pilihan : ");
				scanf("%d",&kriteria);
				switch(kriteria){
					case 1 :
								
					break;
					case 2 :
						
					break;
					case 3 :
						
					break;
					case 4 :
						
					break;
					case 5 :
						
					break;
					case 6 :
						
					break;
				}
				break;
			case 6 :
				status=pilihan;
				system("CLS");
				printf("Have a nice day :)");
				break;
		}
	}
}

void input(){
	int jenis, tujuan;
	printf("=================================================================\n");
	printf("|                        Form Input Data                        |\n");
	printf("=================================================================\n");
	fflush(stdin);
	bermotor[i].no_tiket = i + 1;
	printf("-----------------------------------------------------------------\n");
	fflush(stdin);
	printf("| Masukkan Tanggal(dd mouth yyyy): ");
	scanf("%d %s %d", &bermotor[i].tanggal.hari,&bermotor[i].tanggal.bulan,&bermotor[i].tanggal.tahun);
	printf("-----------------------------------------------------------------\n");
	fflush(stdin);
	printf("| Masukkan Nopol Kendaraan       : ");
	gets(bermotor[i].no_kendaraan);
	printf("-----------------------------------------------------------------\n");
	fflush(stdin);
	printf("| Pilih Jenis Kendaraan");
	printf("\n| 1. Truk \n| 2. Pick up \n| 3. Bus \n| 4. Minibus \n| 5. Sedan \n| 6. Motor\n");
	printf("| Masukkan Jenis Kendaraan       : ");
	scanf("%d", &jenis);
	switch(jenis){
		case 1 : strcpy(bermotor[i].jenis, "Truk");
		break;
		case 2 : strcpy(bermotor[i].jenis, "Pick Up");
		break;
		case 3 : strcpy(bermotor[i].jenis, "Bus");
		break;
		case 4 : strcpy(bermotor[i].jenis, "Minibus");
		break;
		case 5 : strcpy(bermotor[i].jenis, "Sedan");
		break;
		case 6 : strcpy(bermotor[i].jenis, "Motor");
		break;
	}
	printf("-----------------------------------------------------------------\n");
	fflush(stdin);
	printf("| Masukkan Bobot Kendaraan(Ton)   : ");
	scanf("%f", &bermotor[i].bobot);
	printf("-----------------------------------------------------------------\n");
	fflush(stdin);
	printf("| Pilih Tujuan");
	printf("\n| 1. Ketapang \n| 2. Padang Bai \n| 3. Lembar \n| 4. Tanjung Perak\n");
	printf("| Masukkan Tujuan                : ");
	scanf("%d",&tujuan);
	switch(tujuan){
		case 1 : strcpy(bermotor[i].tujuan, "Ketapang");
		break;
		case 2 : strcpy(bermotor[i].tujuan, "Padang Bai");
		break;
		case 3 : strcpy(bermotor[i].tujuan, "Lembar");
		break;
		case 4 : strcpy(bermotor[i].tujuan, "Tanjung Perak");
		break;	
	}
	printf("-----------------------------------------------------------------\n");
	i++;
}

void lihat(){
	if(i==0){
		printf("===================================\n");
		printf("|                                 |\n");
		printf("|        ~~ DATA KOSONG ~~        |\n");
		printf("|                                 |\n");
		printf("===================================\n");
	}else{
		for(int a=0; a<i; a++){
			printf("=================================================================\n");
			printf("|                           View Data                           |\n");
			printf("=================================================================\n");
			printf("| No Tiket        : %d\n", bermotor[a].no_tiket);
			printf("| Tanggal         : %d %s %d\n", bermotor[a].tanggal.hari, bermotor[a].tanggal.bulan, bermotor[a].tanggal.tahun);
			printf("| Nopol Kendaraan : %s\n", bermotor[a].no_kendaraan);
			printf("| Jenis Kendaraan : %s\n", bermotor[a].jenis);
			printf("| Bobot Kendaraan : %.2f Kg\n", bermotor[a].bobot);
			printf("| Tujuan          : %s\n", bermotor[a].tujuan);
			printf("=================================================================\n");
		}	
	}
	getch();
}

void ubah(){	
	int caritiket;
	int low=0, high=i-1, pos, ketemu=0;
	bool berhenti = false;  
  
 	fflush(stdin);
	printf("masukkan no tiket yang di cari : ");
	scanf("%d", &caritiket);
	
	while(berhenti ==false){
		
		pos = (caritiket-bermotor[low].no_tiket)/(bermotor[high].no_tiket-bermotor[low].no_tiket)*(high-low)+low;
		printf("pos %d",pos);
		if(bermotor[pos].no_tiket == caritiket){
			ketemu = 1;
			berhenti = true;
		}
		else if(bermotor[pos].no_tiket < caritiket){
			high = pos - 1;
		}
		else if(bermotor[pos].no_tiket > caritiket){
			low = pos + 1;
		}
	}	
	if(ketemu==1){
		int jenis, tujuan;
		printf("=================================================================\n");
		printf("|                         Form ubah Data                        |\n");
		printf("=================================================================\n");
		fflush(stdin);
		bermotor[pos].no_tiket = i;
		fflush(stdin);
		printf("| Masukkan Tanggal(dd mouth yyyy): ");
		scanf("%d %s %d", &bermotor[pos].tanggal.hari,&bermotor[pos].tanggal.bulan,&bermotor[pos].tanggal.tahun);
		printf("-----------------------------------------------------------------\n");
		fflush(stdin);
		printf("| Masukkan Nopol Kendaraan       : ");
		gets(bermotor[pos].no_kendaraan);
		printf("-----------------------------------------------------------------\n");
		fflush(stdin);
		printf("| Pilih Jenis Kendaraan");
		printf("\n| 1. Truk \n| 2. Pick up \n| 3. Bus \n| 4. Minibus \n| 5. Sedan \n| 6. Motor\n");
		printf("| Masukkan Jenis Kendaraan       : ");
		scanf("%d", &jenis);
		switch(jenis){
			case 1 : strcpy(bermotor[pos].jenis, "Truk");
			break;
			case 2 : strcpy(bermotor[pos].jenis, "Pick Up");
			break;
			case 3 : strcpy(bermotor[pos].jenis, "Bus");
			break;
			case 4 : strcpy(bermotor[pos].jenis, "Minibus");
			break;
			case 5 : strcpy(bermotor[pos].jenis, "Sedan");
			break;
			case 6 : strcpy(bermotor[pos].jenis, "Motor");
			break;
		}
		printf("-----------------------------------------------------------------\n");
		fflush(stdin);
		printf("| Masukkan Bobot Kendaraan(Ton)   : ");
		scanf("%f", &bermotor[pos].bobot);
		printf("-----------------------------------------------------------------\n");
		fflush(stdin);
		printf("| Pilih Tujuan");
		printf("\n| 1. Ketapang \n| 2. Padang Bai \n| 3. Lembar \n| 4. Tanjung Perak\n");
		printf("| Masukkan Tujuan                : ");
		scanf("%d",&tujuan);
		switch(tujuan){
			case 1 : strcpy(bermotor[pos].tujuan, "Ketapang");
			break;
			case 2 : strcpy(bermotor[pos].tujuan, "Padang Bai");
			break;
			case 3 : strcpy(bermotor[pos].tujuan, "Lembar");
			break;
			case 4 : strcpy(bermotor[pos].tujuan, "Tanjung Perak");
			break;	
		}
		printf("-----------------------------------------------------------------\n");
	}
	else
		printf("Data TIDAK DITEMUKAN");  
	getch();
}
void caritiket(){	
	int caritiket;
	int low=0, high=i-1, pos, ketemu=0;
	bool berhenti = false;  
  
 	fflush(stdin);
	printf("masukkan no tiket yang di cari : ");
	scanf("%d", &caritiket);
	
//	if(strcmp(bermotor[0].no_tiket,caritiket)==0){
//			printf("ketemu");
//	}else
//	printf("gaono");
//	getch();
	while(berhenti ==false){
		
		pos = (caritiket-bermotor[low].no_tiket)/(bermotor[high].no_tiket-bermotor[low].no_tiket)*(high-low)+low;
		printf("pos %d",pos);
		if(bermotor[pos].no_tiket == caritiket){
			printf("ketemu");
			ketemu = 1;
			berhenti = true;
		}
		else if(bermotor[pos].no_tiket < caritiket){
			high = pos - 1;
		}
		else if(bermotor[pos].no_tiket > caritiket){
			low = pos + 1;
		}
	}
	if(ketemu==1){
		printf("=================================================================\n");
			printf("|                           View Data                           |\n");
			printf("=================================================================\n");
			printf("| No Tiket        : %s\n", bermotor[pos].no_tiket);
			printf("| Tanggal         : %d %s %d\n", bermotor[pos].tanggal.hari, bermotor[pos].tanggal.bulan, bermotor[pos].tanggal.tahun);
			printf("| Nopol Kendaraan : %s\n", bermotor[pos].no_kendaraan);
			printf("| Jenis Kendaraan : %s\n", bermotor[pos].jenis);
			printf("| Bobot Kendaraan : %.2f Kg\n", bermotor[pos].bobot);
			printf("| Tujuan          : %s\n", bermotor[pos].tujuan);
			printf("=================================================================\n");
	}
	else
		printf("data TIDAK DITEMUKAN");  
	getch();
}

void carinopol(){
	char carinopol[100];
	int low=0, high=i-1, pos, ketemu=0;
	bool berhenti = false;  
  
 	fflush(stdin);
	printf("masukkan nopol kendaraan yang di cari : ");
	gets(carinopol);
	
//	if(strcmp(bermotor[0].no_tiket,caritiket)==0){
//			printf("ketemu");
//	}else
//	printf("gaono");
//	getch();
	while(berhenti ==false){
		
		pos = (carinopol-bermotor[low].no_kendaraan)/(bermotor[high].no_kendaraan-bermotor[low].no_kendaraan)*(high-low)+low;
		printf("pos %d",pos);
		if(strcmp(bermotor[pos].no_kendaraan,carinopol)==0){
			printf("ketemu");
			ketemu = 1;
			berhenti = true;
		}
		else if(strcmp(bermotor[pos].no_kendaraan,carinopol)==1){
			high = pos - 1;
		}
		else if(strcmp(bermotor[pos].no_kendaraan,carinopol)==-1){
			low = pos + 1;
		}
	}	
	if(ketemu==1){
		printf("=================================================================\n");
			printf("|                           View Data                           |\n");
			printf("=================================================================\n");
			printf("| No Tiket        : %s\n", bermotor[pos].no_tiket);
			printf("| Tanggal         : %d %s %d\n", bermotor[pos].tanggal.hari, bermotor[pos].tanggal.bulan, bermotor[pos].tanggal.tahun);
			printf("| Nopol Kendaraan : %s\n", bermotor[pos].no_kendaraan);
			printf("| Jenis Kendaraan : %s\n", bermotor[pos].jenis);
			printf("| Bobot Kendaraan : %.2f Kg\n", bermotor[pos].bobot);
			printf("| Tujuan          : %s\n", bermotor[pos].tujuan);
			printf("=================================================================\n");
	}
	else
		printf("data TIDAK DITEMUKAN");  
	getch();
}

void caribobot(){
	float caribobot;
	int low=0, high=i-1, pos, ketemu=0;
	bool berhenti = false;  
  
 	fflush(stdin);
	printf("masukkan bobot kendaraan yang di cari : ");
	scanf("%f",&caribobot);
	
//	if(bermotor[pos].bobot == caribobot){
//			printf("ketemu");
//	}else
//	printf("gaono");
//	getch();
	while(berhenti ==false){
		
		pos = (caribobot-bermotor[low].bobot)/(bermotor[high].bobot-bermotor[low].bobot)*(high-low)+low;
		printf("%d",pos);
		if(bermotor[pos].bobot == caribobot){
			printf("ketemu");
			ketemu = 1;
			berhenti = true;
		}
		else if(bermotor[pos].bobot > caribobot){
			high = pos - 1;
		}
		else if(bermotor[pos].bobot < caribobot){
			low = pos + 1;
		}
	}	
	if(ketemu==1){
		printf("=================================================================\n");
			printf("|                           View Data                           |\n");
			printf("=================================================================\n");
			printf("| No Tiket        : %s\n", bermotor[pos].no_tiket);
			printf("| Tanggal         : %d %s %d\n", bermotor[pos].tanggal.hari, bermotor[pos].tanggal.bulan, bermotor[pos].tanggal.tahun);
			printf("| Nopol Kendaraan : %s\n", bermotor[pos].no_kendaraan);
			printf("| Jenis Kendaraan : %s\n", bermotor[pos].jenis);
			printf("| Bobot Kendaraan : %.2f Kg\n", bermotor[pos].bobot);
			printf("| Tujuan          : %s\n", bermotor[pos].tujuan);
			printf("=================================================================\n");
	}
	else
		printf("data TIDAK DITEMUKAN");  
	getch();
}
