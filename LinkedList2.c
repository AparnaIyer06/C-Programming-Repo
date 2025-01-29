# include<stdio.h> 
# include<conio.h> 
#include<alloc.h> 

struct stud {   
int roll;   
struct stud * next; 
}; 
struct stud * head= NULL; 
struct stud * temp; 

void insert() {  
 
int r;   
printf("Enter the Roll Number ");   
scanf("%d", &r);   
struct stud * newNode = (struct stud *) malloc (sizeof(struct stud));   
newNode->roll = r;   
newNode->next = NULL;   
if (head == NULL) 
{     
head = newNode;     
return;   
}   
else {     
temp = head;     
while(temp->next != NULL)       
	temp = temp->next;     
temp->next = newNode;     
return;   
} 
} 

void show() {   
temp = head;   
while(temp != NULL) {     
printf("\n %d ", temp->roll);     
temp = temp->next;   
} 
} 


void main() {   

insert();   
insert();   
insert();   
show();   
 }
