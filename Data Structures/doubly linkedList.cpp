#include <iostream>
#include<cstdlib>

struct node{
	int data;
	node *next;
	node *prev;
};

class Doubly_linked_list{
	node *front;
	node *end;

public:
	/*default constructor*/
	Doubly_linked_list(){
		front,end = NULL;
	}

	/*double linked lists operations*/
	void add_front(int);
	void add_after(node *,int);
	void add_before(node *,int);
	void add_end(int);
	void delete_node(node*);
	void forward_traverse();
	void backward_traverse();

};
int main(int argc, char const *argv[])
{
	
	return 0;
}

void Doubly_linked_list::add_front(int data){
	node *temp;	/*create new NODE*/

	temp = new node();

	temp->data = data;
	temp->prev = NULL;
	temp->next = front;

	/*if list is empty and it is first node*/
	if(front == NULL){
		end = temp;
	}
	else{
		front->prev = temp;
	}
	front = temp;

}

void Doubly_linked_list::add_after(node *n,int data){
	node *temp;
	temp = new node();
	temp->data = data;
	temp->prev = n;
	temp->next = n->next;
	n->next = temp;

	if(n->next == NULL){
		end = temp;
	}
}