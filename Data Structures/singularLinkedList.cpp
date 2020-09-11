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
/*
How to use:
1. Instantiate LinkedList class, e.g LinkedList<typename> ll;
2. Call its methods like ll.methodName();
*/
template <typename T>
class LinkedList 
{
	private:
	/*linked list's node structure*/
	struct node
{
	T data;	/*to hold data of node*/
	node *nextNode;	/*to hold next node's connection*/
};
	node *head,*tail;		/*variables to keep tracks of first and last element of linked list*/
	int count;	/*to keep a count of number of nodes present in linked list*/
	
	public:
	/*default constructor if linked list is created without any constructor parameters*/
	LinkedList(){
		head = NULL;		/*points to first node of linked list*/
		tail = NULL;		/*points to last node of linked list*/
	
	}
	/*cobstructor if linked list is created with one value*/
	LinkedList(T value){
		node *temp = new node;	/*allocate a node*/
		temp->data = value;	/*assign data to node*/
		temp->nextNode = NULL;	/*set next node to NULL*/
		head = temp;	/*as it is first node,assign it with temp as head because it first node*/
		tail = temp;	/*tail will also be temp node because there's only one node'*/
		temp = NULL;	
	}
	void insert(T value);	/*method to create a new node*/
	
	void display();	/*method to display all value of nodes of linkedlist*/
	
	void insertAtFront(T value);		/*method to insert element at head of linkedlist*/
	void insertAtPosition(int pos,T value);/*method to insert Element at some given position of linked list*/
	
	void deleteAtFront();	/*method to delete element at head of linked list*/
	void deleteAtEnd();	/*method to delete element at the end(tail) of linked list*/
	void deleteAtPosition(int pos);	/*method to delete element at some position of linked list*/
	
	void sortLinkedList();	/*method to sort linked list*/
	
	bool search(T value);	/*method to search first occurence of element in linked list*/
	
	int allOccurence(T value); /*method to get number of times element have occured in linked list*/
	
	void merge(LinkedList);	/*method to merge 2 linked list*/
		
	int nodeCount();	/*method to count number of node in linked list*/
};


int main(int argc, char const *argv[])
{

	LinkedList<int> llist(1);
	llist.insert(2);
	llist.insert(3);
	llist.insert(10);	
	
	LinkedList<int> llist2(4);
	llist2.insert(5);
	llist2.insert(15);
	
	llist.merge(llist2);
	llist.insertAtFront(0);
	std::cout << llist.nodeCount() << "End" <<std::endl;
	//l.insertAtPosition(4,45);
	/*22,25,78*/
	
	//llist.sortLinkedList();
	
	llist.display();
	return 0;
}
template<class T>
void LinkedList<T>::insert(T value){
	
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
	//count++;	/*increase count of nodes*/
}
template<class T>
void LinkedList<T>::display(){
	node *temp = new node;		/*create a new node*/
	 
	temp = head;		/*init temp with first element of linkedlist*/
	/*iterate, 
	start from first element of linkedList, until it finds element with NULL*/
	while(temp != NULL){
		std::cout << temp->data << std::endl;	/*print node's value*/
		temp = temp->nextNode;		/*move one element ahead of current*/
	}
}
template<class T>
void LinkedList<T>::insertAtFront(T value){
	/*
	 * steps:
	 1. Create a new node
	 2. Put given value into that node
	 3. point temp's nextNode' to head directly
	 4. And re-init the head to temp
	 * */
	node *temp = new node;	/*create new node*/
	if(temp == NULL){
		std::cout << "Failed to allocate memory!";
	}
	
	
	temp->data = value;		/*init that node's(temp) data value = data*/
	temp->nextNode = head;	/*init temp's next node value to front of current linkedlist*/
	head = temp;		/*make this node as first node*/
	//count++;
}

template<class T>
void LinkedList<T>::insertAtPosition(int pos,T value){
	/*
	1. Make 2 pointer and temp of type node, first to hold address of previous node and one to keep addres of current node
	2. iterate over linked list for pos number of times
	3. after iteration,insert value into that node 
	4. now change the nextNode of previous pointer node such that it point towards temp node
	5. change the temp node's nextNode to point towards the currentNode's nextNode
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
	temp->nextNode = addressOfCurrentNode;	/*join the nextNode of temp to its next memory location*/
	//count++;
}
template<class T>
void LinkedList<T>::deleteAtFront(){
	/*
	 1. Create a temp node of type node
	 2. Assign temp with head node 
	 3. assign head the value of its ahead node, that is move ahead by 1 pos
	 4. now delete that temp var, which has stored previous head address.
	 */
	/*if no element is present in linked list*/
	if(head == NULL){
		std::cout << "Linked List is empty!";
		return;
	}
	node *temp = new node;	/*init new node for temporary usage*/
	
	temp = head; /*temp holds first node of linked list*/

	head = head->nextNode;	/*move head of linked list to
	one node ahead*/

	delete temp;	/*finally delete that first node*/
	//count--;
}
template<class T>
void LinkedList<T>::deleteAtEnd(){
	/*if no element is present in linked list*/
	if(head == NULL){
		std::cout << "Linked List is empty!";
		return;
	}
	node *currentNode = new node;	/*node to hold position of current node*/
	node *previousNode = new node;	/*node to hold previous position i.e current-1 position of currentNode,
	eventually will hold the second last node when the currentNode is the last node of linkedlist*/

	currentNode = head;		/*currentNode will start iterating from head of the linked list*/

	while(currentNode->nextNode !=  NULL){	/*start iterating over the linkedlist,from head*/
		previousNode = currentNode;	/*previousNode will hold the node of currentNode that is pos-1*/
		currentNode = currentNode->nextNode;/*while the currentNode will hold node of its ahead node that it pos+1*/
	}
	/*so,when the loop is reached, the last element of the linked list than we just need to assign tail of the linked list to the
	second last node of linked list that is previousNode
	*/
	tail = previousNode;	/*tail is assigned second last value of linked list*/
	previousNode->nextNode = NULL;	/*and previoudNode's nextNode is assigned NULL because now it is the last element of the linked list*/
	delete currentNode;		/*and removed last element present in currentNode will be deleted*/
	//count --;
}
template<class T>
void LinkedList<T>::deleteAtPosition(int pos){
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
//	count--;
}
template<class T>
void LinkedList<T>::sortLinkedList(){
	node *currentNode = new node;	/*currentNode iterate all over the linkedList*/
	currentNode = head;			/*currentNode init with head,i.e first element of the linked list*/
	node *index = new node;	/*holds the index of the current node*/
	int temp;		/*temporary var for swapping*/
	/*if linked list is empty*/
	if(head == NULL){
		return;
	}
	/*while currentNode does not reaches last node*/
	while(currentNode->nextNode != NULL){
		/*holds the address of the nest node*/
		index = currentNode->nextNode;
		/*sorting, while index does not reaches last node*/
		while(index != NULL){
			/*if the previous value is smaller than after value*/
			if(currentNode->data > index->data){
				/*swap value of variable*/
				temp = currentNode->data;
				currentNode->data = index->data;
				index->data = temp;
			}
			/*move ahead of current node to next node*/
			index = index->nextNode;
		}
		/*move ahead ti next node*/
		currentNode = currentNode->nextNode;
	}
}
template<class T>
bool LinkedList<T>::search(T value){
	/*linear search for element in linked list*/
	if(head == NULL){
		std::cout << "Linked list is empty!" << std::endl;
		return false;
		}
	node *temp = new node;	/*temporary node for iterating over linked list*/
	temp = head;	/*init with head, iterate from beginning*/
	while(temp != NULL){	/*while it does not reaches NULL*/
		if(temp->data == value){
			/*if node's data matches the given value,return true'*/
			return true;
		}
		temp = temp->nextNode;	/*move ahead to next node*/
	}
	/*if nothing found returns false*/
	return false;
}
template<class T>
int LinkedList<T>::allOccurence(T value){
	if(head == NULL){
		std::cout << "Linked list is empty!" << std::endl;
		return 0;
		}
		int occuranceCount = 0;
		node *temp = new node;	/**temporary node for iterating over linked list*/
		temp = head;
		while(temp != NULL){
			if(temp->data == value){
				/*if element matches,than increase vakue of count by 1*/
				occuranceCount++;
				}
			temp = temp->nextNode; /*move one node ahead*/
		
		}
		return occuranceCount;
}

template<class T>
void LinkedList<T>::merge(LinkedList ll){
	/*if linked list is empty*/
	if(head == NULL or ll.head == NULL){
		std::cout << "Linked list is empty!" << std::endl;
		}
		
	tail->nextNode = ll.head;	/*join current tail's to next link list's head*/
	tail = ll.tail;	/*now tail is tail of other linkedlist*/
	

	
	}
template<class T>
int LinkedList<T>::nodeCount(){
	node *temp = new node;
	int count = 0;	/*to keep a count of node presents*/
	temp = head;	/*to iterate from head to tail*/
	
	do{
		count++;	/*increment on each iterate*/
		temp = temp->nextNode;	/*move one node ahead*/
		}while(temp!=NULL);
	return count;
	
	}
