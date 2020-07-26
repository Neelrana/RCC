#include<conio.h>
#include<stdio.h>
#include<string.h>
struct player{
	char player_name[20];
	char team_name[20];
	float average;
};

struct player get_data(struct player p1){
	printf("Enter Player name: \n");
	scanf("%s",p1.player_name);
	printf("Enter Team Name: \n");
	scanf("%s",p1.team_name);
	printf("Enter batting average :\n");
	scanf("%f",&p1.average);
	
	return p1;
}

struct player display_data(struct player p1){
	//printf("%s \n %s  \n %f\n",p1.player_name,p1.team_name,p1.average);
	printf("The player name is : %s\n",p1.player_name );
	printf("The team name is : %s\n",p1.team_name);
	printf("Batting average is : %f\n",p1.average);
	return p1;
}

void sort (struct player p1[],int n){
	int i,j;
	struct player temp;
	for (i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(strcmp(p1[j].team_name,p1[j+1].team_name)>0){
				temp=p1[j];
				p1[j]=p1[j+1];
				p1[j+1]=temp;
			}
		}
	}
}

void search(struct player p1[],int n){
	char p_name[20];
	int i,found=0;
	printf("Enter player you want to display records: \n");
	scanf("%s",p_name);
	for(i=0;i<n;i++){
		if(strcmp(p1[i].player_name,p_name)==0){
			display_data(p1[i]);
			found=1;
		}
	} 
		if(found==0){
			printf("NO data found:\n");
		}
}
int main(){
	int i,n ;
	struct player p1[20];
	printf("Enter No. of students you want to enter :\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		p1[i]=get_data(p1[i]);
	}
	
	for(i=0;i<n;i++){
		display_data(p1[i]);
	}
	
	printf("\nTeam wise sorting :\n");
	
	sort(p1,n);
	
	for(i=0;i<n;i++){
		display_data(p1[i]);
	}
	
	search(p1,n);
	getch();
}
