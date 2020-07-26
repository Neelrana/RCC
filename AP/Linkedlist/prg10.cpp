#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
namespace l1 {
	ostream & printline(ostream & out) // userdefine manipulator
	{
		out << "====================================================================================";
		out << endl;
		return out;
	}
}
class marksheet{
	char sub[20];
	int m1,m2;
	int total;
	char grade;
	public :
		int m3;
		void get_data();
		void display_data();	
};

void marksheet :: get_data(){
	cout << "Enter the subject Name :\n";
	cin >> sub;
	cout << "Enter the internal marks :\n";
	cin >> m1;
	cout << "Enter the external mark :\n";
	cin >> m2;
	if(m1 > 25 || m2 > 100){
		cout << "Enter data again marks are not valid : \n";
		get_data();
	}
}

void marksheet :: display_data(){
	m3 = m1+m2;
	cout.width(21);
	cout << sub;
	cout.width(21);
	cout << m1;
	cout.width(21);
	cout << m2;
	cout.width(16);
	cout << m3;
	cout << endl; 
}
int main(){
	int i , n ,roll_no,col_width=10,total=0,t_m = 0;
	char name[50],dept[50];
	marksheet m1[20];
	cout << "Enter the name of the student:\n";
	cin >> name;
	cout << "Enter the Roll No.\n";
	cin >> roll_no;
	cout << "Enter the department name :\n";
	cin >> dept;
	cout << "Enter how many subject you want to add : \n";
	cin >> n;
	t_m = n * 150 ;
	for(i=0;i<n;i++){
		m1[i].get_data();
	}

	cout << l1::printline;
	cout.width(45) ;
	cout << "MARKSHEET"<< "\n";
	cout << l1::printline; 
	cout <<setiosflags(ios::left)<<setw(col_width) << "Name :"<< "\t" ; printf(name);
	cout << endl;
	cout.width(11);
	cout <<setiosflags(ios::left)<< "Roll No.:" << "\t" << roll_no ; 
	cout << endl;
	cout.width(11);
	cout << setiosflags(ios::left) << "Department: " << "\t" ; printf(dept);
	cout << endl;
	cout << l1 :: printline;
	cout.width(21);
	cout << "subject";
	cout.width(21);
	cout << "internal";
	cout.width(21);
	cout << "external";
	cout.width(21);
	cout << "total";
	cout << endl;
	cout << endl;
	for(i=0;i<n;i++){
		m1[i].display_data();
		total += m1[i].m3;
	}
	cout << l1 :: printline;	cout << "Total is "<< total;
	cout << "  out of :" << t_m << endl;
	cout << l1 :: printline;
	}
