#include<stdio.h>
#include<conio.h>

void read_data(int *iptr,int n){
	int i =0,*cpy;
	cpy = iptr;
	for(i=0 ;i<n; i++){
		printf("Enter %d element ",i+1);
		scanf("%d",cpy);
		cpy++;
	}
}

void display_data(int *iptr,int n){
		int i ;
		for(i=0;i<n;i++){
			printf("Element of %d is %d\n",i+1,*iptr);
			iptr++;
		}
}

int minimum(int *iptr , int n){
	int i,min = *iptr;
	for(i=0;i<n;i++){
		if(min > *(iptr+i) ){
			min =*(iptr+i);
		}
	}
	return min;
}

int maximum(int *iptr , int n){
	int i,max=*iptr;
	for(i=0;i<n;i++){
		if(max < *(iptr + i ) ){
			max = *(iptr + i);
		}
	}
	return max;
}

int main(){
	int *iptr,a[50],n;
	int min=0, max=0;
	iptr = a ;
	printf("Enter the no. of elements: \n");
	scanf("%d",&n);
	read_data(iptr,n);
	printf("\nEntered data is : \n\n");
	display_data(iptr,n);
	printf("\n");
	min = minimum(iptr,n);
	max = maximum(iptr,n);
	printf("Minimum element is %d \n",min);
	printf("Maximum element is %d \n",max);
}
