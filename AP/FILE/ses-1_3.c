#include<stdio.h>
enum day{sunday = 1 ,monday,tuesday=5,wednesday,thursday=10,friday,saturday};

int main(){
	printf("%d \t %d \t %d \t %d \t %d \t %d \t %d \t",sunday,monday,tuesday,wednesday,thursday,friday,saturday);
	return 0 ;
}

//Output is 

//1        2       5       6       10      11      12
