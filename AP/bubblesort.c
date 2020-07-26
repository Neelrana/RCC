#include<stdio.h>
struct student
{
	int no;
	char nm[100];
};
struct student getdata(struct student s)
{
		printf("\n Enter rollno:");
		scanf("%d",&s.no);
		printf("\n Enter Name:");
		scanf(" %s",s.nm);
		return s;
}
struct student displaydata(struct student s)
{
	printf("\n rollno:%d",s.no);
	printf("\n Name:%s",s.nm);
}
void sort(struct student s[],int n)
{
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(s[j].no>s[j+1].no)
			{
				 temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
			}
		}
	}
}
void main()
{
	struct student s[100];
	/*struct student s1 = "";*/
	int n,i,j;
	printf("\n Enter no of student:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		s[i]=getdata(s[i]);
	for(i=0;i<n;i++)
		displaydata(s[i]);
	
	sort(s,n);

	for(i=0;i<n;i++)
		displaydata(s[i]);
		
}