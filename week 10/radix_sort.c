#include<stdio.h>
#include<stdlib.h>                             
int max(int arr[], int n) // This function gives maximum value in array[]
{
    int i;
    int maximum = arr[0];
    for (i = 1; i < n; i++){
        if (arr[i] > maximum)
            maximum = arr[i];
    }
    return maximum;
}
void radixSort(int arr[], int n) 
{
	int i,digitPlace = 1,res[n];
	int maximumvalue =max(arr, n);
	while(maximumvalue/digitPlace >0)
	{
        int count[10] = {0};
        for (i = 0; i < n; i++) //Store the count of "keys"
            count[ (arr[i]/digitPlace)%10 ]++;
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--) // Build the resulting array
        {
            res[count[ (arr[i]/digitPlace)%10 ] - 1] = arr[i];
            count[ (arr[i]/digitPlace)%10 ]--;
        }
        for (i = 0; i < n; i++)  
            arr[i] = res[i];
            digitPlace *= 10; // Move to next digit place
    }
    printf("Sorted order is:\n");
    for(i=0;i<n;i++)
    	printf("%d ",arr[i]);
    printf("\n\n");
}
int main()
{
    int choice=0,n,i;
    while(choice != 2){
	    printf("Enter the choice 1.Radix sort 2.Exit:  ");
    	scanf("%d",&choice);
    	if(choice==1){
			printf("\nEnter the no. of elements you want to insert:  ");
			scanf("%d",&n);
			int *arr=(int*)malloc(sizeof(int)*n);
			printf("\nEnter the values: \n");
			for(i=0;i<n;i++)
				scanf("%d",&arr[i]);
    		radixSort(arr, n);
    	}
    	else if(choice==2)
    		break;
    	else
    		printf("Enter the valid choice\n");
	}
}
