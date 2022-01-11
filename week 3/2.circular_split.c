#include<stdio.h>
#include<stdlib.h>
int length=0;
struct node{
	int data;
	struct node* link;
}*head=NULL,*tail=NULL;
// insert function will insert new value
void insert(){
	printf("Enter the value: ");
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	if(scanf("%d",&temp->data)==1){
	temp->link=NULL;
	//when list is empty	
	if(head==NULL && tail==NULL){
		temp->link=NULL;
		head=temp;
		tail=temp;
	}
	else{
		tail->link=temp;
		tail=temp;
		tail->link=head;
	}
	length++;
	}
	else{
	// exception for input entered as character
	printf("Invalid input. Enter only integers \n\n");
	exit(0);
	}
}
//Displaying the nodes
void display(){
	struct node* temp;
	int x;
	temp=head;
	int n;
	if(length%2 == 0)
	n=length/2;
	else
	n=(length/2)+1;
	x=n;
	struct node *head1=NULL,*tail1=NULL,*head2=NULL,*tail2=NULL;
	int i=0;
	while(i<length){
		if(n>0){
		//list divided into two parts and this is first part
		struct node* temp2=(struct node*)malloc(sizeof(struct node));
		temp2->data=temp->data;
		//When list is empty
		if(head1==NULL && tail1==NULL){
		temp2->link=temp2;
		head1=temp2;
		tail1=temp2;
		}
		else{
		tail1->link=temp2;
		tail1=temp2;
		tail1->link=head1;
	}	
	n--;
		}
		else{
			//this is second part of list
		struct node* temp3=(struct node*)malloc(sizeof(struct node));
		temp3->data=temp->data;
		if(head2==NULL && tail2==NULL){
		temp3->link=temp3;
		head2=temp3;
		tail2=temp3;
		}
		else{
		tail2->link=temp3;
		tail2=temp3;
		tail2->link=head2;
			
		}
	}
	temp=temp->link;
	i++;
}
temp=head1;
i=0;
if(x==0){
	printf("List is empty\n\n");
}
else{
//displaying the first list
while(i< x){
	printf("%d ",temp->data);
	temp=temp->link;
	i++;
}
printf("\n");
temp=head2;
i=0;
//displaying the second list
while(i<(length-x)){
		printf("%d ",temp->data);
	temp=temp->link;
	i++;
}
printf("\n\n");
}
}


int main(){
	int choice=0;
	while(choice!=3){
		printf("Enter the choice\n1.Insert 2.Display 3.Exit  ");
		if(scanf("%d",&choice)==1){// check whether input is integer
		if(choice==1)
		insert();
		else if(choice==2)
		display();
		else if(choice==3)
		break;
		else
		printf("Enter the valid choice\n");
	}
	else{
		//exception raised when input is not integer
		printf("Invalid input. Enter only integers \n");
		exit(0);
	}
}
}
