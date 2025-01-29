#include <stdio.h>
#include <conio.h>
//Stack Implementation
int top=-1;
int stack[5];

void push(){
	
	int item;
	if(top==4){ //Last position has been reached
			
		printf("\n The stack is Full.");
		return;
	}	
	else{
		printf("\nEnter the value to insert: ");
		scanf("%d",&item);
		top++;
		stack[top]=item; //Pushed (added) the element in the stack
	}
}

void show(){
	
	int i=0;
	if(top==-1){
		printf("\nNo element to display.");
		return;
	}
	while(i<=top){
		
		printf("\n%d ",stack[i]);
		i++;
	}
}

void pop(){
	
	if(top==-1){
		printf("\nThe Stack is empty.");
		return;
	}
	else{
		printf("\nThe value %d is popped.",stack[top]);
		top--;
	}
	
}

int main(){
	
	push();
	push();
	push();
	show();
	
	pop();
	pop();
	show();
	
	return 1;
}
