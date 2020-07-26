#include<conio.h>
#include<stdio.h>
struct student {

	int roll_no;
	char name[20];
	float marks;

};

int main(){
	int i,n;
	struct student s1[3]={{1,"Neel"},{2,"Sanjana"}};
	//get_details(s1,n);
//	printf("Enter N:\n");
//	scanf("%d",&n);
	for(i=0;i<3;i++){
	printf("%d\n",s1[i].roll_no);	
	printf("%s\n",s1[i].name);
	printf("%f\n\n",s1[i].marks);
	}
	getch();
}
