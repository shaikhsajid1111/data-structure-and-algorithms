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


void deleteNode(Node **head_reference,int key){
	struct Node *temp = *head_reference,*prev;

	/*if node itself contains the value that has to be deleted*/
	if(temp != NULL && temp->data == key){	/*if temp is not and temp has value that was asked to delete*/
		*head_reference = temp->next;	/*moving the head of the LL towards next value, which'll become head*/
		free(temp);		/*free the space*/
		return;
	}

	while(temp != NULL && temp->data != key){/*until and unless the temp reaches NULL and data doesn't matches key*/
		prev = temp;	/*stirung current value in prev variable*/
		temp = temp->next;	/*than switching towards the next value*/
	}
	if(temp == NULL) return;	/*if LL is already empty*/
	prev->next = temp->next;
	free(temp);
}

