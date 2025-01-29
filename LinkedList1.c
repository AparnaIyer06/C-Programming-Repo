#include<stdio.h> 
#include<conio.h> 
#include<alloc.h> 
struct stud  
{   int roll;   
struct stud * next; 
}; 

struct stud * head = NULL; 
struct stud * temp; 

void main(){  
struct stud * n1 = (struct stud *) malloc (sizeof(struct stud));   
n1->roll = 200;   n1->next = NULL;   
struct stud * n2 = (struct stud *) malloc (sizeof(struct stud));   
n2->roll = 300;   
n2->next = NULL;   
struct stud * n3 = (struct stud *) malloc (sizeof(struct stud));   
n3->roll = 400;   
n3->next = NULL;   
struct stud * n4 = (struct stud *) malloc (sizeof(struct stud));   
n4->roll = 500;   n4->next = NULL;   clrscr();   
printf("\n The data for n1 = %d , address of n1 = %u", n1->roll, n1);   
printf("\n The data for n2 = %d , address of n2 = %u", n2->roll, n2);   
printf("\n The data for n3 = %d , address of n3 = %u", n3->roll, n3);   
printf("\n The data for n4 = %d , address of n4 = %u", n4->roll, n4);   
n1->next = n2;   n2->next = n3;   n3->next = n4; 
//  printf("\n\n n2 data = %d", n1->next->roll); 
//  printf("\n\n n3 data = %d", n1->next->next->roll); 
//  printf("\n\n n4 data = %d", n1->next->next->next->roll);   
head = n1;   
temp = head;   
while(temp != NULL)   
{     
printf("\n The Data = %d", temp->roll);     
temp = temp->next;   
}   

return 1;
 }
