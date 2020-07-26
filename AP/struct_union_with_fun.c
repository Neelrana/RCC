#include<stdio.h>
#include<conio.h>
struct culture
{
	char cul[40];
};

struct sports
{
	char sname[40];
	int tot_match;
	int won;
	int lose;
};

union activity
{
	struct culture c;
	struct sports s;
};
struct student
{
	int rollno,act_code;
	char name[40];
	union activity act;
};

struct student getdata(struct student s1)
{
	printf("Enter RollNo. :");
	scanf("%d",&s1.rollno);
	printf("Enter Name :");
	scanf("%s",&s1.name);
	printf("Enter Activity Code :");
	scanf("%d",&s1.act_code);
	if(s1.act_code == 1)
	{
		printf("Enter Cultural Activity Name :");
		scanf("%s",&s1.act.c.cul);
	}
	else if(s1.act_code == 2)
	{
		printf("Enter Sports Name :");
		scanf("%s",&s1.act.s.sname);
		printf("Enter Total Match :");
		scanf("%d",&s1.act.s.tot_match);
		printf("Enter Won Matchs :");
		scanf("%d",&s1.act.s.won);
		printf("Enter lose Matchs :");
		scanf("%d",&s1.act.s.lose);

	}
	/*else
	{
		printf("Enter Valid Activity Code..");
	}*/
	return s1;
}

struct student disp_data(struct student sp)
{
    printf("\n========================================\n");
    printf("****** Display Details ******");
    printf("\n========================================\n");
	printf("\nRoll No. = %d\n",sp.rollno);	
	printf("Name = %s\n",sp.name);
	if(sp.act_code == 1)
	{
		printf("Culture Activity Name = %s\n",sp.act.c.cul);
	}
	else if(sp.act_code == 2)
	{
		printf("Sports Name = %s",sp.act.s.sname);
		printf("\nTotal Matches = %d",sp.act.s.tot_match);
		printf("\nWon Matches = %d",sp.act.s.won);
		printf("\nLose Matches = %d",sp.act.s.lose);
	}
	else
	{
		printf("Enter Valid Activity Code...");
	}
	return sp;
}

void main()
{
    int i,n;
    struct student sp[10];
    printf("Enter How Many Students Detail's You Want :");
    scanf("%d",&n);
	for(i=0;i<n;i++)
    {
         sp[i]=getdata(sp[i]);
    }
    for(i=0;i<n;i++)
    {
	    disp_data(sp[i]);
    }
}
