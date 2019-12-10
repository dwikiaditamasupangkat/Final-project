#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct tanggal{
	int hari;
	char bulan[20];
	int tahun;
	int jbulan;
	int jtanggal;
};

struct kendaraan{
   int no_tiket;
   char no_kendaraan[100];
   char jenis[100];
   float bobot;
   char tujuan[100];
   tanggal tanggal;
   int jno_kendaraan, jjenis, jtujuan;
};

kendaraan bermotor[100];
kendaraan sementara[100];
int status=0, pilihan, i=0, metode, kriteria, kriteria1, kriteria2, indexing[100], indexing2[100];

void geser(int temp[], int awal, int kiri, int tengah, int akhir, int temp_pos, int jumlah);
void view(int ketemu, int pos);
void kosong();
void input();
void ubah();
void lihat();
void caribobot();
void carinopol();
void caritiket();

int hitungchar(char name[]);
void descendingtiket(int temp[], int awal, int akhir);
void sortdescendingtiket(int temp[], int awal, int tengah, int akhir);
void descendingbobot(int temp[], int awal, int akhir);
void sortdescendingbobot(int temp[], int awal, int tengah, int akhir);
void descendingtujuan(int temp[], int awal, int akhir);
void sortdescendingtujuan(int temp[], int awal, int tengah, int akhir);
void descendingnopol(int temp[], int awal, int akhir);
void sortdescendingnopol(int temp[], int awal, int tengah, int akhir);
void descendingjenis(int temp[], int awal, int akhir);
void sortdescendingjenis(int temp[], int awal, int tengah, int akhir);
void descendingtanggal(int temp[], int awal, int akhir);
void sortdescendingtanggal(int temp[], int awal, int tengah, int akhir);

void ascendingtiket(int temp[], int awal, int akhir);
void sortascendingtiket(int temp[], int awal, int tengah, int akhir);
void ascendingbobot(int temp[], int awal, int akhir);
void sortascendingbobot(int temp[], int awal, int tengah, int akhir);
void ascendingtujuan(int temp[], int awal, int akhir);
void sortascendingtujuan(int temp[], int awal, int tengah, int akhir);
void ascendingnopol(int temp[], int awal, int akhir);
void sortascendingnopol(int temp[], int awal, int tengah, int akhir);
void ascendingjenis(int temp[], int awal, int akhir);
void sortascendingjenis(int temp[], int awal, int tengah, int akhir);
void ascendingtanggal(int temp[], int awal, int akhir);
void sortascendingtanggal(int temp[], int awal, int tengah, int akhir);

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
				if(i==0)
					kosong();
				else
					ascendingtiket(indexing, 0, i-1);
					ubah();
				break;
			case 3 :
				if(i==0)
					kosong();
				else{
					printf("================================\n");
					printf("| Cari Berdasarkan Kriteria :  |\n");
					printf("================================\n");
					printf("| 1. No Tiket                  |\n");
					printf("| 2. Nopol Kendaraan           |\n");
					printf("| 3. Bobot Kendaraan           |\n");
					printf("--------------------------------\n");
					printf("| Masukkan pilihan : ");
					scanf("%d",&kriteria);
					system("cls");
					switch(kriteria){
						case 1 :
							ascendingtiket(indexing, 0, i-1);
							caritiket();		
						break;
						case 2 :
							ascendingnopol(indexing,0, i-1);
							carinopol();
						break;
						case 3 :
							ascendingbobot(indexing, 0, i-1);
							caribobot();
						break;
					}	
				}
				break;
			case 4 :
				if(i==0)
					kosong();
				else
					lihat();
				break;
			case 5 :
				if(i==0)
					kosong();
				else{
					printf("===================================\n");
					printf("| Sorting Berdasarkan Kriteria :  |\n");
					printf("===================================\n");
					printf("| 1. Ascending                    |\n");
					printf("| 2. Descending                   |\n");
					printf("-----------------------------------\n");
					printf("| Masukkan pilihan : ");
					scanf("%d",&metode);
					system("cls");
					switch(metode){
						case 1 : 
							printf("===================================\n");
							printf("| Sorting Ascending Berdasarkan : |\n");
							printf("===================================\n");
							printf("| 1. No Tiket                     |\n");
							printf("| 2. Nopol Kendaraan              |\n");
							printf("| 3. Jenis Kendaraan              |\n");
							printf("| 4. Bobot Kendaraan              |\n");
							printf("| 5. Tujuan                       |\n");
							printf("| 6. Tanggal                      |\n");
							printf("-----------------------------------\n");
							printf("| Masukkan pilihan : ");
							scanf("%d",&kriteria1);
							system("cls");
							switch(kriteria1){
								case 1 :
									ascendingtiket(indexing, 0, i-1);
									lihat();
								break;
								case 2 :
									ascendingnopol(indexing,0, i-1);
									lihat();
								break;
								case 3 :
									ascendingjenis(indexing,0, i-1);
									lihat();
								break;
								case 4 :
									ascendingbobot(indexing, 0, i-1);
									lihat();
								break;
								case 5 :
									ascendingtujuan(indexing, 0, i-1);
									lihat();
								break;
								case 6 :
									ascendingtanggal(indexing,0, i-1);
									lihat();								
								break;
							}
						break;
						case 2 :
							printf("===================================\n");
							printf("| Sorting Descending Berdasarkan :|\n");
							printf("===================================\n");
							printf("| 1. No Tiket                     |\n");
							printf("| 2. Nopol Kendaraan              |\n");
							printf("| 3. Jenis Kendaraan              |\n");
							printf("| 4. Bobot Kendaraan              |\n");
							printf("| 5. Tujuan                       |\n");
							printf("| 6. Tanggal                      |\n");
							printf("-----------------------------------\n");
							printf("| Masukkan pilihan : ");
							scanf("%d",&kriteria2);
							system("cls");
							switch(kriteria2){
								case 1 :
									descendingtiket(indexing, 0, i-1);
									lihat();
								break;
								case 2 :
									descendingnopol(indexing,0, i-1);
									lihat();
								break;
								case 3 :
									descendingjenis(indexing,0, i-1);
									lihat();
								break;
								case 4 :
									descendingbobot(indexing, 0, i-1);
									lihat();
								break;
								case 5 :
									descendingtujuan(indexing, 0, i-1);
									lihat();
								break;
								case 6 :
									descendingtanggal(indexing,0, i-1);
									lihat();
								break;
							}
							break;
						}	
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

void kosong(){
	printf("===================================\n");
	printf("|                                 |\n");
	printf("|        ~~ DATA KOSONG ~~        |\n");
	printf("|                                 |\n");
	printf("===================================\n");
	getch();
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
	printf("| Masukkan Tanggal(dd month yyyy): ");
	scanf("%d %s %d", &bermotor[i].tanggal.hari,&bermotor[i].tanggal.bulan,&bermotor[i].tanggal.tahun);
	if (strcmp(bermotor[i].tanggal.bulan, "Januari") == 0 || strcmp(bermotor[i].tanggal.bulan, "januari") == 0){
		bermotor[i].tanggal.jbulan = 1;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "Februari") == 0|| strcmp(bermotor[i].tanggal.bulan, "februari") == 0){
		bermotor[i].tanggal.jbulan = 2;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "Maret") == 0 || strcmp(bermotor[i].tanggal.bulan, "maret") == 0){
		bermotor[i].tanggal.jbulan = 3;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "April") == 0 || strcmp(bermotor[i].tanggal.bulan, "april") == 0){
		bermotor[i].tanggal.jbulan = 4;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "Mei") == 0 || strcmp(bermotor[i].tanggal.bulan, "mei") == 0){
		bermotor[i].tanggal.jbulan = 5;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "Juni") == 0 || strcmp(bermotor[i].tanggal.bulan, "juni") == 0){
		bermotor[i].tanggal.jbulan = 6;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "Juli") == 0 || strcmp(bermotor[i].tanggal.bulan, "juli") == 0){
		bermotor[i].tanggal.jbulan = 7;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "Agustus") == 0 || strcmp(bermotor[i].tanggal.bulan, "agustus") == 0){
		bermotor[i].tanggal.jbulan = 8;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "September") == 0 || strcmp(bermotor[i].tanggal.bulan, "september") == 0){
		bermotor[i].tanggal.jbulan = 9;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "Oktober") == 0 || strcmp(bermotor[i].tanggal.bulan, "oktober") == 0){
		bermotor[i].tanggal.jbulan = 10;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "November") == 0 || strcmp(bermotor[i].tanggal.bulan, "november") == 0){
		bermotor[i].tanggal.jbulan = 11;
	}
	else if (strcmp(bermotor[i].tanggal.bulan, "Desember") == 0 || strcmp(bermotor[i].tanggal.bulan, "desember") == 0){
		bermotor[i].tanggal.jbulan = 12;
	}
	bermotor[i].tanggal.jtanggal = (bermotor[i].tanggal.tahun*10000) + (bermotor[i].tanggal.jbulan*100) +(bermotor[i].tanggal.hari);
	printf("-----------------------------------------------------------------\n");
	fflush(stdin);
	printf("| Masukkan Nopol Kendaraan       : ");
	gets(bermotor[i].no_kendaraan);
	bermotor[i].jno_kendaraan = hitungchar(bermotor[i].no_kendaraan);
	printf("-----------------------------------------------------------------\n");
	fflush(stdin);
	printf("| Pilih Jenis Kendaraan");
	printf("\n| 1. Truk \n| 2. Pick up \n| 3. Bus \n| 4. Minibus \n| 5. Sedan \n| 6. Motor\n");
	printf("| Masukkan Jenis Kendaraan       : ");
	scanf("%d", &jenis);
	switch(jenis){
		case 1 : 
			strcpy(bermotor[i].jenis, "Truk");
			bermotor[i].jjenis = hitungchar(bermotor[i].jenis);
		break;
		case 2 : 
			strcpy(bermotor[i].jenis, "Pick Up");
			bermotor[i].jjenis = hitungchar(bermotor[i].jenis);
		break;
		case 3 : 
			strcpy(bermotor[i].jenis, "Bus");
			bermotor[i].jjenis = hitungchar(bermotor[i].jenis);
		break;
		case 4 : 
			strcpy(bermotor[i].jenis, "Minibus");
			bermotor[i].jjenis = hitungchar(bermotor[i].jenis);
		break;
		case 5 : 
			strcpy(bermotor[i].jenis, "Sedan");
			bermotor[i].jjenis = hitungchar(bermotor[i].jenis);
		break;
		case 6 : 
			strcpy(bermotor[i].jenis, "Motor");
			bermotor[i].jjenis = hitungchar(bermotor[i].jenis);
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
		case 1 : 
			strcpy(bermotor[i].tujuan, "Ketapang");
			bermotor[i].jtujuan = hitungchar(bermotor[i].tujuan);
		break;
		case 2 : 
			strcpy(bermotor[i].tujuan, "Padang Bai");
			bermotor[i].jtujuan = hitungchar(bermotor[i].tujuan);
		break;
		case 3 : 
			strcpy(bermotor[i].tujuan, "Lembar");
			bermotor[i].jtujuan = hitungchar(bermotor[i].tujuan);
		break;
		case 4 : 
			strcpy(bermotor[i].tujuan, "Tanjung Perak");
			bermotor[i].jtujuan = hitungchar(bermotor[i].tujuan);
		break;	
	}
	printf("-----------------------------------------------------------------\n");
	i++;
	getch();
}

void lihat(){
	for(int a=0; a<i; a++){
		printf("=================================================================\n");
		printf("|                           View Data                           |\n");
		printf("=================================================================\n");
		printf("| No Tiket        : %d\n", bermotor[a].no_tiket);
		printf("| Tanggal         : %d %s %d\n", bermotor[a].tanggal.hari, bermotor[a].tanggal.bulan, bermotor[a].tanggal.tahun);
		printf("| Nopol Kendaraan : %s\n", bermotor[a].no_kendaraan);
		printf("| Jenis Kendaraan : %s\n", bermotor[a].jenis);
		printf("| Bobot Kendaraan : %.2f Ton\n", bermotor[a].bobot);
		printf("| Tujuan          : %s\n", bermotor[a].tujuan);
		printf("=================================================================\n");
	}	
	getch();
}

void view(int ketemu, int pos){
	if(ketemu==1){
		printf("=================================================================\n");
		printf("|                           View Data                           |\n");
		printf("=================================================================\n");
		printf("| No Tiket        : %d\n", bermotor[pos].no_tiket);
		printf("| Tanggal         : %d %s %d\n", bermotor[pos].tanggal.hari, bermotor[pos].tanggal.bulan, bermotor[pos].tanggal.tahun);
		printf("| Nopol Kendaraan : %s\n", bermotor[pos].no_kendaraan);
		printf("| Jenis Kendaraan : %s\n", bermotor[pos].jenis);
		printf("| Bobot Kendaraan : %.2f Ton\n", bermotor[pos].bobot);
		printf("| Tujuan          : %s\n", bermotor[pos].tujuan);
		printf("=================================================================\n");
	}
	else{
		printf("=================================================================\n");
		printf("|                                                               |\n");
		printf("|                  ~~ DATA TIDAK DITEMUKAN ~~                   |\n");
		printf("|                                                               |\n");
		printf("=================================================================\n");
	}
}
void ubah(){	
	int caritiket;
	int low=0, high=i-1, pos, ketemu=0;
  
	printf("=================================================================\n");
	printf("|                            Ubah Data                          |\n");
	printf("=================================================================\n");
	fflush(stdin);
	printf("| Masukkan No Tiket Yang Akan di Ubah : ");
	scanf("%d", &caritiket);
	printf("=================================================================\n");
	
	for(int a=0;a<i;a++){	
		pos = (caritiket-bermotor[low].no_tiket)/(bermotor[high].no_tiket-bermotor[low].no_tiket)*(high-low)+low;
		if(pos>=0 && pos<=high){
			if(bermotor[pos].no_tiket == caritiket){
				ketemu = 1;
				break;
			}
			else if(bermotor[pos].no_tiket < caritiket){
				high = pos - 1;
			}
			else if(bermotor[pos].no_tiket > caritiket){
				low = pos + 1;
			}
		}
	}	
	if(ketemu==1){
		int jenis, tujuan;
		printf("=================================================================\n");
		printf("|                         Form Ubah Data                        |\n");
		printf("=================================================================\n");
		fflush(stdin);
		bermotor[pos].no_tiket = caritiket;
		printf("-----------------------------------------------------------------\n");
		fflush(stdin);
		printf("| Masukkan Tanggal(dd month yyyy): ");
		scanf("%d %s %d", &bermotor[pos].tanggal.hari,&bermotor[pos].tanggal.bulan,&bermotor[pos].tanggal.tahun);
		if (strcmp(bermotor[pos].tanggal.bulan, "Januari") == 0 || strcmp(bermotor[pos].tanggal.bulan, "januari") == 0){
			bermotor[pos].tanggal.jbulan = 1;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "Februari") == 0|| strcmp(bermotor[pos].tanggal.bulan, "februari") == 0){
			bermotor[pos].tanggal.jbulan = 2;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "Maret") == 0 || strcmp(bermotor[pos].tanggal.bulan, "maret") == 0){
			bermotor[pos].tanggal.jbulan = 3;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "April") == 0 || strcmp(bermotor[pos].tanggal.bulan, "april") == 0){
			bermotor[pos].tanggal.jbulan = 4;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "Mei") == 0 || strcmp(bermotor[pos].tanggal.bulan, "mei") == 0){
			bermotor[pos].tanggal.jbulan = 5;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "Juni") == 0 || strcmp(bermotor[pos].tanggal.bulan, "juni") == 0){
			bermotor[pos].tanggal.jbulan = 6;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "Juli") == 0 || strcmp(bermotor[pos].tanggal.bulan, "juli") == 0){
			bermotor[pos].tanggal.jbulan = 7;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "Agustus") == 0 || strcmp(bermotor[pos].tanggal.bulan, "agustus") == 0){
			bermotor[pos].tanggal.jbulan = 8;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "September") == 0 || strcmp(bermotor[pos].tanggal.bulan, "september") == 0){
			bermotor[pos].tanggal.jbulan = 9;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "Oktober") == 0 || strcmp(bermotor[pos].tanggal.bulan, "oktober") == 0){
			bermotor[pos].tanggal.jbulan = 10;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "November") == 0 || strcmp(bermotor[pos].tanggal.bulan, "november") == 0){
			bermotor[pos].tanggal.jbulan = 11;
		}
		else if (strcmp(bermotor[pos].tanggal.bulan, "Desember") == 0 || strcmp(bermotor[pos].tanggal.bulan, "desember") == 0){
			bermotor[pos].tanggal.jbulan = 12;
		}
		bermotor[pos].tanggal.jtanggal = (bermotor[pos].tanggal.tahun*10000) + (bermotor[pos].tanggal.jbulan*100) +(bermotor[pos].tanggal.hari);
		printf("-----------------------------------------------------------------\n");
		fflush(stdin);
		printf("| Masukkan Nopol Kendaraan       : ");
		gets(bermotor[pos].no_kendaraan);
		bermotor[pos].jno_kendaraan = hitungchar(bermotor[pos].no_kendaraan);
		printf("-----------------------------------------------------------------\n");
		fflush(stdin);
		printf("| Pilih Jenis Kendaraan");
		printf("\n| 1. Truk \n| 2. Pick up \n| 3. Bus \n| 4. Minibus \n| 5. Sedan \n| 6. Motor\n");
		printf("| Masukkan Jenis Kendaraan       : ");
		scanf("%d", &jenis);
		switch(jenis){
			case 1 : 
				strcpy(bermotor[pos].jenis, "Truk");
				bermotor[pos].jjenis = hitungchar(bermotor[pos].jenis);
			break;
			case 2 : 
				strcpy(bermotor[pos].jenis, "Pick Up");
				bermotor[pos].jjenis = hitungchar(bermotor[pos].jenis);
			break;
			case 3 : 
				strcpy(bermotor[pos].jenis, "Bus");
				bermotor[pos].jjenis = hitungchar(bermotor[pos].jenis);
			break;
			case 4 : 
				strcpy(bermotor[pos].jenis, "Minibus");
				bermotor[pos].jjenis = hitungchar(bermotor[pos].jenis);
			break;
			case 5 : 
				strcpy(bermotor[pos].jenis, "Sedan");
				bermotor[pos].jjenis = hitungchar(bermotor[pos].jenis);
			break;
			case 6 : 
				strcpy(bermotor[pos].jenis, "Motor");
				bermotor[pos].jjenis = hitungchar(bermotor[pos].jenis);
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
			case 1 : 
				strcpy(bermotor[pos].tujuan, "Ketapang");
				bermotor[pos].jtujuan = hitungchar(bermotor[pos].tujuan);
			break;
			case 2 : 
				strcpy(bermotor[pos].tujuan, "Padang Bai");
				bermotor[pos].jtujuan = hitungchar(bermotor[pos].tujuan);
			break;
			case 3 : 
				strcpy(bermotor[pos].tujuan, "Lembar");
				bermotor[pos].jtujuan = hitungchar(bermotor[pos].tujuan);
			break;
			case 4 : 
				strcpy(bermotor[pos].tujuan, "Tanjung Perak");
				bermotor[pos].jtujuan = hitungchar(bermotor[pos].tujuan);
			break;	
		}
		printf("-----------------------------------------------------------------\n");	}
	else{
		printf("====================================\n");
		printf("|                                  |\n");
		printf("|    ~~ DATA TIDAK DITEMUKAN ~~    |\n");
		printf("|                                  |\n");
		printf("====================================\n");
	}  
	getch();
}
void caritiket(){	
	int caritiket;
	int low=0, high=i-1, pos, ketemu=0;
	printf("=================================================================\n");
	printf("|                          Cari Data :                          |\n");
	printf("=================================================================\n");
 	fflush(stdin);
	printf("masukkan  no tiket yang di cari : ");
	scanf("%d",&caritiket);
	printf("=================================================================\n\n");
	
	for(int a=0;a<i;a++){
		pos = (caritiket-bermotor[low].no_tiket)/(bermotor[high].no_tiket-bermotor[low].no_tiket)*(high-low)+low;
		if(pos>=0 && pos<=high){
			if(bermotor[pos].no_tiket == caritiket){
				ketemu = 1;
				break;
			}
			else if(bermotor[pos].no_tiket > caritiket){
				high = pos - 1;
			}
			else if(bermotor[pos].no_tiket < caritiket){
				low = pos + 1;
			}	
		}
	}
	view(ketemu, pos);  
	getch();
}

void carinopol(){
	char carinopol[100];
	int jnopol;
	int low=0, high=i-1, pos, ketemu=0;
	
	printf("=================================================================\n");
	printf("|                          Cari Data :                          |\n");
	printf("=================================================================\n");
 	fflush(stdin);
	printf("Masukkan Nopol Kendaraan Yang di Cari :  ");
	gets(carinopol);
	jnopol = hitungchar(carinopol);	
	printf("=================================================================\n\n");
	
	for(int a=0;a<i;a++){
		pos = (jnopol-bermotor[low].jno_kendaraan)/(bermotor[high].jno_kendaraan-bermotor[low].jno_kendaraan)*(high-low)+low;
		printf("jnopol : %d\n",jnopol);
		printf("jkendaraaan : %d\n",bermotor[pos].jno_kendaraan);
		if(pos>=0 && pos<=high){
			if(bermotor[pos].jno_kendaraan == jnopol){
				ketemu = 1;
				break;
			}
			else if(bermotor[pos].jno_kendaraan > jnopol){
				high = pos - 1;
			}
			else if(bermotor[pos].jno_kendaraan < jnopol){
				low = pos + 1;
			}	
		}
		
	}
	view(ketemu, pos);  
	getch();
}

void caribobot(){
	float caribobot;
	int low=0, high=i-1, pos, ketemu=0;
	
	printf("=================================================================\n");
	printf("|                          Cari Data :                          |\n");
	printf("=================================================================\n");
	fflush(stdin);
	printf("Masukkan Bobot Kendaraan Yang di Cari :  ");
	scanf("%f",&caribobot);
	printf("=================================================================\n\n");
	for(int a=0;a<i;a++){
		pos = (caribobot-bermotor[low].bobot)/(bermotor[high].bobot-bermotor[low].bobot)*(high-low)+low;
		if(pos>=0 && pos<=high){
			if(bermotor[pos].bobot == caribobot){
				ketemu = 1;
				break;
			}
			else if(bermotor[pos].bobot > caribobot){
				high = pos - 1;
			}
			else if(bermotor[pos].bobot < caribobot){
				low = pos + 1;
			}	
		}
		
	}
	view(ketemu, pos);
	getch();
}

int hitungchar( char name[]){
	int jumlah = 0;
	int indeks = 0;
	int batas = 100000;
	
	while (name[indeks] != NULL && batas > 0){
		int cek = name[indeks];
		jumlah = jumlah + (batas*cek);
		indeks++;
		batas = batas/2;
	}
	return jumlah;
}

void geser(int temp[], int awal, int kiri, int tengah, int akhir, int temp_pos, int jumlah){
	while(awal <= kiri){
		sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
		sementara[temp_pos].bobot = bermotor[awal].bobot;
		strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
		strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
		sementara[temp_pos].tanggal = bermotor[awal].tanggal;
		strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
		sementara[temp_pos].jjenis = bermotor[awal].jjenis;
		sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
		sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
		awal = awal+1;
		temp_pos = temp_pos+1;
	}
	
	while(tengah <= akhir){
		sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
		sementara[temp_pos].bobot = bermotor[tengah].bobot;
		strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
		strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
		sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
		strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
		sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
		sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
		sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
		tengah = tengah+1;
		temp_pos = temp_pos+1;
	}
	
	for(int i=0; i<jumlah;i++){
		strcpy(bermotor[akhir].tujuan, sementara[akhir].tujuan);
		bermotor[akhir].bobot= sementara[akhir].bobot;
		strcpy(bermotor[akhir].jenis, sementara[akhir].jenis);
		strcpy(bermotor[akhir].no_kendaraan, sementara[akhir].no_kendaraan);
		bermotor[akhir].no_tiket= sementara[akhir].no_tiket;
		bermotor[akhir].tanggal= sementara[akhir].tanggal;
		bermotor[akhir].jjenis = sementara[akhir].jjenis;
		bermotor[akhir].jno_kendaraan = sementara[akhir].jno_kendaraan;
		bermotor[akhir].jtujuan = sementara[akhir].jtujuan;
		
		akhir = akhir-1;
	}
}


void descendingtiket(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		descendingtiket(temp, awal, tengah);
		//pisah kanan
		descendingtiket(temp, (tengah+1), akhir);
		
		sortdescendingtiket(temp, awal, (tengah+1), akhir);
	}
}

void sortdescendingtiket(int temp[], int awal, int tengah, int akhir){
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	
	while((awal<=kiri) && (tengah<=akhir)){
		if(bermotor[awal].no_tiket >= bermotor[tengah].no_tiket){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);

}

void descendingbobot(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		descendingbobot(temp, awal, tengah);
		//pisah kanan
		descendingbobot(temp, (tengah+1), akhir);
		
		sortdescendingbobot(temp, awal, (tengah+1), akhir);
	}
}

void sortdescendingbobot(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	
	while((awal<=kiri) && (tengah<=akhir)){
		if(bermotor[awal].bobot >= bermotor[tengah].bobot){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void descendingtujuan(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		descendingtujuan(temp, awal, tengah);
		//pisah kanan
		descendingtujuan(temp, (tengah+1), akhir);
		
		sortdescendingtujuan(temp, awal, (tengah+1), akhir);
	}
}

void sortdescendingtujuan(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	while((awal<=kiri) && (tengah<=akhir)){
		if(strcmp(bermotor[awal].tujuan, bermotor[tengah].tujuan)!=-1){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void descendingnopol(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		descendingnopol(temp, awal, tengah);
		//pisah kanan
		descendingnopol(temp, (tengah+1), akhir);
		
		sortdescendingnopol(temp, awal, (tengah+1), akhir);
	}
}

void sortdescendingnopol(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	while((awal<=kiri) && (tengah<=akhir)){
		if(strcmp(bermotor[awal].no_kendaraan, bermotor[tengah].no_kendaraan)!=-1){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
		
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void descendingjenis(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		descendingjenis(temp, awal, tengah);
		//pisah kanan
		descendingjenis(temp, (tengah+1), akhir);
		
		sortdescendingjenis(temp, awal, (tengah+1), akhir);
	}
}

void sortdescendingjenis(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	while((awal<=kiri) && (tengah<=akhir)){
		if(strcmp(bermotor[awal].jenis, bermotor[tengah].jenis)!=-1){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void descendingtanggal(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		descendingtanggal(temp, awal, tengah);
		//pisah kanan
		descendingtanggal(temp, (tengah+1), akhir);
		
		sortdescendingtanggal(temp, awal, (tengah+1), akhir);
	}
}

void sortdescendingtanggal(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	while((awal<=kiri) && (tengah<=akhir)){
		if(bermotor[awal].tanggal.jtanggal >= bermotor[tengah].tanggal.jtanggal){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void ascendingtiket(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		ascendingtiket(temp, awal, tengah);
		//pisah kanan
		ascendingtiket(temp, (tengah+1), akhir);
		
		sortascendingtiket(temp, awal, (tengah+1), akhir);
	}
}

void sortascendingtiket(int temp[], int awal, int tengah, int akhir){
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	
	while((awal<=kiri) && (tengah<=akhir)){
		if(bermotor[awal].no_tiket <= bermotor[tengah].no_tiket){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void ascendingbobot(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		ascendingbobot(temp, awal, tengah);
		//pisah kanan
		ascendingbobot(temp, (tengah+1), akhir);
		
		sortascendingbobot(temp, awal, (tengah+1), akhir);
	}
}

void sortascendingbobot(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	
	while((awal<=kiri) && (tengah<=akhir)){
		if(bermotor[awal].bobot <= bermotor[tengah].bobot){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void ascendingtujuan(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		ascendingtujuan(temp, awal, tengah);
		//pisah kanan
		ascendingtujuan(temp, (tengah+1), akhir);
		
		sortascendingtujuan(temp, awal, (tengah+1), akhir);
	}
}

void sortascendingtujuan(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	while((awal<=kiri) && (tengah<=akhir)){
		if(strcmp(bermotor[awal].tujuan, bermotor[tengah].tujuan)!=1){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void ascendingnopol(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		ascendingnopol(temp, awal, tengah);
		//pisah kanan
		ascendingnopol(temp, (tengah+1), akhir);
		
		sortascendingnopol(temp, awal, (tengah+1), akhir);
	}
}

void sortascendingnopol(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	while((awal<=kiri) && (tengah<=akhir)){
		if(strcmp(bermotor[awal].no_kendaraan, bermotor[tengah].no_kendaraan)!=1){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void ascendingjenis(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		ascendingjenis(temp, awal, tengah);
		//pisah kanan
		ascendingjenis(temp, (tengah+1), akhir);
		
		sortascendingjenis(temp, awal, (tengah+1), akhir);
	}
}

void sortascendingjenis(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	while((awal<=kiri) && (tengah<=akhir)){
		if(strcmp(bermotor[awal].jenis, bermotor[tengah].jenis)!=1){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}

void ascendingtanggal(int temp[], int awal, int akhir){
	int tengah;
	
	if(akhir>awal){
		tengah=(akhir+awal)/2;
		//pisah kiri
		ascendingtanggal(temp, awal, tengah);
		//pisah kanan
		ascendingtanggal(temp, (tengah+1), akhir);
		
		sortascendingtanggal(temp, awal, (tengah+1), akhir);
	}
}

void sortascendingtanggal(int temp[], int awal, int tengah, int akhir){
	
	int kiri, jumlah, temp_pos;
	
	kiri = (tengah-1);
	temp_pos = awal;
	jumlah = (akhir-awal)+1;
	while((awal<=kiri) && (tengah<=akhir)){
		if(bermotor[awal].tanggal.jtanggal <= bermotor[tengah].tanggal.jtanggal){
			sementara[temp_pos].no_tiket = bermotor[awal].no_tiket;
			sementara[temp_pos].bobot = bermotor[awal].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[awal].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[awal].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[awal].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[awal].tujuan);
			sementara[temp_pos].jjenis = bermotor[awal].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[awal].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[awal].jtujuan;
			temp_pos = temp_pos+1;
			awal = awal+1;
		}else{
			sementara[temp_pos].no_tiket = bermotor[tengah].no_tiket;
			sementara[temp_pos].bobot = bermotor[tengah].bobot;
			strcpy(sementara[temp_pos].jenis, bermotor[tengah].jenis);
			strcpy(sementara[temp_pos].no_kendaraan, bermotor[tengah].no_kendaraan);
			sementara[temp_pos].tanggal = bermotor[tengah].tanggal;
			strcpy(sementara[temp_pos].tujuan, bermotor[tengah].tujuan);
			sementara[temp_pos].jjenis = bermotor[tengah].jjenis;
			sementara[temp_pos].jno_kendaraan = bermotor[tengah].jno_kendaraan;
			sementara[temp_pos].jtujuan = bermotor[tengah].jtujuan;
			temp_pos = temp_pos+1;
			tengah = tengah+1;
		}
	}
	
	geser(indexing2, awal, kiri, tengah, akhir, temp_pos, jumlah);
}
