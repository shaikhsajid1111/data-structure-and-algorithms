/*linear linked list*/
#include<iostream>
#include<cstdlib>
/*
-----------------
|	   |		|
|value |mem 	|--------
----------------		|
						|
-----------------		|
|	   |		|		|
|value |mem 	|<------
----------------- -------
-----------------		|				
|	   |		|       |
|value |mem(NULL)|	<----
----------------

*/

struct node
{
	int data;
	node *nextNode;
};

/*
How to use:
1. Instantiate LinkedList class, e.g LinkedList ll;
2. Call its methods like ll.methodName();
*/
class LinkedList 
{
	private:
	node *head,*tail;		/*variables to keep tracks of first and last element of linked list*/
	int count;	/*to keep a count of number of nodes present in linked list*/

	public:
	LinkedList(){
		head = NULL;		/*points to first node of linked list*/
		tail = NULL;		/*points to last node of linked list*/
		count = 0;
	}

	void createNode(int value);	/*method to create a new node*/
	void display();	/*method to display all value of nodes of linkedlist*/
	void insertAtFront(int value);		/*method to insert element at head of linkedlist*/
	void insertAtPosition(int pos,int value);/*method to insert Element at some given position of linked list*/
	void deleteAtFront();	/*method to delete element at head of linked list*/
	void deleteAtEnd();	/*method to delete element at the end(tail) of linked list*/
	void deleteAtPosition(int pos);	/*method to delete element at some position of linked list*/
};


int main(int argc, char const *argv[])
{

	LinkedList llist;
	llist.createNode(25);
	l.insertAtFront(22);
	l.createNode(78);
	//l.insertAtPosition(4,45);
	/*22,25,78*/
	//l.deleteAtPosition(45);
	llist.display();
	system("pause");
	return 0;
}

void LinkedList::createNode(int value){
	
	node *temp = new node; /*allocate new node*/
	
	temp->data = value;	/*enter data into that node,which was passed as a parameter to this method*/

	temp->nextNode = NULL;		/*set the next node to NULL*/
	/*if it is a first node*/
	if(head == NULL){
		/*if it is a first node of linkedlist, than head and tails will be same, so init the head and tails
		with the current temp*/
		head = temp;	
		tail = temp;
		temp = NULL;
	}
	else{
		/*if linkedlist contains already nodes than init tail with temp's node*/
		tail->nextNode = temp;	/*tail will have the memory location of this current node as it is the last node inserted*/
		tail = temp;		
	}
	count++;	/*increase count of nodes*/
}

void LinkedList::display(){
	node *temp = new node;		/*create a new node*/
	 
	temp = head;		/*init temp with first element of linkedlist*/
	/*iterate, 
	start from first element of linkedList, until it finds element with NULL*/
	while(temp != NULL){
		std::cout << temp->data << std::endl;	/*print node's value*/
		temp = temp->nextNode;		/*move one element ahead of current*/
	}
}
void LinkedList::insertAtFront(int value){
	node *temp = new node;	/*create new node*/

	if(temp == NULL){
		std::cout << "Failed to allocate memory!";
	}
	temp->data = value;		/*init that node's(temp) data value = data*/
	temp->nextNode = head;	/*init temp's next node value to front of current linkedlist*/
	head = temp;		/*make this node as first node*/
	count++;
}

void LinkedList::insertAtPosition(int pos,int value){
	/*
	1. Pass the address of the new node in the next field of the previous node.
	2. Pass the address of the current node in the next field of the new node.
	*/
	/*if given index is not present in linked list*/
	if(count < pos-1){
		std::cout << "Cannot insert element because linked list does not have index " << pos << std::endl;
		return;
	}
	node *addressOfPreviousNode = new node;	/*node to keep track of previous node*/
	node *addressOfCurrentNode = new node;	/*node to keep track of current node*/
	node *temp = new node;		/*node to init and insert into linkedlist at some positions*/

	addressOfCurrentNode = head;/*current node will be started from first element of linked list, 
	that is start of linked list*/

	/*iterate till the position,where it has to be inserted*/

	for (int i = 1; i < pos; i++)
	{
		/*as we iterate,previous node will have value of current and current will have memory location of its next element*/
		addressOfPreviousNode = addressOfCurrentNode;	/*current node will become previous node as we iterate*/
		addressOfCurrentNode = addressOfCurrentNode->nextNode;	/*address of current will hold the memory of node ahead of it*/
	}

	/*insert data into node*/
	temp->data = value;

	/*insert node into the linkedlist at pos*/
	addressOfPreviousNode->nextNode = temp;
	temp->nextNode = addressOfCurrentNode;
	count++;
}

void LinkedList::deleteAtFront(){
	/*if no element is present in linked list*/
	if(count < 1){
		std::cout << "Linked List is empty!";
		return;
	}
	node *temp = new node;	/*init new node for temporary usage*/
	
	temp = head; /*temp holds first node of linked list*/

	head = head->nextNode;	/*move head of linked list to
	one node ahead*/

	delete temp;	/*finally delete that first node*/
	count--;
}

void LinkedList::deleteAtEnd(){
	/*if no element is present in linked list*/
	if(count < 1){
		std::cout << "Linked List is empty!";
		return;
	}
	node *currentNode = new node;	/*node to hold position of current node*/
	node *previousNode = new node;	/*node to hold previous position i.e current-1 position of currentNode,
	eventually will hold the second last node when the currentNode is the last node of linkedlist*/

	currentNode = head;		/*currentNode will start iterating from head of the linked list*/

	while(currentNode->nextNode
	 !=  NULL){	/*start iterating over the linkedlist,from head*/
		previousNode = currentNode;	/*previousNode will hold the node of currentNode that is pos-1*/
		currentNode = currentNode->nextNode;/*while the currentNode will hold node of its ahead node that it pos+1*/
	}
	/*so,when the loop is reached, the last element of the linked list than we just need to assign tail of the linked list to the
	second last node of linked list that is previousNode
	*/
	tail = previousNode;	/*tail is assigned second last value of linked list*/
	previousNode->nextNode = NULL;	/*and previoudNode's nextNode is assigned NULL because now it is the last element of the linked list*/
	delete currentNode;		/*and removed last element present in currentNode will be deleted*/
	count --;
}
void LinkedList::deleteAtPosition(int pos){
	/*if given index is not present in linked list*/
	if(count < pos-1){
		std::cout << "Linked List does not have element with index " << pos << std::endl;
		return;
	}

	node *currentNode = new node;	/*node to hold element of current node*/
	node *previousNode = new node;	/*node to hold element of current node after it has move ahead to its ahead node*/

	currentNode = head;	/*currentNode starts from head node that is first node*/

	/*iterate and move to required position*/
	for (int i = 0; i < pos; i++)
	{
		previousNode = currentNode;		/*previousNode has value of currentNode*/
		currentNode = currentNode->nextNode;	/*currentNode has value of one node ahead of itself,that is, it's next value*/
	}
	/*we have moved to required positions*/
	previousNode->nextNode = currentNode->nextNode;	/*assign previousNode the value of currentNode's next element and skip currentNode's node which will be skipped or deleted*/
	count--;
}