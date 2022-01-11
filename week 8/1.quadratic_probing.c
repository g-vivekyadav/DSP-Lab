#include<stdio.h>
#include<stdlib.h>
int currentelements=0;
void insert(int arr[],int size,int check[]){//insertion of elements
	int value,index,key;
	printf("\nEnter the value:  ");
	if(scanf("%d",&value)==1){
	if(value<0)//if given value is negative then making it as positive for key
	key=-value;
	else
	key=value;
	int hashkey=key%size;//hashfunction
	int i;
 	for(i=0;i<size;i++)
    {
     index=(hashkey+(i*i))%size;//for quadratic probing hash function
     if(check[index] == 0 || check[index]==2)//if check==0 then it is empty and check==2 means element deleted in it
     {
        arr[index]=value;
        check[index]=1;
        currentelements++;
        printf("\nElement inserted successfully\n\n");
         break;
     }
    }
    if(i == size)//when array is full
     printf("\nsize is full/can't insert'\n\n");
}
else{
	printf("Invalid data\n\n");
	exit(0);
}
}
void display(int arr[],int size,int check[]){//display hash table
	int i;
	for(i=0;i<size;i++){
		if(check[i]==0||check[i]==2)
			printf("key = %d  value = \n",i);
		else
			printf("key = %d  value = %d\n",i,arr[i]);	
		}
}
int search(int arr[],int size,int check[])//search function to check whether given number is in hash table
{
 int value,key,index,i,hashkey,c=0;
 printf("\nEnter element:  ");
 if(scanf("%d",&value)==1){//taking element to search
 if(value<0){//if value is -ve then making it as +ve for key
 	key=-value;
 }
 else
 key=value;
 hashkey=key%size;//hash function
 i=0;
 index=(hashkey+(i*i))%size;
 while(check[index] != 0)
 {	
    index=(hashkey+(i*i))%size;//linear probing to iterate to next element
    if(arr[index]==value)
    {
    printf("\nElement found at index %d after %d collisions\n\n",index,c);
	return;	
	}
  c++;//counting collisions
  i++;
 }
    printf("\n Element not found\n\n");//if element not found
}
else{
	printf("invalid data given\n");
	exit(0);
}
}
int Delete(int arr[],int size,int check[]){//Deleting the element from hashtable
 int value,key,index,i,hashkey;
 if(currentelements==0){
 	printf("\n No elements in array\n\n");//when array is empty
 }
 else{
 printf("\nEnter element:  ");
 if(scanf("%d",&value)==1){
 if(value<0){  //making key as +ve if value is -ve
 	key=-value;
 }
 else
 key=value;
 hashkey=key%size;
 i=0;
 index=(hashkey+(i*i))%size;
 while(check[index] != 0)
 {	
    index=(hashkey+(i*i))%size;
    if(arr[index]==value)
    {
    	printf("\nElement deleted\n\n");
    	arr[index]=0;
    	check[index]=2;//when deleted making check value as 2 for easy search
    	currentelements--;
    	return;
	}
	i++;
 }
    printf("\n Element not found\n\n");
}
else{
	printf("Invalid data given\n\n");
	exit(0);
}
}
}
int main(){
	int size;
	printf("Enter the size: ");
	if(scanf("%d",&size)==1){
		int arr[size],check[size];
		int i;
		for(i=0;i<size;i++){
		arr[i]=0;
		check[i]=0;
		}
		int choice=0;
		while(choice != 6){
		printf("Enter the choice\n1.insertion 2.deletion 3.display 4.search 5.load factor 6.exit : ");
		scanf("%d",&choice);
		if(choice==1)
			insert(arr,size,check);
		else if(choice==2)
			Delete(arr,size,check);
		else if(choice==3)
			display(arr,size,check);
		else if(choice==4)
			search(arr,size,check);
		else if(choice==5){
			float load;
			load=(float)currentelements/(float)size;
			printf("\nload factor is %.2f\n\n",load);
		}
		else if(choice==6)
		break;
		else{
			printf("\nEnter valid choice\n\n");
		}		
	}
}
else{
	printf("Invalid size given\n\n");
	exit(0);
}
}
