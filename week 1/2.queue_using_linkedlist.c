#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
}*front,*rear;
void Enqueue(){
	struct node* temp=(struct node*)malloc(sizeof(struct node));//create node
	printf("Enter the value ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(front == NULL && rear == NULL){
		front=rear=temp;
	}
	else{
		rear->link=temp;
		rear=temp;
	}
	printf("Value inserted\n");
}

void Dequeue(){
	if(front==NULL && rear==NULL)
		printf("Queue Underflow\n");
	else{
		if(front==rear){
			printf("Deleted value is %d\n",rear->data);
			front=rear=NULL;	
		}
		else{
		struct node* temp;
		temp=front;
		front=front->link;
		printf("Deleted value is %d\n",temp->data);
		free(temp);
		}
	}
}


void display(){
	if (front == NULL && rear == NULL)
		printf("Queue is empty\n");
	else{
		struct node* temp;
		temp=front;
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->link;
		}
		printf("\n");
	}
}

int main(){
int n;
int x=0;
while(x!=4){
printf("Select Option\n1.Enqueue 2.Dequeue 3.display 4.exit\n");
scanf("%d",&x);
if(x==1){
	Enqueue();
}
else if(x==2){
	Dequeue();
}
else if(x==3){
	display();
}
else if(x==4){
}
else
printf("Enter valid choice\n");
}
}
