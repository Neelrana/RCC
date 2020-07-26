//Finding minimum of given numbers
#include<stdio.h>
#include<string.h>
int toInt(char str[]) // this function converts the string value to integer it is user define 
{
	int i = 0, result=0, negative=0;
		if(str[0]=='-') {
		negative=1;
		i=1;
		}
	while(str[i]!='\0') {
		result= result * 10 +(str[i]-'0');
		i++;
	}
	if(negative)
		result*=-1;
	return result;
}
int main(int argc, char *argv[])
{
	int min, i;
	min=toInt(argv[1]);
	for(i=2; i<argc; i++) {
		if(min > toInt(argv[i]))
			min=toInt(argv[i]);
	}
	printf("Min = %d", min);
}

/* output :

E:\ROLWALA\sem2\AP\FILE>09_neel_rana.exe 10 20 30 01
Min = 1
E:\ROLWALA\sem2\AP\FILE>

*/
