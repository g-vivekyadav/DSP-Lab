#include<stdio.h>
#include<stdlib.h>
int *stack,n;
int top=-1;
void push(){
	if(top+1 == n)
		printf("\nStack Overflow\n\n");
	else{
		top+=1;
		int a;
		printf("\nEnter the value ");
		scanf("%d",&a);
		stack[top]=a;
		printf("Value inserted\n\n");
	}
}
void pop(){
	if(top<=-1)
		printf("Stack Underflow\n");
	else{
		printf("Value Deleted is %d\n",stack[top]);
		top-=1;
	}
}
void display(){
	int i;
	if(top==-1)
		printf("Stack is empty");
	else{
		printf("\nThe elements are\n");
		for(i=top;i>-1;i--)
		printf("%d ",stack[i]);
	}
	printf("\n\n");
}
int main(){
printf("Enter the size of stack ");
scanf("%d",&n);
stack=(int*)malloc(n*sizeof(int));
int x=0;
while(x!=4){
printf("Select Option\n1.push 2.pop 3.display 4.exit\n");
scanf("%d",&x);
if(x==1){
	push();
}
else if(x==2){
	pop();
}
else if(x==3){
	display();
}
else if(x==4){
}
else
printf("\nEnter valid choice\n");
}
}
