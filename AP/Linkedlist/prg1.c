#include<stdio.h>
#include<stdlib.h>


struct student{
	int no;
	float marks;
	struct student* next;
};

struct student* insert(int no,float marks,struct student* first){
	struct student* temp = (struct student*) malloc(sizeof(struct student));
	temp->no=no;
	temp->marks=marks;
	temp->next=first;
	first = temp ;
	return first;
}

void display(struct student* first){
	struct student* temp = first;
	printf("\nThe linkedlist is:\n");
	while(temp != NULL){
		printf(" %d",temp->no);
		printf("  ");
		printf(" %.2f",temp->marks);
		printf("\t");
		temp= temp->next;
	}
	printf("\n");
}
	
int main(){
	struct student* first = NULL;
	struct student* temp = NULL;
	int i=1,n=1;
	int no,marks;
	while (n!= 0 ){
		printf("\n 1. insert node:");
		printf("\n 2. Display the linked list :");
		printf("\n 0. exit");
		printf("\nEnter the no you want to do from above :\n");
		scanf("%d",&n);
		if(n!=1 || n!=2 || n!=0){
			printf("\nEnter proper no.:\n");
		}
		else if(n == 1){
			printf("Enter the no of student %d\n",i);
			scanf("%d",&no);
			printf("Enter the marks of student %d\n",i);
			scanf("%d",&marks);
			first = insert(no,marks,first);
		}
		else if(n==2){
			display(first);
		}
		else{
			exit(0);
		}
		i++;
	}
}
