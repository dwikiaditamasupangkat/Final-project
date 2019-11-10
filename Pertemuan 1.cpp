#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

struct hp{
	char merk[10];
	char type[10];
	int RAM;
	int memory;
};

int main(){
	hp baru;
	strcpy(baru.merk, "Xiaomi");
	strcpy(baru.type, "Redmi 7");
	baru.RAM = 8;
	baru.memory = 64;
	printf("Merk		: %s\n", baru.merk);
	printf("Type		: %s\n", baru.type);
	printf("RAM		: %i Gb\n", baru.RAM);
	printf("Memory		: %i Gb\n", baru.memory);
	printf("Alamat merk	: %d\n", &baru.merk);
	int harga = 2000000;
	int *ph = &harga;
	printf("Alamat harga	: %d", ph);
	ph = &harga*2;
	printf("Alamat harga	: %d", ph);
}
