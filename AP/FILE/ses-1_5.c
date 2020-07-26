#include<stdio.h>
void fun(int *x){
	int q = 10 ;
//	printf("%d\n",&q);
	x =&q;
//	printf("%d\n",*x);
}
int main(){
	int r = 20 ;
	int *p = &r ;
//	printf("%d\n",&r);
	fun(p);
//	printf("%d\n",p);
	printf("%d",*p);
	return 0;
}

//op is 20 
