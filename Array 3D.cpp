#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "math.h"

main(){
	int array[3][3][3];
	int jalan=0, pilihan;
	float lintasan=0;
	
	for(int i=0; i<3; i++){
		for(int id=0; id<3; id++){
			for(int idd=0; idd<3; idd++){
				array[i][id][idd] = rand() %10 + 1;
			}
		}
	}
	
	while(jalan==0){
		system("cls");
		printf("1. Tampilkan data\n2. Hitung lintasan\n3. Keluar\n\nMasukkan pilihan : ");
		scanf("%i", &pilihan);
		switch(pilihan){
			case 1 :
				system("cls");
				for(int i=0; i<3; i++){
				printf("\nLintasan ke-%i\n", i+1);
				for(int id=0; id<3; id++){
					printf("\nKoordinat titik ke-%i : ", (id+1));
					for(int idd=0; idd<3; idd++){
						printf("%d	", array[i][id][idd]);
					}
					printf("\n");
				}
				printf("\n==========================================================================================================\n");
				}
				printf("\nTekan sembarang tombol");	
				getch();
				break;
			case 2 :
				system("cls");
				for(int i=0; i<3; i++){
					for(int id=1; id<3; id++){
						lintasan = lintasan + sqrt((pow((array[i][id][0]-array[i][id-1][0]),2))+(pow((array[i][id][1]-array[i][id-1][1]),2))+(pow((array[i][id][2]-array[i][id-1][2]),2)));
					}
					printf("\nLintasan ke-%i : %f\n", i+1, lintasan);
					lintasan=0;
				}
				printf("\nTekan sembarang tombol");	
				getch();
				break;
			case 3 :
				system("cls");
				printf("\n\n\nHave a nice day :)\n\n\n");
				jalan++;
				break;
		}
	}
}
