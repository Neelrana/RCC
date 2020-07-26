#include<stdio.h>
#include<string.h>
int main(){
	char ch[50];
	int i=0,vow=0,con=0,num=0,w_s=0;
	printf("Enter the string :\n");
	gets(ch);
	strcpy(ch,strlwr(ch));
	while(ch[i]!='\0'){
		if(ch[i]>48 && ch[i] < 57){
			num++;
		}
		else if(ch[i]>97 && ch[i] < 122 ){
			if(ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u' || ch[i] == 'a')
			{
				vow++;
			}
			else 
			{
				con++;
			}
		}
		else{
			w_s++;
			//printf("%c",ch[i]);
		}
		i++;
	}
	printf("In the string total vowels are %d \n" ,vow);
	printf("in the string total consonents are %d\n",con);
	printf("in the string total digits are %d\n",num);
	printf("in the string total white space are %d\n",w_s);
	puts(ch);
}
