#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char input[50];
int i,check=1;
//push the elements to the left side
int deletefunc(int i){
	while(i+2 <=strlen(input)){
		input[i]=input[i+2];
		i++;
	}
	input[i]='\0';
}
int main(){
	printf("Enter the input ");
	gets(input);
	for(i=0;i<strlen(input);i++){
	if((input[i]=='(' && input[i+1]==')' )||(input[i]=='[' && input[i+1]==']' )||(input[i]=='{' && input[i+1]=='}' )){
		deletefunc(i);
		if(i==0)
			i-=1;
		else
			i-=2;
	}
	//checking whether character is not equal to [,(,{,},),]
	else if(input[i] !='(' && input[i] !=')' && input[i]!='[' && input[i]!=']' && input[i]!='{' && input[i]!='}' ){
		check=0;
		break;
	}
	}
if(check==1 && strlen(input)==0)
	printf("True\n");
else if(check == 0)
	printf("Invalid String \n");
else
	printf("False\n");
}
