#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
}*head;//create a head node

void push(){
	struct node* stack=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value ");
	scanf("%d",&stack->data);
	if(head == NULL){
		stack->link=NULL;
		head=stack;
	}
	else{
		stack->link=head;
		head=stack;
	}
	printf("Value inserted\n\n");
}
//pop the element from the stack
void pop(){
	if(head==NULL)
		printf("Stack Underflow\n\n");
	else{
		struct node* stack;
		stack=head;
		head=head->link;
		printf("Deleted value is %d\n\n",stack->data);
		free(stack);
	}
}
//display the elements
void display(){
	if (head == NULL)
		printf("Stack is empty\n\n");
	else{
		struct node* stack;
		stack=head;
		printf("The elements are \n");
		while(stack!=NULL){
			printf("%d ",stack->data);
			stack=stack->link;
	}
	printf("\n\n");
	}
}
int main(){
int n;
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
