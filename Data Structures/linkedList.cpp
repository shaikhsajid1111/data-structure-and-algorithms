#include<iostream>
#include<cstdlib>


struct Node{
	int data;
	Node *next;
};

Node *new_node(int value);
Node *insert(Node *start,int value);
void printValue(Node *node);
bool is_there(Node *node,int value);
void deleteNode(Node **head_ref,int pos);
int main(int argc, char const *argv[])
{
	
	Node* root = new_node(4);
	insert(root,5);
	insert(root,6);
	insert(root,7);
	insert(root,8);
	for (int i = 0; i < 15000; ++i)
	{
		insert(root,i);
	}
	printValue(root);
	Node *list = new_node(9);
	printValue(list);
	system("pause");
	return 0;
}

Node *new_node(int value){
	Node *node = new Node();
	node->data = value;
	node->next = NULL;
	return node;
}

Node *insert(Node *start,int value){
	if(start == NULL){
		return new_node(value);
	}
	Node *current = start;

	while(current->next != NULL){
		current = current->next;
	}
	current->next = new_node(value);
	return current;
}
void printValue(Node *node){
	while(node != NULL){
		std::cout << node->data<< std::endl;
		node = node->next;
	}
}
bool is_there(Node *node,int value){
	Node *current = node;
	while(current->next != NULL){
		if(current -> data == value){
			return true;
			break;
		}
		current = current->next;
	}
	return false;
}

void deleteNode(Node **head_ref,int pos){
	//empty linked list
	if (*head_ref == NULL)
	{
		return;
	}

	/*head node*/
	Node *temp = *head_ref;
	/*if pos is head*/
	if (pos == 0)
	{
		*head_ref = temp->next;			/*moving head to next head*/
		free(temp);
		return;
	}
	for (int i = 0; temp != NULL && i < pos-1; ++i)
	{
		temp = temp->next;
	}
	if (temp == NULL || temp->next == NULL)
	{
		return;
	}
	Node *next = temp->next->next;
	free(temp->next);
}


