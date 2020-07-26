#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	int d1,d2,m1,m2,y1,y2;
	int diff_d,diff_m,diff_y;
	printf("Enter current date: \n");
	scanf("%d %d %d" ,&d2,&m2,&y2);
	printf("Enter D.O.B \n");
	scanf("%d %d %d",&d1,&m1,&y1);
	
	if(d2<d1)
	{
		if(m2==3){
			if((y2 % 4 == 0 && y2 % 100 !=0) || y2 % 400 == 0 )
			{
				d2 += 29;
			}
			else 
			{
				d2+=28;
			}
		}
		else if(m2 == 5 || m2 == 7 || m2 == 10 || m2 == 12)
		{
			d2 += 30;
		}
		else{
			d2 += 31;
		}
		m2=m2-1;
	}
	if(m2<m1){
		m2 += 12;
		y2 -= 1;
	}
	
	diff_d=d2-d1;
	diff_m=m2-m1;
	diff_y=y2-y1;
	
	printf("%d %d %d",diff_d,diff_m,diff_y);
	getch();
}
