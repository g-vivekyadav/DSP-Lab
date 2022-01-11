#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	int height;
	struct node* left;
	struct node* right;
}*root=NULL;
//get the balance of the tree
int getBal(struct node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}
// right rotation to balance the tree
struct node *rightrotation(struct node *root)
{
    struct node *l = root->left;
    struct node *r = l->right;
    l->right = root;
    root->left = r;
    root->height = max(height(root->left), height(root->right))+1;
    l->height = max(height(l->left), height(l->right))+1;
    return l;
}
//left rotation to balance the tree
struct node *leftrotation(struct node *root)
{
    struct node *r = root->right;
    struct node *l = r->left;
    r->left = root;
    root->right = l;
    root->height = max(height(root->left), height(root->right))+1;
    r->height = max(height(r->left), height(r->right))+1;
    return r;
}
//insert into the tree
struct node* insert(struct node *node,int value){
if(node == NULL){	//if tree is empty
	struct node* node1=(struct node*)malloc(sizeof(struct node));
	node1->data=value;
	node1->left=NULL;
	node1->right=NULL;
	node1->height=1;
	node=node1;
	printf("\nValue inserted\n\n");
	return node;
}
else{
if(value < node->data ){ // if value is less than current node value
	node->left=insert(node->left,value);	
}
else if(value >node->data){ // if value is greater than current node value
	node->right=insert(node->right,value);	
}
else{
	printf("\nNumber already exists\n\n");
	return node;
}
}
node->height = 1 + max(height(node->left),
                           height(node->right));
    int bal = getBal(node);
    // LL Case
    if (bal > 1 && value < node->left->data)
        return rightrotation(node);
    // RR Case
    if (bal < -1 && value > node->right->data)
        return leftrotation(node);
    // LR Case
    if (bal > 1 && value > node->left->data)
    {
        node->left =  leftrotation(node->left);
        return rightrotation(node);
    }
    // RL Case
    if (bal< -1 && value < node->right->data)
    {
        node->right = rightrotation(node->right);
        return leftrotation(node);
    }
    return node;
}
int maximumvalue(struct node *temp) // it will return maximum value in the right 
    {
        if(temp->right == NULL)
            return temp->data;
        return maximumvalue(temp->right);
    }
struct node* Delete(struct node* root, int value) 
   {
    if(root==NULL){//if root is null
    	printf("\nNo such value found\n");
        return NULL;
    }
    if(root->data  < value)//recursive call if value is greater than current node value
        root->right=Delete(root->right,value);
    else if(root->data > value ) // recursive call if value is less than current node value
        root->left=Delete(root->left,value);
    else if(root->data==value) //here node found
    {
    	if(root->left==NULL && root->right==NULL)//if node is present in leaf node
            return NULL;
            
        else if(root->right!=NULL && root->left!=NULL)//node have two childs
        {				
            int maxi=maximumvalue(root->left);
            root->data=maxi;
            root->left=Delete(root->left,maxi);
            return root;
        }
        else
        {
        	//node have either left or right child only.
            if(root->right!=NULL)
               return root->right;
            else if(root->left!=NULL)
                return root->left;
            }
        }
    if (root == NULL)
    return root;
    root->height = 1 + max(height(root->left),height(root->right));
    int bal = getBal(root);
    if (bal> 1 && getBal(root->left) >= 0)
        return rightrotation(root);
    if (bal > 1 && getBal(root->left) < 0)
    {
        root->left =  leftrotation(root->left);
        return rightrotation(root);
    }
    if (bal < -1 && getBal(root->right) <= 0)
        return leftrotation(root);
    if (bal < -1 && getBal(root->right) > 0)
    {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }
        return root;
    }
int max(int a,int b){//returns maximum value
	if(a>b)
	return a;
	else
	return b;
}
int height(struct node* node){//returns the height of the tree
	if(node == NULL)
	return 0;
	else{
	return node->height;
}
}
struct node* Findroot(struct node* root,int value){//check whether given value is present in the tree 
	if(root == NULL)
	return NULL;
	if(root->data == value)
	return root;
	else if(root->data < value)
	Findroot(root->right,value);
	else if(root->data > value)
	Findroot(root->left,value);
}
int totalvalue=0;
void Sumofnodes(struct node* root){//Sumof nodes of the left subtree of root
	if(root==NULL)
	return;
	else{
	totalvalue+=root->data;
	Sumofnodes(root->left);
	Sumofnodes(root->right);	
	}
}
void preorder(struct node* node){//preorder of the tree
	if(node==NULL)
	return;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}
void inorder(struct node* node){//inorder of the tree
	if(node==NULL)
	return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}
void postorder(struct node* node){//postorder of the tree
	if(node==NULL)
	return;
	postorder(node->left);
	postorder(node->right);
printf("%d ",node->data);
}
void displaylevel(struct node* temp,int l){
	if(temp == NULL)
	return;
	if(l==1)
	printf("%d ",temp->data);
	else if(l >1){
		displaylevel(temp->left,l-1);
		displaylevel(temp->right,l-1);
	}	
}
void levelorder(struct node* temp,int h){
	int i=1;
	while(i<=h){
		displaylevel(temp,i);
		i++;
	}
	printf("\n");
}
int main(){
	int choice=0;
    while (choice!=5)
    {
    	printf("Enter your choice :\n1.Insert 2.Delete 3.Display 4.Sum of all nodes of left subtree 5.Exit : ");    
        if(scanf("%d", &choice)==1){
        if(choice==1){
        	int value;
        	printf("Enter the value: ");
        	if(scanf("%d",&value)==1)
        	root=insert(root,value);
        	else{
        		printf("Only integers allowed\n");
        		exit(0);
			}
        }
        else if(choice== 2){
        	int delvalue;
        	if(root==NULL)
			printf("\nAVL tree is empty\n");
			else{
        	printf("Enter the value: ");
        	if(scanf("%d",&delvalue)==1){
        	root=Delete(root,delvalue);
        	}
        	else{
        		printf("Only integers allowed\n");
        		exit(0);
        }
    	}}
        else if(choice== 3){
        	if(root==NULL)
			printf("\nThe Tree is empty\n\n");
			else{
			printf("\nPreorder: ");
			preorder(root);
			printf("\nInorder: ");
			inorder(root);
			printf("\nPostorder: ");
			postorder(root);
        	printf("\nLevelorder: ");
			levelorder(root,height(root));
			printf("\n");
		}}
        else if(choice== 4){
        	int rootvalue=0;
        	printf("\nEnter the root value: ");
        	scanf("%d",&rootvalue);
        	struct node* temp=Findroot(root,rootvalue);
        	totalvalue=0;
        	if(temp==NULL)
        	printf("\n No such root found\n\n");
        	else{
        	Sumofnodes(temp->left);
        	printf("\nSum of all nodes of left subtree is %d\n",totalvalue);
        }
    }
        else if(choice== 5) 
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
