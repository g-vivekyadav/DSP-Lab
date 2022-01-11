#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define total 5
struct node{
	char data[10];
	struct node* left;
	struct node* right;
}*root=NULL;
//max value
int max(int a,int b){
	if(a>b)
	return a;
	else
	return b;
}
//preorder
void preorder(struct node* node){
	if(node==NULL)
	return;
	printf("%s ",node->data);
	preorder(node->left);
	preorder(node->right);
}
//inorder
void inorder(struct node* node){
	if(node==NULL)
	return;
	inorder(node->left);
	printf("%s ",node->data);
	inorder(node->right);
}
//postorder
void postorder(struct node* node){
	if(node==NULL)
	return;
	postorder(node->left);
	postorder(node->right);
printf("%s ",node->data);
}
//insert values
void insert(struct node **node,char *value,char *par,int childchoice){// insertion into tree
	if(*node == NULL && *node == root){	// when root is null
		struct node* node1=(struct node*)malloc(sizeof(struct node));
		strcpy(node1->data,value);
		node1->left=NULL;
		node1->right=NULL;
		*node=node1;
		return;
	}
	else if(*node == NULL)
	return;
	else if(!(strcmp((*node)->data,par))){
		struct node* node1=(struct node*)malloc(sizeof(struct node));
		strcpy(node1->data,value);
		node1->left=NULL;
		node1->right=NULL;
		if(childchoice==1)
		(*node)->left=node1;
		else
		(*node)->right=node1;
		return;
	}
	insert(&(*node)->left,value,par,childchoice);
	insert(&(*node)->right,value,par,childchoice);
}

int height(struct node* node){// height of the tree
	if(node == NULL)
		return 0;
	else{
		int leftheight=height(node->left);
		int rightheight=height(node->right);
		return max(leftheight,rightheight)+1;
	}
}

void display(struct node *root, int h)// display
{
    if (root == NULL)
        return;
    h += total;
    display(root->right, h);
    printf("\n");
    int i=0;
    for (i = total; i < h; i++)
        printf(" ");
    printf("%s\n", root->data);
    display(root->left, h);
}


int main(){
	char value[10];
	char par[10];
	int i=0,childchoice,choice=0;	
    while (choice!=7)
    {
    	printf("Enter your choice :\n1.Insert 2.Height 3.Display 4.Preorder 5.Inorder 6.Postorder 7.Exit: ");    
        if(scanf("%d", &choice)==1){
        if(choice==1){
            if (root!=NULL){
			printf("Enter the parent name:  ");
			scanf("%s",par);
			printf("left or right child to the parent 1.left 2.right :  ");
			scanf("%d",&childchoice);
			}
			printf("Enter the value: ");
			scanf("%s",value);
			insert(&root,value,par,childchoice);        
    		}
        else if(choice== 2){
        	//leftheight=0,rightheight=0;
        	int r=height(root);
			printf("%d\n",r);
        }
        else if(choice== 3) 
            {
            	//leftheight=0,rightheight=0;
            	int r=height(root);
            	display(root,r);
				printf("\n");
			}
        else if(choice==4) {
            printf("The Preorder is :\n");
        	if(root==NULL)
        	printf("Empty");
        	else
            preorder(root);
            printf("\n");
        }
        else if(choice==5) {
            printf("The Inorder is :\n");
        	if(root==NULL)
        	printf("Empty");
        	else
            inorder(root);
            printf("\n");
        }
        else if(choice==6) 
         {
		   printf("The Postorder is :\n");
        	if(root==NULL)
        	printf("Empty");
        	else
            postorder(root);
            printf("\n");
        }
        else if(choice==7)
        break;
        else 
        	printf("Enter valid choice\n");
        }
        else{
        	printf("Invalid input. Only integers allowed\n");
        	exit(0);
		}

}
}
