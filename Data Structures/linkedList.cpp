#include<iostream>

struct Node{
	int data;
	Node *next;
};
Node *new_node(int value);
Node *insert(int value);
void printValue(Node *node);
bool is_there(Node *node,int value);

int main(int argc, char const *argv[])
{

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
	Node *current = node;
	while(current->next != NULL){
		std::cout << current->data<< std::endl;
		current = current->next;
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
