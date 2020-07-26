#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};

struct node* first= NULL;
void insert(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp -> data=x;
	temp -> next =first;
	first=temp;
}

void print(){
	struct node* temp = first;
	printf("The list is:\n");
	while(temp != NULL){
		printf(" %d",temp->data);
		temp = temp -> next;
	}
	printf("\n");
}

int main(){
	int n, i ,x;
	struct node* temp = NULL;
	printf("Enter no. you want to add records:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the number \n");
		scanf("%d",&x);
		insert(x);
		print();
	}
}
