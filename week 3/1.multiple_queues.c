#include<stdio.h>
#include<stdlib.h>
int arr[16];
int val;
//four front, rear and max values for four queue
int f1=-1,r1=-1,f2=4,r2=4,f3=7,r3=7,f4=9,r4=9,m1=4,m2=7,m3=9,m4=15;
//Insert value into particular queue
int insertelements(int *f, int *r, int index){
printf("Enter the value ");
if(scanf("%d",&val) == 1){
if(index == 4){
if(*f==9 && *r==9){
	++(*f);
	arr[++(*r)]=val;
	}
else{
	arr[++(*r)]=val;		
}		
}
else if(index == 3){
if(*f==7 && *r==7){
	++(*f);
	arr[++(*r)]=val;
	}
else{
	arr[++(*r)]=val;		
}		
}
else if(index==2){
	if(*f==4 && *r==4){
	++(*f);
	arr[++(*r)]=val;
	}
else{
	arr[++(*r)]=val;		
}	
}
else if(index == 1){
	if(*f==-1 && *r==-1){
	++(*f);
	arr[++(*r)]=val;
	}
else{
	arr[++(*r)]=val;		
}	
}
}
else{//Raise exception when input is not integer
	printf("Invalid input. Enter only Integers\n");
	exit(0);
}
}
void insert(){
	//checking condition for overflow
	if(r3 >= m3){
		if(r2 >= m2){
			if(r1 >= m1){
				if(r4 >= m4){
					printf("Queue Overflow\n");
				}
				else{
					//insert value at desired location in queue
					insertelements(&f4,&r4,4);
				}	
			}
			else{
				insertelements(&f1,&r1,1);
				}
			}	
		else{
			insertelements(&f2,&r2,2);
		}
	}
	else{
		insertelements(&f3,&r3,3);
	}
}
void setelements(int *f,int *r,int index){
	int i;
	// printing the deleted element from queue
	printf("Deleted element is %d from Queue %d\n",arr[*f],index);
	//pushing all values towards left in the queue after deletion to maintain queue
	for (i=*f; i < *r; i++)
    {
        arr[i] = arr[i + 1];
    }
	(*r)--;
	//indexes are made to default if queue has only one element
	if(index==1){
    if (*r == -1) 
    *f = -1;
	}
	else if(index==2){
	if (*r == 4) 
    *f = 4;
	}
	else if(index == 3){
	if (*r == 7) 
    *f = 7;
	}
	else if(index==4){
	if (*r == 9) 
    *f = 9;
		
	}
}

void Delete(){
	//Underflow condition
	if(f4 == 9 && r4==9){
		if(f1==-1 && r1==-1){
			if(f2==4 && r2==4){
				if(f3==7 && r3==7)
				printf("Queue Underflow\n");
				else{
				//function called to delete and rearrange the elements
				setelements(&f3,&r3,3);
				}		
			}
			else{
				setelements(&f2,&r2,2);
			}
		}
		else{
			setelements(&f1,&r1,1);
		}
	}
	else{
		setelements(&f4,&r4,4);
	}
}
//method to display the elements in the queue
void display(){
	int i;
	printf("Q1 : ");
	//checking the base condition of queues
	if(f1 != -1){
	for(i=f1;i<=r1;i++)
	printf("%d ",arr[i]);
	}
	printf("\n");
	printf("Q2 : ");
	if(f2 != 4){
	for(i=f2;i<=r2;i++)
	printf("%d ",arr[i]);
}
	printf("\n");
	printf("Q3 : ");
	if(f3 != 7){
	for(i=f3;i<=r3;i++)
	printf("%d ",arr[i]);
}
	printf("\n");
	printf("Q4 : ");
	if(f4 != 9){
	for(i=f4;i<=r4;i++)
	printf("%d ",arr[i]);
}
	printf("\n");
}
int main(){	
	int choice=0;
	while(choice!=4){
	printf("Enter the choice\n1.Insert 2.Delete 3.Display 4.Exit  ");
	if(scanf("%d",&choice)==1){
	if(choice==1)
	insert();
	else if(choice==2)
	Delete();
	else if(choice==3)
	display();
	else if(choice==4)
		break;
	else
	printf("Enter valid choice\n");
	}
	else{
		//raise exception when input is not integer
		printf("Invalid input data. Enter only integers\n");
		exit(0);
	}
}
}
