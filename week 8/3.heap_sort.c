#include<stdio.h>
#include<stdlib.h>
int size1=-1;
void insert(int a[],int size){//inserting values into array
	if(size1 == size-1)
	printf("Size is full\n\n");
	else{
	printf("Enter the value ");
	scanf("%d",&a[++size1]);
	printf("Element inserted successfully\n\n");
}
}
//max heapify
void maxheapify(int arr[], int n, int i)
{
    int largest = i; //storing maximum value from parent and child nodes into largest
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        int temp;//swapping the largest with parent node
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        maxheapify(arr, n, largest);
    }
}
//minheapify of array
void minheapify(int arr[], int n, int i)
{
    int smallest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && arr[l] < arr[i])
        smallest = l;//storing smallest value
    if (r < n && arr[r] < arr[smallest])
        smallest = r;//storing smallest value
    if (smallest != i) {
        int temp;//swapping smallest with parent node
        temp=arr[i];
        arr[i]=arr[smallest];
        arr[smallest]=temp;
        minheapify(arr, n, smallest);//recursive call
    }
}
//build min heap
void buildheapmin(int arr[],int n){
	int i;
	for ( i = n / 2 - 1; i >= 0; i--)//minheap from leaf above level
        minheapify(arr, n, i);
} 
//build max heap
void buildheapmax(int arr[],int n){
	int i;
	for ( i = n / 2 - 1; i >= 0; i--)
        maxheapify(arr, n, i);
}

void maxheapsort(int arr[], int n)//max heap sort
{
	int i;
    for ( i = n / 2 - 1; i >= 0; i--)//build max heap
        maxheapify(arr, n, i);
    for ( i = n - 1; i > 0; i--) {//swapping max value with last element in array
        int temp;
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        maxheapify(arr, i, 0);
    }
}
//minheap sort
void minheapsort(int arr[], int n)
{
	int i;
    for ( i = n / 2 - 1; i >= 0; i--)//min heapify
        minheapify(arr, n, i);
    for ( i = n - 1; i > 0; i--) {
        int temp;//swapping with root with last element
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        minheapify(arr, i, 0);
    }
}
void Delete(int a[], int size,int ch){//delete element from array
	if(size1==-1)
	printf("\nEmpty array\n\n");
	else{
	int i=0,delval;
	printf("Enter the value: ");
	scanf("%d",&delval);
	for(i=0;i<=size;i++){//iterate till last element
	if(a[i]==delval){
		int temp;//swapping with last element
		temp=a[i];
		a[i]=a[size];
		a[size]=temp;
		size1--;//decrease size value
		break;
	}
	}
	if(i>size)//if element not found
	printf("\nElement not found\n\n");
	else
	printf("\nElement  found\n\n");
	//build heapify after deletion
	if(ch==1)
		buildheapmin(a,size1);
	else
		buildheapmax(a,size1);	
	}
}
void display(int arr[], int n)//display elements
{
	int i;
	if(size1==-1)//if array is empty
	printf("\nEmpty array\n\n");
	else{
	printf("\nThe elements are:\n");
    for(i = 0; i <= n; ++i)
        printf("%d  ",arr[i]);
    printf("\n");
	}
}
int main(){
	int size;
	printf("Enter the maxsize: ");
	if(scanf("%d",&size)==1){
		if(size <= 0){//if size is given less than 1
			printf("Invalid size given\n\n");
			return;
		}
		int arr[size];
		int i=0;
		for(i=1;i<size;i++)
		arr[i]=-1;
		int choice=0;
		int ch=0;
		while(ch !=1 && ch !=2){
		printf("\nEnter the choice 1.Min heapify 2.Max heapify:  ");
		scanf("%d",&ch);
		}	
		while(choice != 6){
		printf("\nEnter the choice\n1.insertion 2.deletion 3.display  4. build heap 5.sort 6.exit : ");
		scanf("%d",&choice);
		if(choice==1)
			insert(arr,size);
		else if(choice==2)
			Delete(arr,size1,ch);
		else if(choice==3)
			display(arr,size1);
		else if(choice==4){
			if(ch==1)
			buildheapmin(arr,size1+1);
			else
			buildheapmax(arr,size1+1);
			display(arr,size1);
		}
		else if(choice==5){
			if(size1==-1)
			printf("\nEmpty array\n\n");
			else{
			if(ch==1)
			minheapsort(arr,size1+1);
			else
			maxheapsort(arr,size1+1);
			display(arr,size1);
		}
	}
		else if(choice==6)
		break;
		else{
			printf("\nEnter valid choice\n\n");
		}
			
}
}
else{
printf("\nEnter valid choice\n\n");
exit(0);	
}
}
