#include "stdio.h"

struct data_mahasiswa
{
	float IPK;
	int NPM;
};

int main(){
	struct data_mahasiswa mhs[20];
	mhs[0].NPM = 10059;
	mhs[1].NPM = 10060;
	mhs[2].NPM = 10061;
	mhs[3].NPM = 10062;
	mhs[4].NPM = 10063;
	mhs[5].NPM = 10064;
	mhs[6].NPM = 10065;
	mhs[7].NPM = 10066;
	mhs[8].NPM = 10067;
	mhs[9].NPM = 10068;
	
	mhs[0].IPK = 3.12;
	mhs[1].IPK = 3.42;
	mhs[2].IPK = 3.13;
	mhs[3].IPK = 3.76;
	mhs[4].IPK = 3.86;
	mhs[5].IPK = 3.34;
	mhs[6].IPK = 3.45;
	mhs[7].IPK = 3.44;
	mhs[8].IPK = 3.87;
	mhs[9].IPK = 3.64;
	
	float IPK[10] = {3.12, 3.42, 3.13, 3.76, 3.86, 3.34, 3.45, 3.44, 3.87, 3.64};
	int NPM[10] = {10059, 10060, 10061, 10062, 10063, 10064, 10065, 10066, 10067, 10068};
	
	printf("Menggunakan array biasa\n");
	for(int indeks = 0; indeks<10; indeks++){
		printf("NPM-%i memiliki IPK : %f \n", NPM[indeks], IPK[indeks]);
	}
	
	printf("\nMenggunakan struct\n");
	for(int indeks = 0; indeks<10; indeks++){
		printf("NPM-%i memiliki IPK : %f \n", mhs[indeks].NPM, mhs[indeks].IPK);
	}
}
