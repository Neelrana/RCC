#include<conio.h>
#include<stdio.h>
struct student {
	int r_no;
	float marks;
	struct student* next;
};

struct student *insert_end(int r_no , float marks , struct student *first){
	struct student *temp;
	struct student *new = first;
	temp = (struct student*)malloc(sizeof(struct student));
	temp -> r_no = r_no;
	temp -> marks= marks;
	temp -> next = NULL;
	if(first == NULL){
		first = temp; 
	}
	else{
		while (new -> next != NULL){
			new = new -> next;
		}
		new = temp;
	}
}

void display(struct student *first){
	struct student *temp = first ;
	while(temp != NULL){
		printf("%d",temp->r_no);
		printf("%f",temp->marks)
		temp = temp -> next;
		printf("\t")
	}
}
int main(){
	struct student* first = NULL;
	struct student* temp = NULL;
	
}
