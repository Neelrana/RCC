#include<stdio.h>
#include<conio.h>
struct date {
	int dd,mm,yy;
};
struct student{
	int r_no;
	char name[20];
	struct date dob;
};

int get_details(struct student s1 [],int n){
	int i;
	for(i=0;i<n;i++){
		printf("\nEnter details of %d student\n",i+1);
		printf("Enter roll_no\n");
		scanf("%d",&s1[i].r_no);
		printf("Enter Name \n");
		scanf("%s",s1[i].name);
		printf("Enter Date of birth : \n");
		scanf("%d",&s1[i].dob.dd);
		scanf("%d",&s1[i].dob.mm);
		scanf("%d",&s1[i].dob.yy); 
	}
}

int process(struct student s1[],int n,struct date cdate){
	int i,d_yy,d_mm;
	for(i=0;i<n;i++)
	{
		printf(" \n\n%d student details : \n",i+1);
		printf("Roll_no:%d\n",s1[i].r_no);
		printf("%s\n",s1[i].name);
		printf("%d %d %d\n",s1[i].dob.dd,s1[i].dob.mm,s1[i].dob.yy);
		d_yy=s1[i].dob.yy-cdate.yy;
		d_mm=s1[i].dob.mm-cdate.mm;
		if(cdate.mm<s1[i].dob.mm){
			d_yy=d_yy-1;
		}
		printf("%d years %d months" ,d_yy,-d_mm);
	}
}

int main()
{
	int n;
	struct student s1[20];
	struct date cdate;
	printf("Enter No of students : \n");
	scanf("%d",&n);
	get_details(s1,n);
	printf("Enter current date: \n");
	scanf("%d %d %d",&cdate.dd,&cdate.mm,&cdate.yy);
	process(s1,n,cdate);
}
