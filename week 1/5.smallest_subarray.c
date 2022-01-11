#include<stdio.h>
#include<stdlib.h>
int main(){
int *a,n,x;
printf("Enter the size of array\n");
scanf("%d",&x);

a=(int*)malloc(x*sizeof(int));//allocate memory
//enter the values
printf("Enter the values\n");
int r,sum,tsum=0;
for(r=0;r<x;r++)
	scanf("%d",&a[r]);
printf("Enter the n value ");
scanf("%d",&n);
int i,j,lindex=0,rindex=0;
for(i=0;i<x;i++){
	sum=0;
	for(j=i;j<x;j++){
		sum+=a[j];
		if(sum > n){
			if(lindex==0 && rindex==0){
				lindex=i;
				rindex=j;
			}
			else if((j-i) < (rindex-lindex)){
				lindex=i;
				rindex=j;
			}
		}
	}
	if(sum>tsum)
	tsum=sum;
	}
if(tsum>n){
	printf("\nsmallest subarray is ");
	for(i=lindex;i<=rindex;i++)
		printf("%d ",a[i]);//printing smallest subarray
	printf("\n");
	printf("\noutput is ");
	for(i=lindex;i<=rindex;i++)
		printf("%d ",a[i]+(rindex-lindex+1));//adding size of array to each element
}
else
	printf("\nNo such array found\n");
}

