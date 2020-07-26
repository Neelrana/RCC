#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct football{
	int ties;
	int field_goals;
	int touch_downs;
	int turn_overs;
};

struct baseball{
	int no_of_hits;
	int runs;
	int errors;
	int extra_timing;
};

union league{
	struct football f1;
	struct baseball b1;
};

struct team {
	char t_name[30];
	char city[30];
	int no_of_wins;
	int team_code;
	union league l1;
	
};

struct team get_details(struct team t1){
	printf("Enter team name :\n");
	scanf("%s",t1.t_name);
	printf("Enter city name:\n");
	scanf("%s",t1.city);
	printf("Enter win records:\n");
	scanf("%d",&t1.no_of_wins);
	printf("Enter team code:\n");
	scanf("%d",&t1.team_code);
	if(t1.team_code==1){
		printf("Enter no of hits:\n");
		scanf("%d",&t1.l1.b1.no_of_hits);
		printf("Enter no of runs:\n");
		scanf("%d",&t1.l1.b1.runs);
		printf("Enter no of errors:\n");
		scanf("%d",&t1.l1.b1.errors);
		printf("Enter no of extra timings:\n");
		scanf("%d",&t1.l1.b1.extra_timing);
	}
	else if(t1.team_code==2){
		printf("Enter no. of ties: \n");
		scanf("%d",&t1.l1.f1.ties);
		printf("Enter no. of fiels goals:\n");
		scanf("%d",&t1.l1.f1.field_goals);
		printf("Enter no of touch downs:\n");
		scanf("%d",&t1.l1.f1.touch_downs);
		printf("Enter no. of turn overs:\n");
		scanf("%d",&t1.l1.f1.turn_overs);
	}
	else{
		printf("Enter only 1 or 2 in team_code :\n");
		exit(0);
	}
	return t1;
}

void display_data(struct team t1){
	printf("\n*****************************\n");
	printf("\nTeam name is: %s",t1.t_name);
	printf("\nCity name is: %s",t1.city);
	printf("\nNo. of wins record is : %d",t1.no_of_wins);
	if(t1.team_code==1 ){
		printf("\nNo. of hits is : %d",t1.l1.b1.no_of_hits);
		printf("\nNo. of runs are: %d",t1.l1.b1.runs);
		printf("\nNo of errors: %d",t1.l1.b1.errors);
		printf("\nNo. of extra rimings: %d",t1.l1.b1.extra_timing);
	}
	else {
		printf("\nNo. of field goal is : %d",t1.l1.f1.field_goals);
		printf("\nNo. of ties :%d",t1.l1.f1.ties);
		printf("\nNo. of touchdowns is: %d",t1.l1.f1.touch_downs);
		printf("\nNo. of turn over is : %d",t1.l1.f1.turn_overs);
	}
}

void sort(struct team t1[],int n){
	int i ,j;
	struct team temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(t1[j+1].no_of_wins>t1[j].no_of_wins){
				temp=t1[j];
				t1[j]=t1[j+1];
				t1[j+1]=temp;
			}
		}
	}
}
int main(){
	int i,n;
	struct team t1[30];
	printf("Enter no. of teams you want to enter : \n");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		t1[i]=get_details(t1[i]);
	}
	
	printf("\nDisplay Records: \n");
	for (i=0;i<n;i++){
		display_data(t1[i]);
	}
	
	sort(t1,n);
	
	printf("\n\nAfter Sorting Records are : \n");
	
	for (i=0;i<n;i++){
		display_data(t1[i]);
	}
	getch();
	
}

