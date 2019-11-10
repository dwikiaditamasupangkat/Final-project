#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

int urut(int angka[], int loop, int flag){
	
	printf("\n\nData shorting : ");
	for(int indeks = 0; indeks < 10; indeks++){
		printf("%d ", angka[indeks]);
	}
	
	if(angka[loop] < angka[loop-1] && loop > 0){
		int bantuan = angka[loop-1];
		angka[loop-1] = angka[loop];
		angka[loop] = bantuan;
		loop--;
		urut(angka, loop, flag);
	}
	else if(angka[loop] > angka[loop-1] && loop > 0){
		loop--;
		urut(angka, loop, flag);
	}
	else if(loop == 0 && flag < 5){
		flag++;
		urut(angka, 9, flag);
	}
}

int main(){
	static int angka [10] = {36, 24, 5, 63, 10, 32, 6, 80, 9, 64};
	
	printf("Data : ");
	for(int indeks = 0; indeks < 10; indeks++){
		printf("%d ", angka[indeks]);
	}
	
	urut(angka, 9, 0);
	
	printf("\n\nData setelah shorting : ");
	for(int indeks = 0; indeks < 10; indeks++){
		printf("%d ", angka[indeks]);
	}
}
