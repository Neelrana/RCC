#include<stdio.h>
#include<stdlib.h>

struct student{
	int r_no;
	float marks;
	struct student* next;
};

void insert_beg(struct student **first, struct student **last){
	struct student *temp;
	temp = (struct student*)malloc(sizeof(struct student));
	printf("Enter the Roll No:\n");
	scanf("%d",&temp->r_no);
	printf("Enter the Marks:\n");
	scanf("%f",&temp->marks);
	temp->next = NULL;
	if(*first == NULL){
		*first=temp;
		*last=temp;	
	}
	else{
		temp->next=*first;
		*first = temp ;
	}
	printf("\nNode inserted successfully\n");
}

void insert_between(struct student **first, struct student **last){
	struct student *previous = NULL;
	struct student *p =NULL;
	struct student *temp;
	temp = (struct student*)malloc(sizeof(struct student));
	printf("Enter the Roll No:\n");
	scanf("%d",&temp->r_no);
	printf("Enter the Marks:\n");
	scanf("%f",&temp->marks);
	temp->next = NULL;
	if(*first == NULL){
		*first = temp ;
		*last = temp ;
		printf("\nFirst node inserted successfully:\n");
	}
	// newnode inserted before first node:
	
	else if(temp->r_no < (*first)->r_no){
		temp->next=(*first);
		*first = temp;
		printf("\nNode inserted successfuly:\n");
	}
	
	else if(temp->r_no > (*first)->r_no){
		previous = (*first);
		while(temp->r_no > previous->r_no && previous->next != NULL){
			p = previous;
			previous = previous->next;
		}
		
		//node insert at the end
		if(temp->r_no > previous->r_no){
			previous -> next = temp;
			*last = temp;
		}
		
		//node insert after the first node
		else if(previous->next == NULL){
			temp->next = p->next;
			p->next = temp;
			*last = temp;
		}
		
		//node insert between two node
		else{
			p->next=temp;
			temp->next=previous;
		}
	}
}

void insert_end(struct student **first, struct student **last){
	struct student *temp= NULL;
	temp = (struct student*)malloc(sizeof(struct student));
	printf("Enter the Roll No:\n");
	scanf("%d",&temp->r_no);
	printf("Enter the Marks:\n");
	scanf("%f",&temp->marks);
	temp->next = NULL;
	if(*first != NULL){
		(*last)->next=temp;
		(*last)=temp;
	}
	else{
		*first = temp;
		*last = temp;
	}
	printf("Node inserted successfully\n");
}

void display(struct student *first){
	struct student *temp;
	temp = first;
	printf("Linked list is:\n\n");
	printf("R_no \t Marks \n");
	while(temp != NULL){
		printf("%d\t",temp->r_no);
		printf("%f\n",temp->marks);
		temp= temp -> next;
	}
}
int main(){
	int no=1;
	struct student *first = NULL;
	struct student *last = NULL;
	while(no != 0){
		printf("\n\n1.Insert at the Begin:\n");
		printf("2.Insert at middle the linkedlist :\n");
		printf("3.Insert at the end of the list :\n");
		printf("4.Display the linked list:\n");
		printf("0.Exit\n");
		printf("\nEnter the No What you want to do from the above:\n");
		scanf("%d",&no);
		
		if(no == 1 ){
			insert_beg(&first,&last);
		}
		if(no == 2){
			insert_between(&first,&last);
		}
		if(no == 3){
			insert_end(&first,&last);
		}
		if(no==4){
			display(first);
		}
		if(no == 0){
			exit(1);
		}
	}
}
