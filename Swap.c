#include <stdio.h>
#include <conio.h>

void swap(int x,int y)
{
	
	int temp=x;
	x=y;
	y=temp;
	printf("First number is %d\n",x);
	printf("Second number is %d\n",y);
}

int main(){
	
	int a=10, b=20;
	printf("Original numbers: ");
	printf("\nFirst Number is %d",a);
	printf("\nSecond Number is %d",b);
	printf("\n\nCalling Swap Function\n");
	swap(a,b);
	
	return 0;
}
