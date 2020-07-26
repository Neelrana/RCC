#include<stdio.h>
#include<stdlib.h>
struct student {
	int r_no;
	float marks;
	struct student *next;
};

struct student *insert(struct student *first,int r_no,float mark){
	struct student *temp = (struct student*)malloc(sizeof(struct student));
	temp->r_no = r_no;
	temp->marks=mark;
	temp->next = first;
	return temp;
}

struct student *delete (struct student *first, int no){
	struct student *p;
	struct student *temp;
	if(first == NULL){
		printf("\nLinked list is empty: \n");
	}
	else if(first->r_no == no) // deleted node is first node
	{
		temp = first;
		first = first->next;
		free(temp);
		printf("\nFirst node is deleted successfully:\n");
	}
	// if deleted node is not the first node 
	else{
		p =first;
		while(p->next != NULL && p->next->r_no != no) // check when not found the node which u want to delete
		{
			p = p->next;
		}
		if(p->next != NULL){
			temp = p->next;
			p->next = temp->next;
			free(temp);
			printf("\nNode is deleted successfully:\n");
		}
		else	// if p points to the last node than
		{
			printf("Record is not in the list:\n");
		}
	}
	return first ;
}
void display(struct student *first){
	struct student *temp = first;\
	printf("The linkedlist is:\n");
	printf("=======================\n");
	printf("\nr_no \t Marks\n");
	printf("=======================\n");
	while(temp != NULL){
		printf("%d\t",temp->r_no);
		printf("%f\n",temp->marks);
		temp = temp->next;
	}
	printf("\n");
	printf("=======================\n");
}

struct student* search_node(struct student *first, int no){
	struct student *p = first;
	int found = 0;
	if(first == NULL){
		printf("\nLinked list is empty:\n");
	}
	while(p->next != NULL){
		if(p->r_no == no){
			found = 1;
			break;
		}
		p = p->next;
	}
	if( found == 1){
		printf("Node is present in the list :\n");
	}	
	return found;
}
int main(){
	struct student *first = NULL;
	struct student *temp = NULL;
	int n,i,r_no,no,ch=1,found;
	float mark;
	printf("\nCreate the linked list:\n");
	printf("Enter how many nodes you want to enter :\n");
			scanf("%d",&n);
			for(i=0;i<n;i++){
				printf("Enter the roll No.\n");
				scanf("%d",&r_no);
				printf("Enter the marks:\n");
				scanf("%f",&mark);
				first = insert(first,r_no,mark);
			}
	
	while(ch != 0){
		printf("\n1-> Delete the node:\n");
		printf("\n2-> Display the list\n");
		printf("\n0-> Exit:\n\n");
		
		printf("\nEnter the character from above:\n");
		scanf("%d",&ch);
			if(ch == 1){
			printf("Enter the Roll no that you want to search:\n");
			scanf("%d",&no);
			found = search_node(first,no);
			if (found == 0){
				printf("Node is not present \n");
				exit(0);
			}
			else{
				first = delete(first,no);
			}
			
			}
			if(ch == 2){
				display(first);
			}
			if(ch == 0){
				exit(0);
			}	
			else{
				printf("Enter proper no:\n");
			}
	}		
}
