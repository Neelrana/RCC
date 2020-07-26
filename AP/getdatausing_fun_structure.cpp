//Age calculate using structure 

#include<conio.h>
#include<stdio.h>
struct date{
	int dd,mm,yy;
};
struct student {
	int roll_no;
	char name[20];
	struct date dob;
};

struct student get_details(){
	struct student st1;
	printf("Enter student RollNo:\n");
	scanf("%d",&st1.roll_no);
	printf("Enter student name : \n");
	scanf("%s",st1.name);
	printf("Enter date of Birth: \n");
	scanf("%d %d %d" ,& st1.dob.dd,&st1.dob.mm,&st1.dob.yy);	
	return st1;
}

int display(struct student s1){
	printf("\nDisplaying student information : \n");
	printf("%d\n",s1.roll_no);
	printf("%s\n",s1.name);
	printf("Date : %d\n",s1.dob.dd);
	printf("Month: %d\n",s1.dob.mm);
	printf("Year : %d\n",s1.dob.yy);
	printf("\n\n");
}

int main(){
	int c_d,c_m,c_y,d_y,d_m;
	struct student st1;
	st1=get_details();
	display(st1);
	printf("Enter Current date : \n");
	scanf("%d %d %d",&c_d,&c_m,&c_y);
	
	d_y=c_y - st1.dob.yy;
	d_m=c_m-st1.dob.mm;
	if(st1.dob.yy<c_y){
		d_y--;
	}
	
	if(d_m < 0 )
	{
		d_m= -d_m;
	}
	
	printf("\n%d Years ",d_y);
	printf("%d month",d_m);
	getch();
}
