#include <stdio.h>
#include <ctype.h>
#include<math.h>
int s[100];
char s2[100],s3[100];
int top2=-1;
int top3 =-1;
int top=-1;
int flag=0,tot=0,check=0,check2=0;
//precedence of each operator
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
//pop the top element from stack
int pop()
{
  return(s[top--]);
}
//push the value to top of the stack
int push(int value)
{
  if(flag==1){
    int topvalue;
    topvalue=pop();
    s[++top]=value+10*topvalue;
  }
  else if(flag==0){
    s[++top]=value;
    flag=1;
    s3[++top3]=' ';
    
  }
}

char push2(char ch){
	s2[++top2]=ch;
}
char pop2(){
	return s2[top2--];
}


int main()
{
  char infixexp[100],ch;
  int i=0,first,second;
  printf("Enter the Infix Expression: ");
  fgets(infixexp,100,stdin);
  //taking each character from the given string
  while( (ch=infixexp[i++]) != '\n')
  {
    if(isdigit(ch)){
	s3[++top3]=ch;
	check2=1;
	}
	else{
		//if(flag==1)
		//s3[++top3]=' ';
	    if(ch =='('){
		check++;
		push2(ch);
		}
		else if (ch == ')' && check>0){
			check--;
			while(top2 != -1 && s2[top2] !='('){
			s3[++top3]=' ';
			s3[++top3]=pop2();		
			}
			char z=pop2();	
		}
		else{
			if(top2 != -1 && s2[top2]=='^' &&ch =='^' && check2==1)
			push2(ch);
			else if((ch=='+' ||ch=='-'||ch=='*' ||ch=='*' ||ch=='/'||ch=='^') && check2==1){
			while(top2 != -1 && preced(ch) <= preced(s2[top2])){
				s3[++top3]=' ';
			s3[++top3]=pop2();
			}
			push2(ch);
			check2=0;
			}
		else
		tot=1;
		}
	s3[++top3]=' ';
	//	flag=0;
	}
	}
//printf("%s",s3);
if(tot==0 && check==0 && check2==1){
	while(top2!= -1){
	s3[++top3]=' ';
	s3[++top3]=pop2();	
	}
	s3[++top3]='\0';//postfix expression
	int w;
	for(w=0;s3[w]!='\0';w++){//evaluate postfix expression
	if(isdigit(s3[w])) 
		push(s3[w]-'0');
    	else if(s3[w]==' ')
    		flag=0;
	else{
		if(s3[w]=='+'){
			first=pop();
			second=pop();
			push(first+second);
		}
		else if(s3[w]=='-'){
			first=pop();
			second=pop();
			s[++top]=second-first;
		}
		else if(s3[w]=='*'){
			first=pop();
			second=pop();
			s[++top]=second*first;
		}
		else if(s3[w]=='/'){
			first=pop();
			second=pop();
			s[++top]=second/first;
		}
		else if(s3[w]=='^'){
			first=pop();
			second=pop();
			s[++top]=pow(second,first);
		}
	}
	}
	printf("\nPostfix Expression is ");
	for(w=0;s3[w]!='\0';w++)
	if(s3[w]!=' ')
	printf("%c",s3[w]);
	printf("\n");
	printf("\nEvaluation of Postfix expression result is %d\n",s[top]);
	}
else
	printf("\nInvalid Expression\n\n");
}

  
