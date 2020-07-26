#include<conio.h>
#include<stdio.h>
struct cultural{
	char event_name[30];
	int medal;
}cl;
struct sports{
	char game_name[20];
	int played_game;
	int win_game;
	int loose_game;
}sp1;
struct student{
	int roll_no;
	int act_code;
	char name[30];
	union event {
		struct cultural cl;
		struct sports sp1;
	}evnt;
};

int main(){
	
	struct student s1[30];
	int i,n;
	printf("Enter how many students you want to add : \n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter activity code : \n");
		scanf("%d",&s1[i].act_code);
		printf("Enter Student roll_no:\n");
		scanf("%d",&s1[i].roll_no);
		printf("Enter Name:\n");
		scanf("%s",&s1[i].name);
		if(s1[i].act_code==1){
			printf("Enter cultural activity name:\n");
			scanf("%s",&s1[i].evnt.cl.event_name);
			printf("Enter medal no:\n");
			scanf("%d",&s1[i].evnt.cl.medal);
		}
		else{
			printf("Enter sports activity name:\n");
			scanf("%s",&s1[i].evnt.sp1.game_name);
			printf("Enter total game:\n");
			scanf("%d",&s1[i].evnt.sp1.played_game);
			printf("Enter win game:\n");
			scanf("%d",&s1[i].evnt.sp1.win_game);
			printf("Enter loose game:\n");
			scanf("%d",&s1[i].evnt.sp1.loose_game);
		}
		printf("*****************************\n");
	}
	printf("*****************************\n");
	printf("Display the details:\n");
	printf("*****************************\n");
	for (i=0;i<n;i++){
		printf("Roll_no of student %d is : %d \n",i+1,s1[i].roll_no);
		printf("Name of student %d is : %s \n",i+1,s1[i].name);
		if(s1[i].act_code==1)
		{
			printf("cultural activity name is %s:\n",s1[i].evnt.cl.event_name);
			printf("medal no is : %d\n",s1[i].evnt.cl.medal);
		}
		else
		{
				printf("sports activity name is %s:\n",s1[i].evnt.sp1.game_name);
				printf("total game played %d:\n",s1[i].evnt.sp1.played_game);
				printf("win game %d\n",s1[i].evnt.sp1.win_game);
				printf("loose game %d\n",s1[i].evnt.sp1.loose_game);
		}
		printf("*****************************\n");
	}
}
