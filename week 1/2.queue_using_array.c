#include<stdio.h>
#include<stdlib.h>
int *queue,n;
int front=-1,rear=-1;
void Enqueue(){
	if(rear+1 == n)
	printf("\nQueue Overflow\n");
	else{
		if(front==-1)
		front++;
		rear+=1;
		int a;
		printf("\nEnter the value ");
		scanf("%d",&a);
		queue[rear]=a;
		printf("\nValue inserted\n");
	}
}
void Dequeue(){
	if(front>rear || front==-1)
	printf("\nQueue Underflow\n");
	else{
		if(front==rear){
		printf("\nValue Deleted is %d\n",queue[front]);
		front=-1;
		rear=-1;
		}
		else{
		printf("\nValue Deleted is %d\n",queue[front]);
		front+=1;
		}
	}
}
//display the elements
void display(){
	int i;
	if(front==-1 || front > rear)
	printf("\nQueue is empty");
	else{
	for(i=front;i<=rear;i++)
	printf("%d ",queue[i]);
	}
	printf("\n");
}

int main(){
	printf("Enter the size of Queue ");
	scanf("%d",&n);
	queue=(int*)malloc(n*sizeof(int));
	int x=0;	
	while(x!=4){
		printf("\nSelect Option\n1.Enqueue 2.Dequeue 3.display 4.exit\n");
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
		printf("\nEnter valid choice\n");
	}
}
