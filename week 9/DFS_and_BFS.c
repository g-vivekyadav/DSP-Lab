#include<stdio.h>
#include<stdlib.h>
int n,f=0,r=-1,m=-1,*queue,*visited,*values;
void DFS(int i,int* graph[n])
{
    int j;
	values[++m]=i;
    visited[i]=1;
	for(j=0;j<n;j++)
        if(!visited[j] && graph[i][j]==1)
            DFS(j,graph);
}
void BFS(int i,int* graph[n]){
	int j,k,check=0;
	for(k=0;k<n;k++){
		if(values[k]==i){
			check=1;
			break;
		}
	}
	if(check==0){
		values[++m]=i;
	}
	for (j=0;j<n;j++)
		if(graph[i][j] && !visited[j])
			queue[++r]=j;
	if(f<=r) {
		visited[queue[f]]=1;
		BFS(queue[f++],graph);
	}
}

void main()
{
    int i,j,choice=0;
    while(choice !=2){
    	printf("\nEnter the choice 1.Number of vertices 2.Exit\n");
		if(scanf("%d",&choice) != 1){
			printf("invalid choice. enter the number\n");
			exit(0);
		}
		if(choice==1){
			printf("Enter the no. of vertices\n");
			if(scanf("%d",&n) != 1){
				printf("invalid choice. enter the number\n");
				exit(0);
			}
			int* graph[n];
    		for (i = 0; i < n; i++)
        		graph[i] = (int*)malloc(n * sizeof(int));
				visited = (int*)malloc(n* sizeof(int));
				values = (int*)malloc(n* sizeof(int));
    	//read the adjecency matrix
			printf("\nEnter adjacency matrix of the graph:\n");
			for(i=0;i<n;i++){
     			for(j=0;j<n;j++){
					if(scanf("%d",&graph[i][j]) !=1){
						printf("Invalid data given. Enter only numbers");
						exit(0);
					}
				}
			}
    	//visited is initialized to zero
   			for(i=0;i<n;i++){
    		    visited[i]=0;
    		    values[i]=-1;
    		}
    		printf("\nEnter the choice 1. DFS 2.BFS\n");
    		int choice2;
    		scanf("%d",&choice2);
    		int checking=0,startnode;
    		if(choice2==1){
    			printf("Enter the start node\n");
    			scanf("%d",&startnode);
    			if(startnode >-1 && startnode < n)
    				DFS(startnode,graph);
    			else
    				printf("Invalid start node. try again\n");
    		for(i=0;i<n;i++){
    				if(values[i] == -1);
    					checking=1;
    					break;
				}
				if(checking==1)
					printf("Not reachable to all nodes\n\n");
				else{
					for(i=0;i<n;i++){
    				printf("%d ",values[i]);
				}	
				}
    		}
    		else if(choice2==2){
    			queue=(int*)malloc(sizeof(int)*n);
    			for(i=0;i<n;i++)
    				queue[i]=0;
    			printf("Enter the start node\n");
    			scanf("%d",&startnode);
    			if(startnode >-1 && startnode < n)
    				BFS(startnode,graph);
    			else
    				printf("Invalid start node. try again\n");	
    			for(i=0;i<n;i++){
    				if(values[i] == -1);
    					checking=1;
    					break;
				}
				if(checking==1)
					printf("Not reachable to all nodes\n\n");
				else{
					for(i=0;i<n;i++){
    				printf("%d ",values[i]);
				}	
				}
				}
    		else
    			printf("\nInvalid choice\n");
		}
		else if(choice==2)
			exit(0);
		else
			printf("\nEnter the valid choice\n");
		}
}
