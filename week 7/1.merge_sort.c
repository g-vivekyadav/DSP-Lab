#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long arr[100000000];
void merge(long arr[], int l, int m, int r) {
int n1 = m - l + 1;
int n2 = r - m;
int L[n1], M[n2],i,j,k;
for (i = 0; i < n1; i++)
  L[i] = arr[l + i];
for (j = 0; j < n2; j++)
  M[j] = arr[m + 1 + j];
  i=0;
  j=0; 
  k=l;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) { //check values from 1st array and 2nd array
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }
  while (i < n1) {//if size of 1st array is greater than size of 2nd array,insert remaining elements of 1st array
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {//if size of 1st array is greater than size of 2nd array, insert remaining elements of 2nd array
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(long arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);//left partition
    mergeSort(arr, m + 1, r);//right partition
    merge(arr, l, m, r);
  }
}
void display(long arr[],int s){
	mergeSort(arr, 0,s-1);
  //printf("\nSorted array: ");
  //int i;
  //for (i = 0; i < s; i++)
    //printf("%d ", arr[i]);
  //printf("\n\n");
}
int main(){ 
		int s;
  	printf("Enter the size: ");
  	if(scanf("%d",&s)==1){
  	if(s<=0){
  		printf("\nInvalid size given\n\n");
  		exit(0);
	  }
  //int arr[s];
  	int i=0;
  	int max=s;
  	int temp;
  	for(i=0;i<s;i++){
  	arr[i]=i+1;
  	}
  //using rand() function,making a array contains random integers and calculating the time taken.
  	for (i = 0; i < s; i++)  
    {  
    int j=i+rand()%(s-i);
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t; 
	}
	printf("\nGiven random integers are: \n");
	for(i=0;i<s;i++){	
	printf("%d ",arr[i]);
    }
  	clock_t t;
    t = clock();
    display(arr,s);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\nRandom elements after sorted : \n");
    for(i=0;i<s;i++)
    printf("%d ",arr[i]);
    printf("\ntime taken for random numbers is %f\n\n", time_taken); 
    //inserting sorted numbers in to the array and calculating the time taken
    printf("\nGiven sorted numbers are: \n");
    for(i=0;i<s;i++){
    	arr[i]=i+1;
    	printf("%d ",arr[i]);
	}
	printf("\n");
    t = clock();
    display(arr,s);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Sorted array is: \n");
    for(i=0;i<s;i++){
    	printf("%d ",arr[i]);
	}
    printf("\ntime taken for sorted numbers  is %f\n\n", time_taken);
    
    //making an array as almost sorted and calculating time taken to sort.
    int num=s/100;
    for (i = 0; i < num; i++)  
    {  
    int j=i+rand()%(s-i);
    int t=arr[i];
    arr[i]=arr[j];
    arr[j]=t; 
	}
	printf("Given almost sorted elements are:\n");
    for(i=0;i<s;i++)
    printf("%d ",arr[i]);
    printf("\n");
    t = clock();
    display(arr,s);
    t = clock() - t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Elements after sorted:\n");
    for(i=0;i<s;i++)
    printf("%d ",arr[i]);
    printf("\ntime taken for almost sorted numbers  is %f\n\n", time_taken);
  	}
  	else{
  	printf("\nInvalid size given\n\n");
  	exit(0);
  
  	}	
}
