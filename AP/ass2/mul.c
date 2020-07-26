#include<stdio.h>
int get_row(){
	int r;
	printf("Enter Rows:\n");
	scanf("%d",&r);
	return r;
}


int get_col(){
	int c;
	printf("Enter columns:\n");
	scanf("%d",&c);
	return c;
}

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
}
void multiply(int mat[][10] , int mat2[][10],int mat3[][10] , int r,int c,int r1, int c1){
	int i , j, k ,sum;
	int (*ptr1)[10]=mat;
	int (*ptr2)[10]=mat2;
	int (*ptr3)[10]=mat3;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			sum =0 ;
			for(k=0;k<c;k++){
				sum += (*(*ptr1+i)+k) + (*(*ptr1+k)+j) ;
			}
			(*(*(ptr3+i)+j))==sum;
		}
	}
}

int main(){
	int mat[10][10];
	int mat2[10][10];
	int mat3[10][10];
	int r,c,r1,c1;
	if(r != r1 && c != c1){
		printf("Enter only square matrix :");
	}
	else {
		r=get_row();
		c=get_col();
		get_matrix(mat,r,c);
		r1= get_row();
		c1= get_col();
		get_matrix(mat2,r1,c1);
		display(mat,r,c);
		display(mat2,r1,c1);
		multiply(mat,mat2,mat3,r,c,r1,c1);
		display(mat3,r,c);	
	}
	
	
	return 0;
}
