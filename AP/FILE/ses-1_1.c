#include<stdio.h>

#define R 10 
#define C 20 

int main(){
	int(*p)[R][C];
	printf("%d",sizeof(*p));
	getchar();
	return 0;
}


//Output is 800
//because of size of int pointer is 4 and it multiply with (10)(20) = (200)
