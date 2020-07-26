#include<stdio.h>
union test{
	int x,y; 
};

int main(){
	union test t;
	t.x = 2 ;
	printf("After making x =2 : \n x = %d , y = %d \n\n",t.x,t.y);
	
	t.y = 10 ;
	printf("After making y = 10  : \n x = %d , y = %d \n\n",t.x,t.y);
}
/* Output is  

After making x =2 :
 x = 2 , y = 2

After making y = 10  :
 x = 10 , y = 10
 
 */


