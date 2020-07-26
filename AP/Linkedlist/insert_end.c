#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct student {
	int r_no;
	float marks;
	struct student* next;
};

struct student *insert_end(int r_no , float marks , struct student *first){
	
	struct student *new;
	struct student *temp = (struct student*)malloc(sizeof(struct student));
	temp -> r_no = r_no;
	temp -> marks= marks;
	temp -> next = NULL;
	if(first == NULL){
		first = temp; 
	}
	else{
		new = first;
		while (new -> next != NULL){
			new = new -> next;
		}
		new -> next = temp;
	}
	return first;
}

void display(struct student *first){
	struct student *temp = first ;
	printf("The linked list is: \n\n");
	while(temp != NULL){
		printf("%d\t",temp->r_no);
		printf("%f",temp->marks);
		temp = temp -> next;
		printf("\t");
	}
	printf("\n");
}
int main(){
	int r_no,marks,n,i=0,no=1;
	struct student* first = NULL;
	struct student* temp;
	
	while(no != 0 ){
		printf("1. Insert at end \n");
		printf("2. Display Linked list \n");
		printf("0. Exit");
		printf("\nEnter no. what you want to do from the above:\n");
		scanf("%d",&no);
		
		if(no == 0 ){
			exit(1);
		}
		else if(no == 1){
			printf("How many nodes you want to enter :\n");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				printf("ENter the roll no:\n");
				scanf("%d",&r_no);
				printf("ENter the marks:\n");
				scanf("%d",&marks);
				first = insert_end(r_no,marks,first);
				temp = first;
				printf("\n");
			}
		}
		else if(no == 2){
			display(temp);
			printf("\n");
		}		
	}
}
