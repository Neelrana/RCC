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

struct student *split(struct student *first, int r_no){
	struct student *temp = first;
	struct student *prev = NULL;
	struct student *curr = NULL;
	struct student *new_list = NULL;
	while(temp != NULL && temp->r_no != r_no){
		prev = temp;
		temp = temp->next;
	}
	if(prev != NULL){
		new_list = temp ;
		prev->next = NULL;
	}
	return new_list;
}
int main(){
	struct student *first = NULL;
	struct student *last = NULL;
	struct student *second= NULL;
	int no=1,n,i,num;
	while(no != 0){
		printf("\n1-> Insert the list:\n");
		printf("2-> Split the linked list\n");
		printf("3-> Display the first linked list:\n");
		printf("4-> Display the second linked list:\n");
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
			printf("Enter no that you want to split the node:\n");
			scanf("%d",&num);
		 	second = split(first,num);
		}
		if(no == 3){
			printf("first linked list :");
			display(first);
		}
		if(no == 4){
			printf("second linked list :");
			display(second);
		}
	}
}
