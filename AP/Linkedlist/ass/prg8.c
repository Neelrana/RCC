//Write a program to swap two consecutive elements of the given linked list.  ( Swap only values ) 
#include<stdio.h>
#include<stdlib.h>
struct student {
	int r_no;
	float marks;
	struct student *next;
};


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


void insert(struct student **first,struct student **last){
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


void pairswap(struct student *first){
	struct student *temp = first;
	float swp_m; // temporary var.
	int swp_r;
	while(temp != NULL && temp->next != NULL){
		swp_r = temp->r_no;
		swp_m = temp->marks;
		temp->marks=temp->next->marks;
		temp->r_no= temp->next->r_no;
		temp->next->marks = swp_m;
		temp->next->r_no = swp_r;
		temp = temp->next->next; 
	}
	printf("\nNode swapping succesfully:\n");
}
int main(){
	struct student *first;
	struct student *last;
	int no=1,n,i,num;
	while(no != 0){
		printf("\n1-> Insert the list:\n");
		printf("2-> swap the marks of the list:\n");
		printf("3-> Display the list before swaping the marks:\n");
		printf("4-> Display the list after swaping the marks:\n");
		printf("5-> Exit\n");
		printf("\nEnter the No. What you want to do from above:\n");
		scanf("%d",&no);
		if(no == 0){
			exit(1);
		}
		if(no == 1 ){
			printf("ENter how many nodes you want to enter :\n");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				insert(&first,&last);
			}
		}
		if(no == 2){
			printf("Enter no that you want to swap that node with its next one:\n");
			scanf("%d",&num);
		 	first = swap(first,num);
		}
		if(no == 3){
			printf("Before swaping the marks of two consicutive nodes :");
			display(first);
		}
		if(no == 4){
			printf("After swaping the marks of two consicutive nodes :");
			display(first);
		}
	}
}
