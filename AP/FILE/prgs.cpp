/* WAP to define class STUDENT with details of student and marks of three subjects Sub1, Sub2 and Sub3. 
Display the highest marks among three students and their details in proper format for each student.
*/
#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class student
{
	int rollno;
	string name;
	string classs;
	int sub[3];
	int total=0;
	public:
		student()
		{
			sub[0]=25;
			sub[1]=25;
			sub[2]=25;
		}
		void getdata(){
				static int roll = 0;
			rollno = ++roll; //1

			cout<<"\n RollNo:";
			cin>>rollno;
			cout<<"\n Enter Name: ";
			cin>>name;
			cout<<"\n Enter class: ";
			cin>>classs;
			for(int i=0;i<3;i++)
			{
				cout<<"\n Enter Subject"<<i+1<<" Marks:";
				cin>>sub[i];
			}
		}
		void display_data(){
			cout<< "\n Rollno: " <<rollno;
			cout<< "\n Name: "   <<name;
			cout<< "\n Class: "    <<classs;
			for(int i=0; i<3; i++)
			{
				cout<<"\n Subject"<<i+1<<" Marks:"<<sub[i];
				total += sub[i];
			}
		}
	void highest_total(int n , student s[]){
		int id ;
	string name ;
	int totals;
	for(int i =0 ;i<n ;i++){
		if(s[i].total > s[i+1].total){
			id = s[i].rollno;
			name =s[i].name;
			totals = s[i].total;
		}
		break;
	}
	cout << "The student who get the highest mark that Roll No. is : " << id << " Name is : " << name << " And Total is : " << totals ;
	}
};

int main()
{
	student s[10];
	int n, i, roll;
	cout<<"\n How many students u want to enter(MAX 10):";
	cin>>n;
	for(i=0;i<n;i++)
	{
		s[i].getdata();
	}

	cout<<"\n -------Display the student details :------";
	for(i=0;i<n;i++)
	{
		s[i].display_data();
	}
	
	s[10].highest_total(n ,s);
	getch();
	return 0;
}
