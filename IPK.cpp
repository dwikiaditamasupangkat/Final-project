#include "stdio.h"

struct mahasiswa{
	char nama[30];
	float IP;
	int SKS;
}mahasiswa[10][6];

int main(){
	int jumlah, SKS, SKSt=0;
	float IPK, IPS=0;
	printf("Masukkan jumlah mahasiswa : ");
	scanf("%i", &jumlah);
	for(int index=0; index<jumlah; index++){
		SKSt=0;
		fflush(stdin);
		printf("\nMasukkan nama Mahasiswa ke-%i : ", (index+1));
		gets(mahasiswa[index][0].nama);
		for(int indexd=0; indexd<7; indexd++){
			switch(indexd){
				case 0 :
					printf("\nMasukkan nilai mata kuliah pemrograman : ");
					scanf("%f", &mahasiswa[index][indexd].IP);
					printf("\nMasukkan jumlah SKS : ");
					scanf("%i", &mahasiswa[index][indexd].SKS);
					SKSt= mahasiswa[index][indexd].SKS;
					IPS=IPS+(mahasiswa[index][indexd].IP*mahasiswa[index][indexd].SKS);
					break;
				case 1 :
					printf("\nMasukkan nilai mata kuliah kalkulus : ");
					scanf("%f", &mahasiswa[index][indexd].IP);
					printf("\nMasukkan jumlah SKS : ");
					scanf("%i", &mahasiswa[index][indexd].SKS);
					SKSt= SKSt+mahasiswa[index][indexd].SKS;
					IPS=IPS+(mahasiswa[index][indexd].IP*mahasiswa[index][indexd].SKS);
					break;
				case 2 :
					printf("\nMasukkan nilai mata kuliah pancasila : ");
					scanf("%f", &mahasiswa[index][indexd].IP);
					printf("\nMasukkan jumlah SKS : ");
					scanf("%i", &mahasiswa[index][indexd].SKS);
					SKSt= SKSt+mahasiswa[index][indexd].SKS;
					IPS=IPS+(mahasiswa[index][indexd].IP*mahasiswa[index][indexd].SKS);
					break;
				case 3 :
					printf("\nMasukkan nilai mata kuliah belanegara : ");
					scanf("%f", &mahasiswa[index][indexd].IP);
					printf("\nMasukkan jumlah SKS : ");
					scanf("%i", &mahasiswa[index][indexd].SKS);
					SKSt= SKSt+mahasiswa[index][indexd].SKS;
					IPS=IPS+(mahasiswa[index][indexd].IP*mahasiswa[index][indexd].SKS);
					break;
				case 4 :
					printf("\nMasukkan nilai mata kuliah sistem informasi : ");
					scanf("%f", &mahasiswa[index][indexd].IP);
					printf("\nMasukkan jumlah SKS : ");
					scanf("%i", &mahasiswa[index][indexd].SKS);
					SKSt= SKSt+mahasiswa[index][indexd].SKS;
					IPS=IPS+(mahasiswa[index][indexd].IP*mahasiswa[index][indexd].SKS);
					break;
				case 5 :
					printf("\nMasukkan nilai mata kuliah sistem operasi : ");
					scanf("%f", &mahasiswa[index][indexd].IP);
					printf("\nMasukkan jumlah SKS : ");
					scanf("%i", &mahasiswa[index][indexd].SKS);
					SKSt= SKSt+mahasiswa[index][indexd].SKS;
					IPS=IPS+(mahasiswa[index][indexd].IP*mahasiswa[index][indexd].SKS);
					break;
				case 6 :
					printf("\nMasukkan nilai mata kuliah kewirausahaan : ");
					scanf("%f", &mahasiswa[index][indexd].IP);
					printf("\nMasukkan jumlah SKS : ");
					scanf("%i", &mahasiswa[index][indexd].SKS);
					SKSt= SKSt+mahasiswa[index][indexd].SKS;
					IPS=IPS+(mahasiswa[index][indexd].IP*mahasiswa[index][indexd].SKS);
					mahasiswa[index][0].IP=IPS;
					break;
			}
		}
		mahasiswa[index][0].SKS=SKSt;
	}
	for(int index=0; index<jumlah; index++){
		printf("\nNama Mahasiswa : ", mahasiswa[index][0].nama);
		for(int indexd=0; indexd<7; indexd++){
			switch(indexd){
				case 0 :
					printf("\nNilai mata kuliah pemrograman : %f", mahasiswa[index][indexd].IP);
					break;
				case 1 :
					printf("\nNilai mata kuliah kalkulus : %f", mahasiswa[index][indexd].IP);
					break;
				case 2 :
					printf("\nNilai mata kuliah pancasila : %f", mahasiswa[index][indexd].IP);
					break;
				case 3 :
					printf("\nNilai mata kuliah belanegara : %f", mahasiswa[index][indexd].IP);
					break;
				case 4 :
					printf("\nNilai mata kuliah sistem informasi : %f", mahasiswa[index][indexd].IP);
					break;
				case 5 :
					printf("\nNilai mata kuliah sistem operasi : %f", mahasiswa[index][indexd].IP);
					break;
				case 6 :
					printf("\nNilai mata kuliah kewirausahaan : %f", mahasiswa[index][indexd].IP);
					break;
			}
		}
		IPK = mahasiswa[index][0].IP/mahasiswa[index][0].SKS;
		printf("\nIPS : %f", IPS);
		printf("\nSKS : %i", SKSt);
		printf("\nIPK : %f", IPK);
	}
}
