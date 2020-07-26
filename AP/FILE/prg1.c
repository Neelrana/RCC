#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	
	FILE *fptr;
	int num;
	char name[20];
	int n =0 , i= 0;
	printf("How many records do you want to enter in the file: \n");
	scanf("%d",&n);
	//fptr = fopen("Student.txt","w+"); // if file is not created w+ it creates the file and write in the file
	fptr = fopen("Student.txt","w+"); // it opens the file and append the file.

		for (i=0;i<n;i++){
			if(fptr == NULL){
				printf("Error\n");
				exit(1);		
			}
			printf("Enter the num\n");
			scanf("%d",&num);
	
			printf("Enter the name :\n");
			fflush(stdin);
			scanf("%s",name);
	
			fprintf(fptr,"%3d",num);
			fprintf(fptr,"%16s",name);
			printf("Record entered successfully\n");
			fseek(fptr, 0, SEEK_END); 
		}	
	fclose(fptr);
	
	
	fptr = fopen("Student.txt","r");
	printf("\n\nThe data in the file is:\n");
	while(!feof(fptr)){
		fscanf(fptr,"%3d",&num);
		fscanf(fptr,"%16s",&name);
		printf("%d\t",num);
		printf("%s\n",name);
	}
	fclose(fptr);
	
	return 0;
}


