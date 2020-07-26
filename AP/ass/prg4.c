#include<stdio.h>
#include<conio.h>
#include<string.h>
struct book{
	char author_name[20];
	char title[20];
	float price;
	char publisher[20];
	int stock;
};

struct book get_data(struct book b1){
	printf("\n*********************************\n");
	printf("Enter Author Name :\n");
	scanf(" %[^\n]",b1.author_name);
//	gets(b1.author_name);
	printf("Enter Title Of Book :\n");
	scanf(" %[^\n]",b1.title);
	printf("Enter price of book :\n");
	scanf("\n%f",&b1.price);
	printf("Enter Publisher Name :\n");
	scanf(" %[^\n]",b1.publisher);
	printf("Enter Stock of book :\n");
	scanf("\n%d",&b1.stock);
	printf("\n*********************************\n");
	return b1;
}

struct book display_data(struct book b1){
	printf("Author name is : %s:\n",b1.author_name);
	printf("Title is %s :\n",b1.title);
	printf("Price of the book is %f : \n",b1.price);
	printf("Publisher name is %s:\n",b1.publisher);
	//printf("stock is %d : \n",b1.stock);
	printf("\n*********************************\n");
	return b1;
}

void search(struct book b1[],int n){
	char b_title[20],a_name[20],pub[20];
	int i,found=0,copies=0;
	float price,total_price;
	
	printf("\nEnter The title of the book you want to find : \n");
	scanf(" %[^\n]",b_title);
	printf("\nEnter the author name you want to search :\n");
	scanf(" %[^\n]",a_name);
	
	for(i=0 ; i<n; i++){
		if(strcmp(b1[i].title,b_title)==0)
		{
			printf("\nDetails of the book is : \n");
			display_data(b1[i]);
			found=1;
			price = b1[i].price;
		}
	}
	if(found==0){
		printf("Record not fornd: \n");
	}
	
if(found==1){
	printf("Enter No of copies you want to get :\n");
	scanf("%d",&copies);
	if(copies>=b1[i].stock){
		printf("Stock is available :\n");
		total_price = copies * price;
		printf ("Total Price is : %.2f",total_price);
	}
	else {
		printf("Stock is not available : \n");
	}
}

}

int main(){
	int i,n ;
	struct book b1[20];
	printf("Enter No of books you want to add:\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		b1[i]=get_data(b1[i]);
	}
	//for(i=0;i<n;i++){
	//	display_data(b1[i]);
	//}
	search(b1,n);
	getch();
}


/*
Enter No of books you want to add:
2

*********************************
Enter Author Name :
Ashok
Enter Title Of Book :
c lang
Enter price of book :
300
Enter Publisher Name :
bpb
Enter Stock of book :
20

*********************************

*********************************
Enter Author Name :
Bhushan
Enter Title Of Book :
c++
Enter price of book :
200
Enter Publisher Name :
oxfard
Enter Stock of book :
30

*********************************

Enter The title of the book you want to find :
c lang

Enter the author name you want to search :
Ashok

Details of the book is :
Author name is : Ashok:
Title is c lang :
Price of the book is 300.000000 :
Publisher name is bpb:

*********************************
Enter No of copies you want to get :
10
Stock is available :
Total Price is : 3000.00

*/
