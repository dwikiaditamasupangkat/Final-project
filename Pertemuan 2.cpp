/*static int i;
static void func();
int max_so_far(int curr){
	static int biggest;
	if (curr > biggest) biggest = curr;
	return biggest
}*/

#include "stdio.h"

void cetak(){
	static int count=0;
	printf("count=%d\n", count++);
}
int main(void){
	int i;
	for(i=0;i<5;i++) cetak();
	for(i=0;i<3;i++) cetak();
	return 0;
}
