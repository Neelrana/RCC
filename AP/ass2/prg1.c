#include<stdio.h>
#include<conio.h>

int read_data(int *iptr,int n){
	int i =0;
	for(i=0 ;i<n; i++){
		printf("Enter %d element ",i+1);
		scanf("%d",iptr);
		iptr++;
	}
	return iptr;
}

void display_data(int *iptr,int n){
		int i ;
		iptr--;
		for(i=0;i<n;i++){
			printf("\nElement of %d is %d",i+1,*iptr);
			iptr--;
		}
}

int main(){
	int *iptr,a[50],n;
	iptr = a ;
	printf("Enter the no. of elements: \n");
	scanf("%d",&n);
	iptr = read_data(iptr,n);
	display_data(iptr,n);
	
}
