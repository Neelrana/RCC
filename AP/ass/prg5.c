#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct two_wheelar{
	float milage;
	char type[20];
};
struct four_wheelar{
	char usage[10];
	double engine_no;
	char f_type[10];
};

union v_type{
	struct two_wheelar t1;
	struct four_wheelar f1;
};
struct vehicle {
	char name[30];
	int price;
	char v_type[20];
	union v_type vt1;
};

struct vehicle get_data(struct vehicle v1){\
	printf("\n********************************\n");
	printf("Enter vehicle name:\n");
	scanf("%s",v1.name);
	printf("Enter Vehicle price:\n");
	scanf("%d",&v1.price);
	printf("Enter vehicle type(two-wheelar / four-wheelar): \n");
	scanf("%s",v1.v_type);
	
	if(strcmp(v1.v_type,"two-wheelar")==0){
		printf("Enter milage: \n");
		scanf("%f",&v1.vt1.t1.milage);
		printf("Enter type(gared / gearless)");
		scanf("%s",v1.vt1.t1.type);		
	}
	else if(strcmp(v1.v_type,"four-wheelar")==0){
		printf("Enter the usage of car (auto/manual): \n");
		scanf("%s",v1.vt1.f1.usage);
		printf("Enter the engine no:\n");
		scanf("%ld",&v1.vt1.f1.engine_no);
		printf("Enter the type of the car(heavy/light) : \n");
		scanf("%s",v1.vt1.f1.f_type);
	}
	else{
		printf("Enter proper vehicle type:\n");
		exit(0);
	}
	printf("\n********************************\n");
	return v1;
}

struct vehicle display_data(struct vehicle v1){
	printf("\n********************************\n");
	if(strcmp(v1.v_type,"two-wheelar")==0){
		printf("Vehicle name is: %s\n",v1.name);
		printf("Vehicle price is : %d\n",v1.price);
		printf(" Milage is : %f\n",v1.vt1.t1.milage);
		printf("Vehicle type is: %s\n",v1.vt1.t1.type);	
	}
	else if(strcmp(v1.v_type,"four-wheelar")==0){
			printf("Vehicle type is : %s\n",v1.v_type);
			printf("Vehicle name is: %s\n",v1.name);
			printf("Vehicle price is : %d\n",v1.price);
			printf("The usage of car is : %s\n",v1.vt1.f1.usage);
			printf("The engine no is : %d\n",v1.vt1.f1.engine_no);
			printf("The type of the car is %s: \n",v1.vt1.f1.f_type);
	}
//	printf("Vehicle name is: %s\n",v1.name);
//	printf("Vehicle price is : %d\n",v1.price);
//	printf("Vehicle type is : %s\n",v1.v_type);
//	if(strcmp(v1.v_type,"two-wheelar")==0){
//		printf(" Milage is : %f\n",v1.vt1.t1.milage);
//		printf("Vehicle type is: %s\n",v1.vt1.t1.type);
//	}
//	else if(strcmp(v1.v_type,"four-wheelar")==0){
//		printf("The usage of car is : %s\n",v1.vt1.f1.usage);
//		printf("The engine no is : %d\n",v1.vt1.f1.engine_no);
//		printf("The type of the car is %s: \n",v1.vt1.f1.f_type);
//	}
}
int main(){
	int i ,n ;
	struct vehicle v1[20];
	printf("Enter how many records you want to enter :\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		v1[i]=get_data(v1[i]);
	}
	
	for(i=0;i<n;i++){
		display_data(v1[i]);
	}
}


/*
Enter how many records you want to enter :
2

********************************
Enter vehicle name:
verna
Enter Vehicle price:
400000
Enter vehicle type(two-wheelar / four-wheelar):
four-wheelar
Enter the usage of car (auto/manual):
auto
Enter the engine no:
123456789
Enter the type of the car(heavy/light) :
heavy

********************************

********************************
Enter vehicle name:
shine
Enter Vehicle price:
60000
Enter vehicle type(two-wheelar / four-wheelar):
two-wheelar
Enter milage:
60
Enter type(gared / gearless)gared

********************************

********************************
Vehicle name is: verna
Vehicle price is : 400000
Vehicle type is : four-wheelar
The usage of car is : auto
The engine no is : 123456789
The type of the car is heavy:

********************************
Vehicle name is: shine
Vehicle price is : 60000
Vehicle type is : two-wheelar
 Milage is : 60.000000
Vehicle type is: gared

--------------------------------
Process exited after 103.8 seconds with return value 2
Press any key to continue . . .
*/
