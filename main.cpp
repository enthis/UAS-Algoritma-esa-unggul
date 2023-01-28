#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};
typedef struct node* item;
struct queue{
	int count;
	item front;
	item rear;
};
typedef struct queue* antrian;
void init(antrian q){
	q->count = 0;
	q->front = NULL;
	q->rear = NULL;
}
bool isEmpty(antrian q){
	return (q->rear == NULL);
}
void insertFront(antrian q, int v){
	item newItem;
	newItem = new node();
	newItem->data = v;
	newItem->next = NULL;
	
	if(!isEmpty(q)){
		newItem->next = q->front;
		q->front = newItem;
	}else{
		q->rear = q->front = newItem;
	}
	q->count++;
}
void insertRear(antrian q, int v){
	item newItem;
	newItem = new node();
	newItem->data = v;
	newItem->next = NULL;
	
	if(!isEmpty(q)){
		q->rear->next = newItem;
		q->rear = newItem;
	}else{
		q->rear = q->front = newItem;
	}
	q->count++;
}
void remove(antrian q){
	item temp;
	temp = q->front;
	q->front = q->front->next;
	q->count--;
	temp = NULL;
}
void display(antrian q){
	item n;
	n = q->front;
	if(isEmpty(q)){
		cout<< "Masih kosong";
	}else{
		while(n != NULL){
              cout << "==============================="
                   << "\n >> No. Antri : [" << n->data << "]"
                   << "\n==============================="<< endl;
			n = n->next;
		}
	}
}
void pop(antrian q){
	item n;
	n = q->front;
	if(isEmpty(q)){
		cout<< "Masih kosong";
	}else{
		q->front = q->front->next;
	}
	q->count--;
}
int main(){
	int choose, p = 1;
	antrian q ;
	q = new queue();
	init(q);
	do{
		cout << "\n\n===== PROGRAM ANTRIAN C++ ====="
             << "\n==============================="
             << "\n|1. Tambah Antrian (Belakang) |"
             << "\n|2. Tambah Antrian (Depan)    |"
             << "\n|3. Panggil Antrian           |"
             << "\n|4. Lihat daftar antrian      |"
             << "\n|5. Exit                      |"
             << "\n===============================";
        cout << "\nChoose ! "; cin >> choose;
        cout << "\n\n";
        if(choose == 1){
        	insertRear(q,p);
        	p++;
			display(q);
		}else if(choose == 2){
        	insertFront(q,p);
        	p++;
			display(q);
		}else if(choose == 3){
			cout << "=================================" << endl;
            cout << "No. Antri : [" << q->front->data << "]";
            cout << "\n=================================" << endl;
			pop(q);
            cout << "Silahkan Dipanggil !" << endl;
		}else if(choose == 4){
			display(q);
		}else{
			cout << "Menu tidka di temukan";
		}
	}while(choose != 5 );
}
