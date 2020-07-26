#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct student {
	int r_no;
	float marks;
	struct student* next;
};

void insert_end(struct student **first,struct student **last)
{
//	struct student *new;
	struct student *temp = (struct student*)malloc(sizeof(struct student));
	printf("ENter the roll no:\n");
	scanf("%d",&temp->r_no);
	printf("ENter the marks:\n");
	scanf("%f",&temp->marks);
	temp -> next = NULL;
	if(*first == NULL){
		*first = temp; 
		*last = temp;
	}
	else{
		(*last) -> next = temp;
		(*last) = temp;
	}
	//return *first;
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
	struct student* last = NULL;
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
				insert_end(&first,&last);
				printf("\n");
			}
		}
		else if(no == 2){
			display(first);
			printf("\n");
		}		
	}
}
