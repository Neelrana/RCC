//10. Write a C program to split a given linked list into two.
#include<stdio.h>
#include<stdlib.h>
struct student {
	int r_no;
	float marks;
	struct student *next;
};


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

struct student* reverse(struct student *first){
	struct student *temp = first;
	struct student *t1 = NULL;
	struct student *t2 = NULL;
	while(temp != NULL){
		t2 = temp->next;
		temp->next = t1;
		t1 = temp;
		temp = t2;
	}	
	return(t1);
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
	struct student *first = NULL;
	struct student *last = NULL;
	int no=1,n,i;
	while(no != 0){
		printf("\n1-> Insert the list:\n");
		printf("2-> Reverse the linked list\n");
		printf("3-> Display the linked list Before reverse:\n");
		printf("4-> Display the linked list After reversed:\n");
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
		 	first = reverse(first);
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
