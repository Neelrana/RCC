#include<stdio.h>
void get_matrix(int mat[][10],int r,int c){
	int i=0,j=0;
	int (*cpy)[10] = mat;
	printf("Enter first matrix:\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("Enter elements a %d%d\n",i+1,j+1);
			scanf("%d",*(cpy+i)+j);
		}
	}
}

void display(int mat[][10] , int r ,int c){
	int i=0,j=0;
	int (*cpy)[10] = mat;
	printf("\n\nEntered matrix is :\n");
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			printf("%d\t",*(*(cpy+i)+j));
		}
		printf("\n");
	}
	printf("\n\n Transpose of the matrix is: \n");
	for(i=0;i<c;i++){
		for(j=0;j<r;j++){
			printf("%d\t",*(*(cpy+j)+i));
		}
		printf("\n");
	}
}
int main(){
	int mat[10][10];
	int r,c;
	printf("Enter rows you want to enter :\n");
	scanf("%d",&r);
	printf("Enter columns you want to enter: \n");
	scanf("%d",&c);
	get_matrix(mat,r,c);
	display(mat,r,c);
	return 0;
}
