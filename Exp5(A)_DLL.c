#include <stdio.h>
#include <conio.h>
#include <string.h>

//Creating the structure for each Student node.
struct Student
{
int age;
char name[50];
long roll_no;
struct Student *next; // Pointer to next node in DLL
struct Student *prev; // Pointer to previous node in DLL
};

//Function to print the details of each student

void printStudent(struct Student* student){
	printf("Name: %s \n",student->name);
	printf("Roll Number: %d \n",student->roll_no);
	printf("Age: %d \n",student->age);
	printf("\n");
}


int main()
{
	
/*Create a Double Linked list to store and print roll number, name and age of 3
students.
Description:
Assume the list with three nodes n1, n2 and n3 for 3 students.
Create a structure as a collection three variables – Name, Roll No & Age. Structure will also
contain a pointer variable which will point to the next node. Pointer of the last element will
point to NULL. */

//Create 3 students.

struct Student *n1,*n2,*n3;

n1=(struct Student*)malloc(sizeof(struct Student));

n2=(struct Student*)malloc(sizeof(struct Student));

n3=(struct Student*)malloc(sizeof(struct Student));

//Initialize student details.

strcpy(n1->name,"Aparna");
n1->roll_no=1;
n1->age=19;

strcpy(n2->name,"Raji");
n2->roll_no=2;
n2->age=56;

strcpy(n3->name,"Satya");
n3->roll_no=3;
n3->age=59;

//Set Next Pointers.

n1->next=n2;
n2->next=n3;
n3->next=NULL;

//Set Previous Pointers.

n1->prev=NULL;
n2->prev=n1;
n3->prev=n2;

//Print details of each student.

printf("Details of Student 1: \n");
printStudent(n1);

printf("Details of Student 2: \n");
printStudent(n2);

printf("Details of Student 3: \n");
printStudent(n3);

//Free memory.

free(n1);
free(n2);
free(n3);

return 0;

}
