#include<iostream>

struct Node{
	int data;
	struct Node *left,*right;
};
/*
Structure:
	root_element  
	|
	|
	|
 3--5 -------4

*/

struct Node *newNode(int data);
struct Node *insert(struct Node *root,int data);
void inOrder(struct Node *root);
void postOrder(struct Node *root);
void preOrder(struct Node *root);
struct Node* minimum(struct Node *root);
struct Node* deleteNode(struct Node *root,int value);

int main(int argc, char const *argv[])
{
	
	return 0;
}

struct Node *newNode(int data){
	struct Node *node = new Node;
	node->data = data;
	node->right = node -> right = NULL;
	return node;
}

struct Node *insert(struct Node *root,int data){
	if(root == NULL){
		return newNode(data);
	}


	/*if data is smaller than the root*/
	if(data < root->data){
		root->left = insert(root->left,data);
	}
	/*if data is bigger than the root*/
	else if(data > root->data){
		root->right = insert(root->right,data);
	}
	return root;

}
void inOrder(struct Node *root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d\n",root->data);
		inOrder(root->right);
	}
}

void postOrder(struct Node *root){
	if(root == NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->data << std::endl;
}

void preOrder(struct Node *root){
	if(root == NULL) return;

	std::cout << root->data << std::endl;
	preOrder(root->left);
	preOrder(root->right);
}
struct Node* minimum(struct Node *root){
	if(root == NULL) return root;
	while(root->left != NULL){
		root = root->left;
	}
	return root;
}
struct Node* deleteNode(struct Node *root,int value){
	if(root == NULL) return root;

	if(value < root->data){
		root->left = deleteNode(root->left,value);
	}


	else if(value > root->data){
		root -> right = deleteNode(root->right,value);
	}

	else{
		if(root->left == NULL){
			struct Node *temp = root->left;
			free(root);
			return temp;
		}
		else if(root -> right == NULL){
			struct Node *temp = root->right;
			free(root);
			return temp;
		}
		struct Node *temp = minimum(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right,temp->data);
	}

	return root;

}