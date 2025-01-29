//Valid Parentheses Problem (Own)

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>


//Defining a simple stack

typedef struct Stack{
	
	int top;
	unsigned capacity;
	char* array;	
}Stack;

//Function to create a stack of a given capacity

Stack* createStack(unsigned capacity){
	
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity=capacity;
	stack->top=-1;
	stack->array=(char*)malloc(stack->capacity*sizeof(char));
	return stack;
}

//Stack is full when top is equal to the last index

int isFull(Stack* stack){
	
	return stack->top==stack->capacity-1;
	
}

//Stack is empty when top is -1

int isEmpty(Stack* stack){
	
	return stack->top==-1;
	
}

//Function push to add an item to the stack. Increases top by 1.

void push(Stack* stack,char item){
	
	if(isFull(stack)){
		
		return;
	}
	
	stack->array[++stack->top] = item;
}

//Function pop to remove an item from the stack. Decrease top by 1.

char pop(Stack* stack){
	
	if(isEmpty(stack)){
		return '\0';
	}
	return stack->array[stack->top--];
}

//Function peek to get the top item of the stack without removing it from the stack.

char peek(Stack *stack){
	if(isEmpty(stack)){
		return '\0';
	}
	return stack->array[stack->top];
}

//Function to check if the given character is a matching pair

int isMatchingPair(char character1,char character2){
	
	if (character1=='(' && character2==')')
		return 1;
	else if(character1=='{' && character2=='}')
		return 1;
	else if(character1=='['&& character2==']')
		return 1;
	else 
		return 0;
}

//Function to check if the input string is valid

int isValid(char* s){
	
	int length=strlen(s);
	Stack* stack=createStack(length);
	int i;
	for(i=0;i<length;i++){
		
		char current = s[i];
		
		if(current=='(' || current=='{'|| current=='['){
			push(stack,current);
		}
		
		else if(current==')'||current=='}'||current==']'){
			if(isEmpty(stack)||!isMatchingPair(pop(stack),current)){
				return 0;
			}
		}
	}
	if(!isEmpty(stack)){
		return 0;
	}
	return 1;
}

int main(){
	
	char s[]="(){}[]";
	
	if(isValid(s)){
		printf("%s is valid\n",s);
	}
	else{
		printf("%s is not valid\n",s);
	}
}
