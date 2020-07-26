/*Write a menu driven program to create a singly linked list and perform  following operations on it:
	a. Insert an element 
	b. Delete an element
	c. Display the list*/
	
#include<stdio.h>
#include<stdlib.h>
struct student{
	int r_no;
	float marks;
	struct student *next;
};

void insert_node(struct student **first,struct student **last){
	struct student *temp;
	temp = (struct student*)malloc(sizeof(struct student));
	printf("Enter the roll no:\n");
	scanf("%d",&temp->r_no);
	printf("Enter the marks:\n");
	scanf("%f",&temp->marks);
	temp->next = NULL;
	if(*first == NULL){
		*first = temp;
		*last = temp;
	}
	else{
		(*last)->next = temp;
		(*last) = temp ;
	}
}

struct student *delete_node(struct student *first,int no){
	struct student *temp;
	struct student *p = first ;
	if(first == NULL){
		printf("Linkedlist is empty:\n");
	}
	else if(first->r_no == no) // deleted node is first node
	{
		temp = first;
		first = first->next;
		free(temp);
		printf("\nFirst node is deleted successfully:\n");
	}
	else{
		while(p != NULL && p->next->r_no == no ){
			p = p->next;
		}
		if(p->next != NULL){
			p->next = temp->next;
			free(temp);
			printf("\nNode deleted successfully:\n");
		}
		else{
			printf("\nRecord is not in the list:\n");
		}
	}
	return first;
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
	struct student *first;
	struct student *last;
	int no=1,n,i,num =0 ;
	while(no != 0){
		printf("\n1-> Insert the linkedlist:\n");
		printf("2-> Delete the node:\n");
		printf("3-> Display the linked list:\n");
		printf("0-> Exit:\n");
		printf("\nEnter the no what you want to do from above:\n");
		scanf("%d",&no);
		if(no == 0){
			exit(1);
		}
		if(no == 1){
			printf("How many nodes you want to enter:\n");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				insert_node(&first,&last);
			}
		}
		if(no == 2){
			printf("Enter the Roll no which node you want to delete\n");
			scanf("%d",&num);
			first = delete_node(first,num);
		}
		if(no == 3){
			display(first);
		}
	}
}
