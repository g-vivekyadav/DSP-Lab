#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int length=0;
struct node{
	int data;
	struct node *link;
}*head;
//display the elements and decimal value
void display(){
	if(head==NULL){
		printf("Empty List\n");
		printf("Decimal equivalent value is 0\n\n");
	}
	else{
		struct node* temp;
		temp=head;
		int x=length-1,sum=0;
		printf("Binary representation is ");
		while(temp!=NULL){		//calculating the decimal value
			printf("%d",temp->data);
			if(temp->data == 1)
				sum+=pow(2,x);
			x--;
			temp=temp->link;
		}
	printf("\n\nDecimal Equivalent value is %d\n\n",sum);
}
}
void beginning(){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value: ");
	if(scanf("%d",&temp->data)==1){
		if(temp->data == 0 || temp->data == 1){
		if(head == NULL){
			temp->link=NULL;
			head=temp;
		}
		else{
			temp->link=head;
			head=temp;
		}
		printf("Inserted successfully\n\n");
		length++;
		}
		else
			printf("Invalid value \n\n");
	}
	else{
		printf("Only integers allowed\n");
		exit(0);
	}
}
void ending(){
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value: ");	
	if(scanf("%d",&temp->data)==1){
		if(temp->data == 0 || temp->data == 1){
		if(head == NULL){
		temp->link=NULL;
		head=temp;
		}
		else{
			struct node* temp2;
			temp2=head;
			while(temp2->link != NULL)
				temp2=temp2->link;
			temp->link=NULL;
			temp2->link=temp;
		}
		printf("Inserted successfully\n\n");
		length++;
		}
		else
			printf("Invalid value \n\n");
	}
	else{
		printf("Only integers allowed\n\n");
		exit(0);
	}
}
int main(){
	int choice=0;
	while(choice!=3){
		printf("Enter the choice\n1.Insert 2.Display 3.Exit ");
		if(scanf("%d",&choice)==1){
		if(choice == 1){
			int x;
			printf("1. Insert at Beginning 2. Insert at Ending  ");
			if(scanf("%d",&x)==1){
			if(x==1)
			beginning();
			else if(x==2)
			ending();
			else
			printf("Invalid choice\n");
			}
			else{
				printf("Only integers allowed");
				exit(0);
			}
		}
		else if(choice==2)
		display();
		else if(choice==3){
		}
		else{
		printf("Invalid choice\n");
		choice=0;
	}
}
else{
	printf("Only integers allowed");
	exit(0);
}
}
}
