#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

//Compare the Addresses of the elements, and not the elements themselves.

//Find the element of intersection of 2 Linked Lis

struct node{
	int data;
	struct node *next;
};


struct node concatenateLinkedLists(struct node *head1, struct node *head2){
	
	if(head1==NULL){
		
		return head1;
		
	}
	else if(head2==NULL){
		
		return head2;
		
	}
	else{
		
		struct node *temp1=head1;
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
			
		}
		if(temp1->next==NULL){
			temp1->next=head2;
		}
	}
}


void insert(struct node **head,int data) //Pointer to pointer of head
{ 
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	
	if(*head==NULL){
		**head=*newNode;
	}
	else{
		
		struct node *temp=*head; //Pointer of Head is stored 
		while(temp->next!=NULL){
			
			temp=temp->next;
		}
		temp->next=newNode;
	}
}

void intersectionLinkedLists(struct node *head1,struct node *head2, struct node *head3){
	
	struct node *temp1=head1;
	struct node *temp2=head2;
	struct node *temp3=head3;
	
	//Concatenate l1 and l3 for l4, & l2 and l3 for l5
	
	struct node *head4=concatenateLinkedLists(head1,head3);
	struct node *head5=concatenateLinkedLists(head2,head3);
	
	//Compare Linked Lists l4 and l5 to find element at the intersection point 
	struct node *temp4=head4;
	struct node *temp5=head5;
	
	while(temp4!=NULL && temp2!=NULL){
		
		if(temp4==temp5){
			printf("\nIntersected at %d",temp4->data);
		}
		temp4=temp4->next;
		temp5=temp5->next;
	}
	
}

int main(){
	
	
	
	
	return 1;
}
