#include <stdio.h>
#include <conio.h>
//Array of Structure  Variable For More than one Student

int i,j;
struct stud
{
	int roll;
	int submark[3];
	
};
struct stud s1[3];

int main(){
	
	for(i=0;i<3;i++)
	{
		printf("Enter the Roll No.: ");
		scanf("%d",&s1[i].roll);
		printf("Enter the marks for 3 subjects: ");
		scanf("%d %d %d",&s1[i].submark[0],&s1[i].submark[1],&s1[i].submark[2]);
		printf("Roll Number = %d\n",s1[i].roll);
		printf("Marks are: %d\t %d\t %d\n",s1[i].submark[0],s1[i].submark[1],s1[i].submark[2]);
		
	}
	
	return 1;
}


//Homework: Create a Structure Variable inside another Structure.
//Create a separate variable for marks. In 1 structure, create all the variables for Physics, Maths and Chemistry.
//Create the variables of the structure in another structure.


