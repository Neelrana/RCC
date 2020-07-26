#include<conio.h>
#include<stdio.h>

struct student{
	int r_no;
	char name[30];
	float marks;
};

int main()
{
	int i=0,n,high_mark,temp;
	struct student st1[30];
	printf("Enter The size you want to enter the data: \n");
	scanf("%d",&n);
//	printf("roll_no size :%d \n",sizeof(st1.r_no));
//	printf(" name size: %d \n",sizeof(st1.name));
//	printf("Marks size: %d \n",sizeof(st1.marks));
//	printf("total size: %d \n",sizeof(st1));

for(i=1;i<=n;i++){
printf("Enter roll No %d: \n",i);
scanf("%d",&st1[i].r_no);
printf("Enter Your name %d: \n",i);
scanf("%s",st1[i].name);
printf("Enter your marks %d: \n",i);
scanf("%f",&st1[i].marks);	
}
i=0;
for(i=0;i<n;i++){
printf("\n");
printf("%s\n",st1[i].name);
printf("%d\n",st1[i].r_no);
printf("%.2f",st1[i].marks);
printf("\n");
printf("\n");	
}
i=0;
high_mark=st1[i].marks;
for(i=1;i<=n;i++)
{
	if(st1[i].marks>high_mark)
	{
		high_mark=st1[i].marks;
		temp=i;
	}
}

printf("\n%s  getting highest mark is %d",st1[temp].name,high_mark);
getch();	
}
