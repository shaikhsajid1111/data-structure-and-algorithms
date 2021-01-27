#include<iostream>


/*
Structure:
root_element  
	|
	|
	|
 3--5--4

*/

struct node{
		int data;
		node *right;
		node *left;
		
		};

struct node* insert(node *root,int data);


void inOrder(struct node* root);	
void preOrder(struct node* root);
void postOrder(struct node* root);
struct node *newNode(int item);
struct node *invertTree(struct node *root);
int main(int argc, char const *argv[])
{	
	node *bst = NULL;
	bst = insert(bst,4);
	insert(bst,1);
	insert(bst,2);
	insert(bst,3);
	insert(bst,4);
	insert(bst,5);
	bst = invertTree(bst);
	postOrder(bst);
	
	
	
	return 0;
}
struct node *newNode(int item){ 
    struct node *temp =  new node; 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 




struct node* insert(struct node *root,int data){
		if(root == NULL){
			return newNode(data);
			
			}
		if(data < root->data){
			root->left = insert(root->left,data);
			}
		else if(data > root->data){
			root->right = insert(root->right,data);
	}
	return root;

}		

void inOrder(node* root){
	/*Left, Root, Right*/
	if(root != NULL){
		inOrder(root->left);
		std::cout << root->data << std::endl;
		inOrder(root->right);
		}
		
	}

void preOrder(struct node* root){
	/*root,left,right*/
	if(root!= NULL){
		std::cout<<root->data << std::endl;
		preOrder(root->left);
		preOrder(root->right);
		}
	
	}
void postOrder(struct node* root){
	/*left,right and root*/
	if(root != NULL){
		postOrder(root->left);
		postOrder(root->right);
		std::cout << root->data << std::endl;
		}
	
	}


struct node *invertTree(struct node *root){
	if(root){
		struct node *temp = new node;
		temp = root->left;
		root->left = root->right;
		root->right = temp;

		invertTree(root->left);
		invertTree(root->right);
	}
	return root;

}