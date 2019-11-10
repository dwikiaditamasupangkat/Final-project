#include "bits/stdc++.h"

class node { 
public: 
    int data; 
    node* next; 
}; 

int main(){
	int jumlah = 0, pilihan;
	
	//buat node
	node* kepala = new node();
	node* badan1 = new node();
	node* badan2 = new node();
	node* badan3 = new node();
	node* ekor = new node();
	
	//isi node
	kepala -> data = rand() %10;
	kepala -> next = badan1;
	
	badan1 -> data = rand() %10;
	badan1 -> next = badan2;
	
	badan2 -> data = rand() %10;
	badan2 -> next = badan3;
	
	badan3 -> data = rand() %10;
	badan3 -> next = ekor;
	
	ekor -> data = rand() %10;
	ekor -> next = NULL;
	
	//akses node
	printf("Linked list awal :\n");
	node* temp = kepala;
	while(temp != NULL){
		//jumlahkan data
		printf ("%d ", temp -> data);
		jumlah = jumlah + temp -> data;
		//akses node selanjutnya 
		temp = temp->next;
	}
	printf("\n\nJumlah = %d\n\n", jumlah);
	
	//hapus node awal
	printf("Hapus node awal : \n");
	kepala = NULL;
	temp = badan1;
	while(temp != NULL){
		//jumlahkan & tampilkan data
		printf ("%d ", temp -> data);
		jumlah = jumlah + temp -> data;
		//akses node selanjutnya 
		temp = temp->next;
	}
	
	//hapus node akhir
	printf("\nHapus node akhir : \n");
	ekor = NULL;
	badan3 -> next = NULL;
	temp = badan1;
	while(temp != NULL){
		printf ("%d ", temp -> data);
		jumlah = jumlah + temp -> data;
		temp = temp->next;
	}
	
	//tambah data di akhir
	printf("\nTambah data di akhir : \n");
	node* badan4 = new node();
	badan3 -> next = badan4;
	badan4 -> data = rand() %10;
	badan4 -> next = NULL;
	temp = badan1;
	while(temp != NULL){
		printf ("%d ", temp -> data);
		jumlah = jumlah + temp -> data;
		temp = temp->next;
	}
}
