/*4.  Write a program to create an ordered linked list.*/
#include<stdio.h>
#include<stdlib.h>
struct student {
	int r_no;
	float marks;
	struct student *next;
};

void insert_node(struct student **first,struct student **last){
	struct student *temp;
	struct student *p = *first;
	temp = (struct student*)malloc(sizeof(struct student));
	printf("Enter the Roll No:\n");
	scanf("%d",&temp->r_no);
	printf("Enter the marks:\n");
	scanf("%f",&temp->marks);
	temp->next=NULL;
	if(*first == NULL){
		*first = temp ;
		*last = temp;
	}
	else if(temp->r_no < (*first)->r_no){
		temp->next = *first;
		*first = temp;
		while(temp->next != NULL){
			temp = temp->next;
		}
		*last = temp;
	}
	else if(temp->r_no < (*last)->r_no){
		while(p != NULL && p->next->r_no < temp->r_no){
			p = p->next;
		}
		if(p->next != NULL){
			temp->next = p-> next;
			p->next = temp;
		}
		else{
			p->next = temp ;
		}
	}
	else if(temp->r_no > (*first)->r_no && (*last)->next == NULL){
		(*last)->next = temp ;
		(*last) = temp;
	}
}

void display(struct student *first){
	struct student *temp =first;
	if(first == NULL){
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
	int no=1;

	while(no != 0){
		printf("1-> insert the node:\n");
		printf("2-> Display");
		printf("\nEnter the no what you want to do:\n");
		scanf("%d",&no);
		if(no == 1){
			insert_node(&first,&last);
		}
		if(no == 2){
			display(first);
		}
	}
	
}
