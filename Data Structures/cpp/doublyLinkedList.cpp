#include <iostream>



template<typename T>
class Doubly_linked_list{
	private:
struct node{
	
	T data;
	node *nextNode;
	node *prevNode;
};
	node *front;
	node *end;

public:
	/*default constructor*/
	Doubly_linked_list(){
		/*default constructor if linked list is initliazed with no value*/
		front = NULL;
		end = NULL;
	}
	Doubly_linked_list(T value){
		node *newNode = new node;
		newNode->data = value;
		newNode->prevNode = NULL;
		newNode->nextNode = NULL;
		front = newNode;
		end = newNode; 
		}
	/*double linked lists operations*/
	void insertAtPosition(T value,int pos);
	void insertAtFront(T);		/*method to insert element at the front*/
	void insert(T);

	void deleteLastNode();
	void deleteFirstNode();
	void deleteAtPosition(int pos);
	
	void backwardTraverse();
	void forwardTraverse();
	
	void merge(Doubly_linked_list);
	
	void sort();

};


int main(int argc, char const *argv[])
{
	Doubly_linked_list<int> dll(1);

	dll.insert(2);
	dll.insert(3);
	Doubly_linked_list<int> dll2(4);
	dll2.insert(5);
	dll2.insert(6);
	dll.merge(dll2);
	Doubly_linked_list<int> dll3(7);
	dll3.insert(8);
	dll.merge(dll3);
	dll.forwardTraverse();
	return 0;
}

template<class T>
void Doubly_linked_list<T>::insertAtPosition(T value,int pos){
	if(front == NULL){
		std::cout << "Underflow!" << std::endl;
		return;
		}
	node *newNode = new node;
	newNode->data = value;
	node *currentNode = new node;
	currentNode = front;
	
	
	
	for(int i = 1;i < pos-1;i++){
		if(currentNode == end){
			std::cout << "only " << i << " is available" << std::endl;
			return;
			}
		currentNode = currentNode->nextNode;
		
		}
	newNode->nextNode = currentNode->nextNode;
	newNode->prevNode = currentNode;
	currentNode->nextNode = newNode;
	
	/*else{
		newNode->prevNode = currentNode;
		newNode->nextNode = currentNode->nextNode;
		currentNode->nextNode = newNode;
		
		
	}*/
	/*if currentNode was last element,element was inserted at the end of the linked list*/
	if(currentNode == end){
		end = newNode;	/*end will be newNode because now last node is newNode*/
		}
	/*if element was inserted at front of the linkedlist*/
	if(currentNode == front){
		front = newNode;	/*front is now changed to newNode's address*/
		}
	
	}

template<class T>
void Doubly_linked_list<T>::insertAtFront(T data){
	/*create a new node*/
	node *newNode = new node;
	
	/*assign data to node's data member*/
	newNode->data = data;
	/*if we are adding node to front than it's
	  previous node will point to NULL*/
	newNode->prevNode = NULL;
	
	/*front contains the first element of previous,
	 as we are adding in to front than previous front node will 
	 become nextNode of newNode
	 * */
	 
	newNode->nextNode = front;
	/*if list is empty*/
	if(front == NULL){
		end = newNode;	/*because it has only 1 element,end will have the current newNode's address*/
		}
	else{
		front->prevNode = newNode;	/*now front element is move ahead so it's NULL value will be changed to current's newNode*/
		}
	front = newNode; /*because we are adding node in the front,so front will hold the address of current newNode*/
}




template<class T>
void Doubly_linked_list<T>::forwardTraverse(){
	node *trav = new node;
	trav = front;
	while(trav != NULL){
		std::cout << trav->data << std::endl;
		trav = trav->nextNode;
		}
	
	}

template<class T>
void Doubly_linked_list<T>::backwardTraverse(){
	node *trav = new node;
	trav = end;
	while(trav != NULL){
		std::cout << trav->data << std::endl;
		trav = trav->prevNode;
		}
	}
template<class T>
void Doubly_linked_list<T>::insert(T value){
		node *newNode = new node;
		/*if memory failed to allocate*/
		if(newNode == NULL){
			std::cout << "Could not allocate space!" << std::endl;
			}
		/*assign value to the newNode's data member*/
		newNode->data = value;
		/*if doubly linked list is empty*/
		if(end == NULL){
			newNode->nextNode = NULL;	/*newNode's nextNode will be NULL by default*/
			newNode->prevNode = NULL;	/*newNode's prevNode will be NULL too as it is first element*/
			front = newNode;	/*now front points to newNode as well, because it is first as well as last element*/
			}
		/*if linkedlist has nodes already*/
		else{
			newNode->nextNode = NULL;/*newNode's nextNode will be empty because it inserted at last*/
			newNode->prevNode = end;	/*and prevNode will be end because end already had address of end node*/
			end->nextNode = newNode;	/*newNode's nextNode will have inserted into linkedList so,
			 last element is now the newNode*/
			
			}
		end = newNode;	/*now end element is newNode because it has been inserted into the last element*/

}

template<class T>
void Doubly_linked_list<T>::deleteLastNode(){
	if(end == NULL){
		std::cout << "List is empty!" << std::endl;
		return;
		}
	node *nodeToDelete = new node;
	nodeToDelete = end;	/*node that has to be deleted*/
	
	end = end->prevNode;	/*now end point to end's prevNode*/
	end->nextNode = NULL;	/*end's nextNode will point to NULL because it is last element now*/	
	delete(nodeToDelete);	/*delete the node*/
	
	
	
	
	}
template<class T>
void Doubly_linked_list<T>::deleteFirstNode(){
	/*if linked list is empty*/
	if(front ==  NULL){
		std::cout << "List is empty!" << std::endl;
		return;
		
		}
	
	node *nodeToDelete = new node;
	/*if memory is full and cannot allocate space for nodeToDelete node*/
	if(nodeToDelete == NULL){
		std::cout << "Failed to allocate memory!" << std::endl;
		}
	nodeToDelete = front;
	
	front = front->nextNode;
	front->prevNode = NULL;
	
	delete(nodeToDelete);
	
	
	
	}
template<class T>
void Doubly_linked_list<T>::deleteAtPosition(int pos){
	/*if linked list is empty*/
	if(end == NULL){
		std::cout << "List is empty!" << std::endl;
		}
	
	node *currentNode = new node;	/*current node var to use during iteration*/
	currentNode = front;	/*currentNode will start from front*/
	
	/*iterate to position,where element needs to be deleted*/
	for(int i = 0;i < pos-1;i++){
		/*override the currentNode value to its next node*/
		currentNode = currentNode->nextNode;
		/*if during iteration, loop reaches end*/
		if(currentNode == end){
			std::cout << "Failed to delete at position " << pos << " because index does not exist!" << std::endl;
			return;
			}
		
		}
	/*if first element has to be deleted*/
	if(currentNode->prevNode == NULL){
		front = currentNode->nextNode;	/*front element is now the nextNode of front element,as front is removed so second
		element is now first*/
		front->prevNode = NULL;	/*and first element's prevNode always points towards NULL*/
		}
		/*if last element has to be deleted*/
	else if(currentNode->nextNode == NULL){	
		end = currentNode->prevNode;	/*as last element is deleted, end node is second last element */
		end->nextNode = NULL;	/*last node's nextNode will always point to NULL */
		
		}
		/*if element is at some positions */
		else{
			currentNode->prevNode->nextNode = currentNode->nextNode;	/*currentNode has to be deleted so, it's prevNode will
			point to nextNode of current node
			*/
			currentNode->nextNode->prevNode = currentNode->prevNode;	/*and nextNode of currentNode has to point to prevNode of
			currentNode
			*/
			
			}
	delete(currentNode);	/*delete node*/
	
	}
template<class T>
void Doubly_linked_list<T>::sort(){
	node *currentNode = new node;	/*to hold the curret node*/
	node *index = new node;	/*to hold index of current element to compare*/
	currentNode = front;	/*iteration starts from front*/
	int temp;	/*temp var for temporary swap*/
	
	/*if linked list is empty*/
	if(front == NULL){
		std::cout << "List is empty!" << std::endl;
		}
	/*logic of bubble sort*/
	while(currentNode->nextNode != NULL){
		index = currentNode->nextNode;
		/*take address of currentNode and compare them with every node of linked list*/
		while(index != NULL){
			/*if current element is smaller than after element */
			if(currentNode->data > index->data){
				/*swap value of variable*/
				temp = currentNode->data;	
				currentNode->data = index->data;
				index->data = temp;
			}
			index = index->nextNode;	/*move ahead to next node*/
		}
		
		currentNode = currentNode->nextNode;	/*move ahead to next node*/
		}
	
	}
template<class T>
void Doubly_linked_list<T>::merge(Doubly_linked_list dll){
	
	if(front == NULL or dll.front == NULL){
		std::cout << "Linked list is empty!" << std::endl;
		return;
		}
	
	dll.front->prevNode = end;	/*change the given linked list's front node's prevNode to point towards current linked list's
	end, so they can join
	*/
	end->nextNode = dll.front;	/*now join end's nextNode to given linkedlist's front which was before NULL*/
	/*now connection is made between the 2 linked list*/
	
	end = dll.end;/*now override end with the end of given linkedlist,because length is increased as well*/

	
	
	}
