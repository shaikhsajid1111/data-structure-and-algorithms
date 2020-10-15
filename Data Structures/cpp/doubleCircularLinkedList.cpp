#include<iostream>

/*class to implement double circular linked list*/
template<typename T>
class doubleCircularLinkedList{
	/*structure of node of linked list*/
	struct node{
		T data;
		node *prevNode;	/*contains previous address of node*/
		node *nextNode;	/*contains next address of node*/
		};
		node *head,*tail;	/*head is to store first element of linked list while tail is for address of last element*/
		public:
		
		/*constructor if class is init with empty values*/
		doubleCircularLinkedList(){
			head = NULL;	/*by default is not value is there than head and tail will be NULL*/
			tail = NULL;
			
			}
		/*if class is init with a value*/
		doubleCircularLinkedList(T value){
			node *temp = new node;	/*allocate memory for new node*/
			temp->data = value;	/*assign value to respective new node*/
			
			temp->nextNode = temp;	/*temps's nextNode will point to itself because it is first node*/
			temp->prevNode = temp;	/*temps's nextNode will point to itself because it is last node as well*/
			
			head = tail = temp;	/*if only one element is present than head and tail should point to same element as well*/
			
			}
		void traverseForward();	/*method to traverse linked list in forward direction*/
		void traverseBackward();	/*method to traverse linked list in backward direction*/
		
		void insert(T);	/*method to insert node at the end of linked list*/
		void insertAtFront(T);	/*method to insert node at the front of linked list*/
		void insertAtPosition(T,int);/*method to insert node at given position of linked list*/
		
		void deleteLastNode();	/*method to delete node at the end of linked list*/
		void deleteFirstNode();	/*method to delete node at the front of linked list*/
		void deleteAtPosition(int pos);/*method to delete node at the given position of linked list*/
	
		bool exists(T value);	/*method to search node in linked list*/
		int search(T value);	/*method to search node in linked list and return position of element*/
	
	};


int main(int argc,char const **argv){
	
	doubleCircularLinkedList<int> dcll(123);
	dcll.insert(10);
	dcll.insert(100);
	dcll.insert(1000);
	dcll.insert(105);
	dcll.insert(10000);
	dcll.insertAtFront(25);
	std::cout << dcll.search(45454) << std::endl;
	 
	dcll.traverseForward();
	return 0;
	
	}

template<class T>
void doubleCircularLinkedList<T>::insert(T value){
		node *newNode = new node;	/*allocate new node*/
		/*if memory allocation failed*/
		if(newNode == NULL) {
			std::cout<< "Cannot allocate memory!" << std::endl;
			}
			
		newNode->data = value;	/*assign value to respective data member*/
		
		/*if linked list is empty*/
		if(head == NULL && head == tail){
			/*head,tail,newnNode's nextNode and newNode's preNode will point towards newNode because it is the 
			only preset element*/
			head = tail = newNode->nextNode = newNode->prevNode = newNode;
	
			}
		else{
			/*join newNode to linked list*/
			newNode->prevNode = tail;	/*newNode's prevNode will be previous tail that had been stored*/
			newNode->nextNode = head;	/*now newNode is last element so it will point to head element*/
			
			tail->nextNode = newNode;	/*and tail will be pointing its nextNode to newNode*/
			head->prevNode = newNode;	/*head's prevNode points to last element,so now newNode is last element*/
			
			tail = newNode;	/*now newNode is last element so,tail will be newNode*/
			
			}
}

template<class T>
void doubleCircularLinkedList<T>::traverseForward(){
		node *temp = new node;
		temp = head;	/*starts from head*/
		/*iterate until we reach head again*/
		while(temp->nextNode != head){
			std::cout << temp->data << std::endl;
			temp = temp->nextNode;	/*move one element ahead*/
			}
	std::cout << temp->data << std::endl;
}

template<class T>
void doubleCircularLinkedList<T>::traverseBackward(){
	node *temp = new node;
	temp = tail;/*starts from end*/
		/*iterate until we reach end again*/
	while(temp->prevNode != tail){
		std::cout << temp->data << std::endl;
		temp = temp->prevNode;
		}
	std::cout << temp->data << std::endl;
	
	}
template<class T>
void doubleCircularLinkedList<T>::insertAtFront(T value){
	node *newNode = new node;	/*allocate memory*/
	/*if memory allocation failed*/
	if(newNode == NULL){
		std::cout<<"Cannot allocate memory!" << std::endl;
		return;
 	}
	 /*assign value to data member*/
	newNode->data = value;	
	/*by default set prevNode and nextNode to NULL*/
	newNode->nextNode = newNode->prevNode = NULL;
	
	/*if list is empty*/
	if(head == NULL && head == tail){
		std::cout << "List is empty!" << std::endl;
		return;
		}
	
	newNode->nextNode = head;	/*join newNode to head,as head was first element and newNode has to take
	place of head
	*/
	newNode->prevNode = tail;	/*and as newNode is now first element,it should point to tail now*/
	
	/*tail's nextNode will point to new first element that is newNode and head's prevNode to newNode as now
	newNode is first element and first element becomes second element*/
	tail->nextNode = head->prevNode = newNode;		
	/*finally head is now newNode that completes the joining process of element to front*/
	head = newNode;
	
	}

template<class T>
void doubleCircularLinkedList<T>::deleteLastNode(){
	/*if list is already empty*/
	if(tail == NULL){
		std::cout << "List is empty!" << std::endl;
		return;
		}
	
	node *nodeToDelete = new node;
	if(nodeToDelete == NULL){
		std::cout << "Failed to allocate memory!" << std::endl;
	}
	nodeToDelete = tail;	/*last element has to be deleted,so temporarily storing it in nodeToDelete var*/
	tail->prevNode->nextNode = head;	/*tail's prevNode of nextNode is now pointing to head*/
	
	tail = tail->prevNode;	/*now tail is second last element*/
	head->prevNode = tail;	/*now head prevNode is even poiting to tail*/
	
	delete(nodeToDelete);	/*deallocate memory*/
	}

template<class T>
void doubleCircularLinkedList<T>::deleteFirstNode(){
	/*if list is empty*/
	if(head == NULL){
		std::cout << "List is empty!" << std::endl;
		return;
		}
	node *nodeToDelete = new node;
	/*if failed to allocate memory*/
	if(nodeToDelete == NULL){
		std::cout << "Failed to allocate memory!" << std::endl;
	}

	nodeToDelete  = head;	/*temporarily hold the element of front side of linked list so we can delete it later*/
	
	head->nextNode->prevNode = tail; /*second element points to tail*/
	head->prevNode = tail;	/*second node of linked list head's prevNode points to tail*/
	head = head->nextNode;	/*move head to second element as first element will be deleted*/
	
	tail->nextNode = head;	/*as we have to delete the first node,tail also should point to second element*/
	/*now first element is removed from linked list so we can delete it*/
	delete(nodeToDelete);
	
	}
template<class T>
void doubleCircularLinkedList<T>::insertAtPosition(T value,int pos){
	node *newNode = new node;
	
	node *currentNode = new node;	/*node to keep address of current iteration for replacing nodes*/
	/*if list is empty*/
	if(newNode == NULL or currentNode == NULL){
		std::cout << "Unable to allocate memory!" << std::endl;
		return;
		}
	newNode->data = value;	/*assign data to newNode*/
	currentNode = head;	/*start iteration from head node*/
	/*loop to the position,where we have to insert node*/
	for(int i = 0;i< pos-1;i++){
		/*if currentNode reaches end position is not reached*/
		if(currentNode == tail){
			std::cout << "Index not found!" << std::endl;
			return;
			}
		currentNode = currentNode->nextNode;	/*move one node ahead*/
		}
	newNode->prevNode = currentNode->prevNode;	/*connect newNode's prevNode to curretNode's prevNode*/
	newNode->nextNode = currentNode->nextNode;	/*connect current's nextNode to newNode's nextNode*/
	
	currentNode->prevNode->nextNode = newNode;	/*now connect currentNode's previous node's nextNode to newNode as
	to join newNode to its next node*/
	currentNode->nextNode->prevNode = newNode;/*now connect currentNode's previous node's nextNode to newNode as
	to join newNode to its previous node*/
	/*if inserted element was first element*/
	if(currentNode == head){
		head = newNode;
		}
	/*if inserted element was last element*/
	else if(currentNode == tail){
		tail = newNode;
		}
	}
	
template<class T>
void doubleCircularLinkedList<T>::deleteAtPosition(int pos){
		node *currentNode = new node;
		/*if failed to allocate memory*/
		if(currentNode == NULL){
			std::cout<< "Failed to allocate memory!" << std::endl;
			return;
		}
		currentNode = head;	/*start iterating from head*/
		/*move to position where we have to delete node from*/
		for(int i = 0;i< pos-1;i++){
			/*if current node is last element*/
			if(currentNode == tail){
				std::cout<< "Index out of bound!" << std::endl;
				return;
				}
			currentNode = currentNode->nextNode;	/*move ahead to next node*/
			}
			
		currentNode->nextNode->prevNode = currentNode->prevNode;	/*join the nextNode to of current element to its one node
		ahead*/
		currentNode->prevNode->nextNode = currentNode->nextNode;	/*join nextNode of prevNode to one node ahead*/
		/*if first node was deleted from linked list*/
		if(currentNode == head){
			head = currentNode->nextNode;	/*head should point to next node of deleted element*/
			tail->nextNode = head;	/*now tail changes it nextNode pointer to point towards one node ahead of first node*/
			}
		/*if last node was deleted from linked list*/
		else if(currentNode == tail){
			tail = currentNode->prevNode;/*tail should point to next node of deleted element*/
			head->prevNode = tail;/*now head changes it prevNode pointer to point towards one node behind of last node*/
			}
		delete(currentNode);
		
		
		 
}

template<class T>
bool doubleCircularLinkedList<T>::exists(T value){
	node *traverser = new node;	/*to traverse entire linked list*/
	/*if failed to allocate memory*/
	if(traverser == NULL){
		std::cout << "Failed to allocate memory!" << std::endl;
		return;
	}
	traverser = head;
	/*traverse through entire linked list and return true if element is found*/
	do{
		if(traverser->data == value){
			return true;
			}
		traverser = traverser->nextNode;	
		
		}while(traverser->nextNode != head);

	return false;
	}
template<class T>
int doubleCircularLinkedList<T>::search(T value){
	int count = 0;
	node *temp = new node;
	/*if failed to allocate memory*/
	if(temp == NULL){
		std::cout << "Failed to allocate memory!" << std::endl;
		return;
	}
	temp = head;	/*start traversing from head*/
	/*while it does not reaches head after iterating,increment count on each fail attempts*/
	while(temp->nextNode != head){
		if(temp->data == value){
			return count;
			}
		temp = temp->nextNode;
		count++;
		}
		/*if element was not found,return -1*/
		return -1;
	
	
	}
