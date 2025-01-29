# include<stdio.h>
# include<conio.h>
#include<malloc.h>
struct stud
{
	int roll;
	struct stud *next;
	struct stud *prev;
};
struct stud * head= NULL;
struct stud * temp;
void append()
{
	int r;
	printf("Enter the Roll Number  ");
	scanf("%d", &r);
 
	struct stud * newNode = (struct stud *) malloc (sizeof(struct stud));
	newNode->roll = r;
	newNode->next = NULL;
	newNode->prev=NULL;
 
	if (head == NULL)   {
		head = newNode;
		return;
	}
	else {
		temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		newNode->prev=temp;
		temp->next = newNode;
		return;
	}
}
void show()  {
	temp = head;
	while(temp != NULL)   {
		printf("\n %d ", temp->roll);
		temp = temp->next;
	}    
 }
 
 
void insert(int value, int p)
{
	struct stud *newNode = (struct stud *) malloc (sizeof(struct stud));
	newNode->roll = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	int c=1;
	if (head == NULL)	{
		head = newNode;
	}
	else	{
		temp = head;
		while(c<p)	{
			temp = temp->next;
			c++;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
}


void removeNode(int p)
{
	int c =1;
	if (head == NULL) {		
	printf("\nEmpty Link"); 
	return;    
	}
	else 	{
		temp = head;
		while(c < (p-1))	{
			temp = temp->next;
			c++;
		}
		struct stud * remNode = temp->next;
		temp->next = remNode->next;
		printf("\n\nThe deleted node is = %d\n\n", remNode->roll);
		free(remNode);
	}
}
int main()
{
	
 
	append();
	append();
	append();
	append();
 
	show();
	insert(99, 2);
 
	printf("\n\n Added node in between\n\n");
	show();
 
	removeNode(3);
	show();
 
	return 1;
}

