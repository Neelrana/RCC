//6). Write a program to calculate the summation of all elements of the linked list.
#include<stdio.h>
#include<stdlib.h>
struct student{
	int r_no;
	float marks;
	struct student *next;
};

void insert_node(struct student **first,struct student **last){
	struct student *temp = (struct student *)malloc(sizeof(struct student));
	struct student *p;
	printf("Enter the Roll No.\n");
	scanf("%d",&temp->r_no);
	printf("Enter the marks:\n");
	scanf("%f",&temp->marks);
	temp->next=NULL;
		if(*first == NULL){
			*first = temp ;
			*last = temp;
		}
		else{
			(*last)->next = temp ;
			*last = temp ;
		}
}

void total_marks(struct student *first){
	int total = 0 ;
	struct student *temp = first;
	while(temp != NULL){
		total = total + temp->marks;
		temp = temp->next;
	}
	printf("The total marks of the list is:%d \n",total);
}

void display(struct student *first){
	struct student *temp =first;
	if(first ==  NULL){
		printf("Linkedlist is empty:\n\n");
	}
	else{
		printf("\n========================\n");
		printf("NO \t\t Marks:\n");
		printf("========================\n");
		while(temp != NULL){
			printf("%d\t\t",temp->r_no);
			printf("%f\n",temp->marks);
			temp = temp->next;	
		}
		printf("========================\n");
	}
}

int main(){
	struct student *first=NULL;
	struct student *last=NULL;
	int n,i,no=1;
	while(no != 0)
	{
		printf("\n1-> Inserting the list\n");
		printf("2-> Sum of all marks in the list\n");
		printf("3-> Display\n");
		printf("0->Exit\n");
		printf("\nEnter the no what you want to do from above:\n");
		scanf("%d",&no);
		if(no == 1){
			printf("How many nodes you want to enter:\n");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				insert_node(&first,&last);
			}
		}
		if(no == 2){
			total_marks(first);
		}
		if(no == 3){
			display(first);
		}
		if(no == 0){
			exit(1);
		}
	}
}
