#include<stdio.h>
#include<stdlib.h>
int currentelements=0;
int prime=0;
void insert(int arr[],int size,int check[]){//insertion of elements
	int value,index,key;
	printf("\nEnter the value:  ");
	if(scanf("%d",&value)==1){
	if(value<0)
	key=-value;
	else
	key=value;
	int hashkey=key%size;//hashfunction
	int i;
 	for(i=0;i<size;i++)
    {
     index=(hashkey+i*(prime-(value%prime))%size);//double hash function
     if(check[index] == 0 || check[index]==2)//checking whether index value is empty or not
     {
        arr[index]=value;
        check[index]=1;
        currentelements++;
        printf("\nElement inserted successfully\n\n");
         break;
     }
    }
    if(i == size)//when array is full or can't insert due to hash function
     printf("\nsize is full / Can't Insert value\n\n");
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
int search(int arr[],int size,int check[])//searching in hash table
{
 int value,key,index,i,hashkey,c=0;
 printf("\nEnter element:  ");
 if(scanf("%d",&value)==1){//taking element to search
 if(value<0){//for negative values making key as positive
 	key=-value;
 }
 else
 key=value;//else key as value for positive numbers
 hashkey=key%size;//hash function
 i=0;
 index=(hashkey+i*(prime-(value%prime))%size);//double hash function
 while(check[index] != 0)
 {	
    index=(hashkey+i*(prime-(value%prime))%size);//linear probing to iterate to next element
    if(arr[index]==value)
    {
    printf("\nElement found at index %d after %d collisions\n\n",index,c);
	return;	
	}
  c++;//counting for collisions
  i++;
 }
    printf("\n Element not found\n\n");
}
else{
	printf("invalid data given\n");//entered number is not valid
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
 if(scanf("%d",&value)==1){//taking value to delete
 if(value<0){//making key as positive if given value is negative
 	key=-value;
 }
 else
 key=value;
 hashkey=key%size;//hash function
 i=0;
 index=(hashkey+i*(prime-(value%prime))%size);
 while(check[index] != 0)
 {	
    index=(hashkey+i*(prime-(value%prime))%size);//double hash function
    if(arr[index]==value)
    {
    	printf("\nElement deleted\n\n");
    	arr[index]=0;
    	check[index]=2;//making as duplicate value for easy search
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
//check whether given number is prime or not
int checkprime(int x)
{
   int c;
   for(c = 2;c <= x/2;c++)
   { 
      if ( x%c == 0 )
     return 0;
   }
   return 1;
}
void nearestprime(int size){//finding nearest prime number to given size
	size--;
	while(size>0){
		int x=checkprime(size);
		if(x==1){
			prime=size;
			break;
		}
		size--;
	}
}
int main(){
	int size;
	printf("Enter the size: ");
	if(scanf("%d",&size)==1){
		nearestprime(size);
		//printf("%d", prime);
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
			float load;//finding load factor
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
else{//if invalid character is entered then this condition executes
	printf("Invalid size given\n\n");
	exit(0);
}
}
