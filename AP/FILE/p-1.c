#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	FILE *fp;
	char name[100];
	char ch;
	int a  =0 ;
	
	printf("Enter the line:\n");
	gets(name);
	
	fp = fopen("p-1.txt","w+");
	if (fp == NULL){
		printf("File does not exist:\n");
	}
	fprintf(fp,"%s",name);
	printf("Record inserted successfully:\n");
	fclose(fp);
	
	printf("\n\nRead alternate character from the file:\n");
	fp = fopen("p-1.txt","r");
	if(fp == NULL){
		printf("File not opened successfully:\n");
	}
 	ch=fgetc(fp);
    while(ch!=EOF)
    {
    	if(a==0)
        {
            printf("%c ",ch);
            a=1;
        }
        else
            a=0;
        ch=fgetc(fp);
    }
    fclose(fp);
}
