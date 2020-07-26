/*2.  Write a program to create a singly linked list and display 
its elements in LIFO pattern.Also display the number of elements in the list.*/

#include<stdio.h>
#include<stdlib.h>
struct student {
	int r_no;
	float marks;
	struct student *next;
};

struct student *insert_node(struct student *first){
	struct student *temp = (struct student*)malloc(sizeof(struct student));
	printf("Enter the no of student:\n");
	scanf("%d",&temp->r_no);
	printf("Enter the marks of the student:\n");
	scanf("%f",&temp->marks);
	temp->next = NULL;
	if(first == NULL){
		first = temp ;
	}
	else{
		temp->next = first ;
		first = temp;
	}
	return first;
}

struct student* delete_first(struct student *first ){
	struct student *temp;
	if(first == NULL){
		printf("Linkedlist is empty:\n");
	}
	else{
		if(first->next == NULL){
			free(first);
			first = NULL;
			printf("Now linkedlist is empty:\n");
		}
		else{
			temp = first->next;
			free(first);
			first = temp;
			printf("Node deleted successfully:\n");
		}
		return(temp);	
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
	}
}
int main(){
	struct student *first = NULL;
	int i,n,no = 1,cnt = 0;	
		while(no != 0){
			printf("\n\n1-> Enter the linked list in LIFO paattern:\n");
			printf("2-> Display the linkedlist:\n");
			printf("3-> Delete the first node from the list:\n");
			printf("0-> Exit\n");
			printf("\nEnter the no from above:\n");
			scanf("%d",&no);
			if(no == 1){
				printf("How many nodes you want to enter:\n");
				scanf("%d",&n);
				for(i=0;i<n;i++){
					first = insert_node(first);
					cnt++;
				}
				printf("Node inserted successfully:\n");
			}
			if(no == 2){
				display(first);
				printf("Total no. of element in the list is %d ",cnt);
			}
			if(no == 3){
				first = delete_first(first);
				if(first != NULL){
					cnt--;
				}
			}
			if(no == 0){
				exit(1);
			}
		}
		
}
