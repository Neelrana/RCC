/*1. Write a program to create a singly linked list and display its elements in FIFO pattern. Also display the number of
elements in the list.*/

#include<stdio.h>
#include<stdlib.h>

struct student {
	int r_no;
	float marks;
	struct student *next;
};

void insert_node(struct student **first, struct student **last){
	struct student *temp = (struct student*)malloc(sizeof(struct student));
	printf("ENter the no:\n");
	scanf("%d",&temp->r_no);
	printf("Enter the marks:\n");
	scanf("%f",&temp->marks);
	temp->next = NULL;
	
	if(*first == NULL){
		*first = temp ;
		*last = temp ;
	}
	else{
		(*last)->next = temp ;
		(*last) = temp ;
	}
}

struct student* delete_first(struct student *first){
	struct student *temp;
	if(first == NULL ){
		printf("\nLinked lust is empty:\n");
	}
	else{
			if(first->next == NULL){
				free(first);
				printf("Now linkedlist is empty:\n");
			}
			temp = first->next;
			printf("2nd->%d",temp);
			free(first);
			first = temp;
			printf("\nDelete node successfully:\n");
			return(temp);
	}
}



void display(struct student *first){
	struct student *temp = first;
	if(first == NULL){
		printf("Linkedlist is empty:\n");
	}
	else{
		printf("Roll No. \t Marks \n");
		printf("=======================\n");
		while(temp != NULL){
		printf("%d\t\t",temp->r_no);
		printf("%f\n",temp->marks);
		temp = temp->next;
		}
		printf("=======================\n");
	}
}


int main(){
	struct student *first;
	struct student *last;
	int no,mark,i,n,num=1,cnt=0;
	while(num != 0){
		printf("\n1-> Create the linkedlist in FIFO pattern:\n");
		printf("2-> Display the linked list: \n");
		printf("3-> delete the first node: \n");
		printf("0-> Exit\n");
		printf("\nEnter no. from the above what you want to do:\n");
		scanf("%d",&num);
		if(num == 1){
			printf("How many nodes you want to enter:\n");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				insert_node(&first,&last);
				printf("\nNode is inserted successfully:\n");	
				cnt++;
			}
		}
		if(num == 2){
			display(first);
			printf("Total elements in the list is %d \n",cnt);
		}
		if(num == 3){
			first = delete_first(first);
			if(first != NULL){
					cnt--;
			}
		}
		if(num == 0){
			exit(1);
		}
	}	
}
