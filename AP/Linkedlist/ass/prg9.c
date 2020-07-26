//Write a program to swap two consecutive elements of the given linked list.  ( Swap only addresses ) 
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

struct student* swap(struct student *first, int r1, int r2) 
{ 

	struct student *temp = NULL;
	struct student *prevX = NULL;
	struct student *X = first;
	struct student *prevY = NULL;
	struct student *Y = first;
   // Nothing to do if x and y are same 
   if (r1 == r2) 
   return(first); 
  
   // Search for x (keep track of prevX and CurrX 
    
   while (X && X->r_no != r1) 
   { 
       prevX = X; 
       X = X->next; 
   } 
  
   // Search for y (keep track of prevY and CurrY 
   while (Y && Y->r_no != r2) 
   { 
       prevY = Y; 
       Y = Y->next; 
   } 
  
   // If either x or y is not present, nothing to do 
   if (X == NULL || Y == NULL) 
       return(first); 
  
   // If x is not head of linked list 
   if (prevX != NULL) 
       prevX->next = Y; 
   else // Else make y as new head 
       first = Y;   
  
   // If y is not head of linked list 
   if (prevY != NULL) 
       prevY->next = X; 
   else  // Else make x as new head 
       first = X; 
  
   // Swap next pointers 
   temp = Y->next; 
   Y->next = X->next; 
   X->next  = temp; 
   
   return(first);
} 


int main(){
	struct student *first;
	struct student *last;
	int no=1,n,i,r1=0,r2=0;
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
			printf("Enter the Roll no 1:\n");
			scanf("%d",&r1);
			printf("Enter the Roll no 2:\n");
			scanf("%d",&r2);
		 	first = swap(first,r1,r2);
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
