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

void append(struct student *last,struct student *head){
	if(head != NULL){
		last->next = head;
		printf("Node appended successfully:\n");
	}
	else{
		printf("Second list is empty:");
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

int main(){
	struct student *first=NULL;
	struct student *last=NULL;
	struct student *head=NULL;
	struct student *end=NULL;
	int n,i,no=1;
	while(no != 0)
	{
		printf("\n1-> Inserting the first list\n");
		printf("2-> Inserting the second list\n");
		printf("3-> Display the first list\n");
		printf("4-> Display the second list\n");
		printf("4-> append the second list after first\n");
		printf("6-> Display the appended list\n");
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
			printf("How many nodes you want to enter:\n");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				insert_node(&head,&end);
			}
		}
		if(no == 3){
			display(first);
		}
		if(no == 4){
			display(head);
		}
		if(no == 5){
			append(last,head);
		}
		if(no == 6){
			display(first);
		}
		if(no == 0){
			exit(1);
		}
	}
}
