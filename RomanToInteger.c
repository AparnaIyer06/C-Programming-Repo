#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int romanToInt(char* s) {
    int i=0;
    int num[10];
    int ans=0;
    while(s[i]!='\0'){
        switch(s[i]){
            
            case 'I':
                num[i]=1;
                break;
            case 'V':
                num[i]=5;
                break;
            case 'X':
                num[i]=10;
                break;
            case 'L':
                num[i]=50;
                break;
            case 'C':
                num[i]=100;
                break;
            case 'D':
                num[i]=500;
                break;
            case 'M':
                num[i]=1000;
                break;

        }
        
        i++;
    }
    
    if(s[i]=='\0'){

        num[i]=NULL;
    }

    i=0;
    while(num[i]!=NULL){
        if(num[i]<num[i+1]){
            ans=ans-num[i];
        }
        else{
            ans=ans+num[i];
        }
        i++;

    }
    return ans;
    
}



int main(){
	
	int num1=romanToInt("MCMXCIV");
	int num2=romanToInt("IV");
	int num3=romanToInt("LVIII");
	int num4=romanToInt("XXIX");
	printf("\nMCMXCIV: %d",num1);
	printf("\nIV: %d",num2);
	printf("\nLVIII: %d",num3);
	printf("\nXXIX: %d",num4);
	
}
