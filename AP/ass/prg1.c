#include<stdio.h>
#include<conio.h>
#include<string.h>
//int num;
struct player {
	char p_name[30];
	int b_avg;
};

struct team{
	char t_name[30];
	struct player p1[11];
};

struct team get_data(struct team t1 ){
	int i,num;
	printf("\n\nEnter Team name :\n");
	scanf("%s",&t1.t_name);
	printf("\nEnter How many players you want to add:\n");
	scanf("%d",&num);
	for(i=0;i<num;i++){
		printf("Enter player name:\n");
		scanf("%s",&t1.p1[i].p_name);
		printf("Enter Batting average :\n");
		scanf("%d",&t1.p1[i].b_avg);	
	}
	
	t1.p1[i].b_avg = '\0';
	t1.p1[i].p_name == '\0';
	
	return t1;
}

struct team display_data(struct team t1){
	int j=0 ;
	printf("\n************************************\n");
	printf("Team Name is : %s \n",t1.t_name);
	printf("************************************\n");
	while(t1.p1[j].p_name != '\0' && t1.p1[j].b_avg != '\0' ){
		printf("player name is: %s\n",t1.p1[j].p_name);
		printf("The batting average is : %d\n" ,t1.p1[j].b_avg);
		j++;
	}
}

void sort(struct team t1[], int n){
	int i,j,k=0,avg=0;
	struct team temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(strcmp(t1[j].t_name,t1[j+1].t_name)>0){
			 	temp=t1[j];
			 	t1[j]=t1[j+1];
			 	t1[j+1]=temp;
			}
		}
	}
}


int main(){
	int i , n;
	struct team t1[100];
	printf("Enter How Many teams you want to enter :\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		t1[i]=get_data(t1[i]);
	}
	
	for(i=0;i<n;i++){
		//count-=1;
		display_data(t1[i]);
	}
	
	sort(t1,n);
	
	printf("\n ******* After sorting: *******\n");
	for(i=0;i<n;i++){
		display_data(t1[i]);
	}
	
}
