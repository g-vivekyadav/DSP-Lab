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
    while(choice != 2){
    	printf("\nEnter the choice 1.Number of vertices 2.Exit\n");
		if(scanf("%d",&choice)!= 1){
			printf("invalid choice\n");
			exit(0);
		}
		if(choice==1){
			printf("Enter the no. of vertices\n");
			scanf("%d",&n);
			if(n<=0){
				printf("Invalid choice\n");
				exit(0);
			}
			int* graph[n];
    		for (i = 0; i < n; i++)
        		graph[i] = (int*)malloc(n * sizeof(int));
				visited = (int*)malloc(n* sizeof(int));
				values = (int*)malloc(n* sizeof(int));
				queue=(int*)malloc(sizeof(int)*n);
    	//read the adjecency matrix
			printf("\nEnter adjacency matrix of the graph:\n");
			for(i=0;i<n;i++)
     			for(j=0;j<n;j++)
					scanf("%d",&graph[i][j]);
    	//visited is initialized to zero
    		int choice2=0;
    		while(choice2 != 4){
    			printf("\nEnter the choice 1. DFS 2.BFS 3.back to menu 4.exit\n");
    			if(scanf("%d",&choice2) != 1){
    				printf("invalid choice\n\n");
    				exit(0);
				}
    			for(i=0;i<n;i++){
    			    visited[i]=0;
    			    queue[i]=0;
    			    values[i]=-1;
    			}
    			m=-1;
    			if(choice2==1){
    				printf("Enter source vertex: ");
    				int source;
    				scanf("%d",&source);
    				if(source <1 || source >n){
    					printf("invalid choice\n");
					}
					else{
    					DFS(source-1,graph);
    					for(i=0;i<n;i++){
    						if(values[i] != -1){
    							printf("%d ",values[i]+1);
    						}
    						else{
    							printf("\nNot reachable to all nodes\n");
    							break;
							}
						}
					}
    			}
    			else if(choice2==2){
    				printf("Enter source vertex: ");
    				int source2;
    				scanf("%d",&source2);
    				if(source2 <1 || source2 >n){
    					printf("invalid choice\n");
					}
					else{
						BFS(source2-1,graph);
    					for(i=0;i<n;i++){
    						if(values[i] != -1){
    							printf("%d ",values[i]+1);
    						}
    						else{
    							printf("\nNot reachable to all nodes\n");
    							break;
							}
						}
    				}
    			}
    			else if(choice2==3){
    				break;
				}
				else if(choice2==4){
					exit(0);
				}
    			else
    				printf("\nInvalid choice\n");
			}
		}
		else if(choice==2)
			exit(0);
		else
			printf("\nEnter the valid choice\n");
		}
}
