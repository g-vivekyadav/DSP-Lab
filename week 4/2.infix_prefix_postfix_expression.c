#include <stdio.h>
#include <ctype.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char* infixexp,s[20];
char* prefixexp;
int top=-1,check=0,enter=0,size;
char ch;
int invalid=0,countbrace=0;
void infix(){
  printf("Enter the size: ");
  if(scanf("%d",&size)==1){
  infixexp = (char*)malloc((size+1)*sizeof(char));
  prefixexp = (char*)malloc((size+2)*sizeof(char));
  invalid=0,countbrace=0,check=0;
  printf("Enter the Infix Expression: ");
  fflush(stdin);
  gets(infixexp);
  if(strlen(infixexp) > size){
  invalid=1;
  printf("Invalid size given\n");
}
}
else{
	printf("Invalid size\n");
	exit(0);
}
}
void checkinfix(){
  int s[50];//stack
  int top=-1;
  countbrace=0,check=0;
  int i=0;
  for(i=0; i<strlen(infixexp); i++ ){
  	ch=infixexp[i];
  	if((i==0 || (i==strlen(infixexp)-1)) && (ch =='+'|| ch=='-'||ch=='*'||ch=='/'||ch=='^')){
  		invalid=1;
		return;	
	  }
	else{
		if((ch == '(' || ch=='{' || ch=='[') && check==0 ){
			s[++top]=ch;
		} 
		else if(((ch == ')' && s[top]=='(')||(ch==']' && s[top]=='[') ||(ch=='}' && s[top]=='{'))&& check==1 ){
		top--;
		}
		else if((ch =='+'|| ch=='-'||ch=='*'||ch=='/'||ch=='^') && check == 1 ){
			check=0;
		}
		else if ((isalpha(ch)|| isdigit(ch))&& check == 0){
			check=1;
		}
		else if(ch==' '){
		}
		else{
			invalid=1;
			return;
		}
	}
  	
  }
  if(top!= -1)
  invalid=1;
}
char push(char ch){
	s[++top]=ch;
}
char pop()
{
  return(s[top--]);
}
int preced(char ch) 
{ 
    if(ch =='+' || ch=='-')
        return 1; 

    else if(ch =='*' || ch=='/')
        return 2; 

    if(ch =='^')
        return 3; 
    return -1; 
} 

void prefix(){
top=-1,countbrace=0,check=0;
int i,j=0;
s[0]='\0';
char ch;
strrev(infixexp);
//printf("%s",infixexp);
for (i=0;i<strlen(infixexp);i++) {
ch=infixexp[i];
if ((isalpha(ch)||isdigit(ch))) {
	prefixexp[j]=ch;
	j++;
	} 
else {
	if (ch==')' || ch=='}' || ch==']') {
		push(ch);
	}
	else if(ch == '(') {
	while (s[top]!=')') {
		prefixexp[j]=pop();
		j++;
		}
		pop();
		}
	else if(ch == '[') {
	while (s[top]!=']') {
		prefixexp[j]=pop();
		j++;
		}
		pop();
		}
	else if(ch == '{') {
	while (s[top]!='}') {
		prefixexp[j]=pop();
		j++;
		}
		pop();
		}
	else if(ch==' '){
	}
	else {
		if (preced(s[top])<=preced(ch)) {
			push(ch);
		}
		else {
			while(preced(s[top])>=preced(ch)) {
			prefixexp[j]=pop();
			j++;
			}
			push(ch);
			}
		}
		}
}
	while (top!=-1) {
		prefixexp[j]=pop();
		j++;
	}
	prefixexp[j]='\0';
strrev(infixexp);//reverse the infix expression	
}
//postfix expression
void postfix(){
top=-1,countbrace=0,check=0;
s[0]='\0';
int i=0,j=0;
char ch;	
for (i=0;i<strlen(infixexp);i++) {
	ch=infixexp[i];
	if(isalpha(ch)||isdigit(ch)){
		prefixexp[j++]=ch;
	}
    else if(ch =='(' || ch=='{' || ch=='['){
	push(ch);
	}
	else if (ch == ')'){
	while(top != -1 && s[top] !='(')
		prefixexp[j++]=pop();	
	char ch=pop();
	}
	else if (ch == ']'){
	while(top != -1 && s[top] !='[')
		prefixexp[j++]=pop();	
	char ch=pop();
	}
	else if (ch == '}'){
	while(top != -1 && s[top] !='{')
		prefixexp[j++]=pop();	
	char ch=pop();
	}
	else if(ch==' '){
	}
	else{
		if(top != -1 && s[top]=='^' && ch =='^')
		push(ch);
		else{
			while(top != -1 && preced(ch) <= preced(s[top]))
				prefixexp[j++]=pop();
			push(ch);
			}
		}
	}
while (top!=-1) {
		prefixexp[j++]=pop();
	}
	prefixexp[j]='\0';
}	
int main(){
	int choice=0;
    while (choice!=5)
    {
    	printf("Enter your choice :\n1.Enter Infix 2.Check infix 3.Prefix 4.Postfix 5.Exit: ");    
        if(scanf("%d", &choice)==1){
        if(choice==1){
        	enter=1;
            infix();
        }
        else if(choice== 2){
        	checkinfix();
        	if(enter==0)
        	printf("\nInfix is empty\n\n");
        	else if(invalid==0)
        	printf("\nGiven Infix notation is valid\n\n");
        	else
        	printf("\nGiven Infix notation is invalid\n\n");
        	
        }
        else if(choice== 3) {
        	if(enter == 0)
        	printf("\nInfix is empty\n\n");
        	else {
			checkinfix();
			if(invalid==0){
            prefix();
            strrev(prefixexp);
            printf("Prefix notation is  ");
            printf("\n%s\n\n",prefixexp);
       	 	}
       	 	else
       	 	printf("\nGiven infix is invalid\n\n");
   		 	}
   			}
        	else if(choice== 4) {
        	if(enter == 0)
        	printf("Infix is empty\n");
        	else {
			checkinfix();
			if(invalid==0){
            postfix();
            printf("Postfix notation is  ");
            printf("\n%s\n\n",prefixexp);
       	 }
       	 else
       	 printf("\nGiven infix is invalid\n\n");
   		 }
   	}
		else if(choice==5)
        break;
        else
        	printf("\\nEnter valid choice\n\n");
        }
        else{
        	printf("\nInvalid input.\n\n");
        	exit(0);
		}
}
}
