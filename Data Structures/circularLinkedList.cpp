#include<iostream>
#include<cstdlib>

template<typename T>
class circularLinkedList{
	private:
	struct node{
		T data;
		node *nextNode;
		};
	
	node *last;	/*stores the address of the first node of linked list*/
	
	
	public:
		/*default construvtor*/
		circularLinkedList(){
			last = NULL;
			}
		circularLinkedList(T value){
			node *temp = new node;	/*create a mode*/
			temp->data = value;	/*assign value to node's member*/
			last = temp;	/*now last is temp, because temp is the only member first and last at the same time*/
			temp->nextNode = last;	/*now temp's nextNode should point to last as it is the first node*/
		
		}
	void insert(T value);	/*method to insert value into linked list*/
	void display();	/*method to display all content of linked list*/
	void addAtFront(T value);
	void addAfter(int pos,T value);
	void deleteNode(T value);
	int search(T value);
	};




int main(int argc,char const **argv){
	circularLinkedList<int> cll(25);
	cll.insert(10);
	cll.insert(100);
	cll.insert(101);
	cll.insert(102);
	cll.insert(103);
	cll.insert(10);
	cll.insert(9);
	cll.deleteNode(103);
	cll.deleteNode(10);
	cll.deleteNode(101);
	
	cll.display();
	system("pause");
	return 0;
	}

template <class T>
void circularLinkedList<T>::insert(T value){ 
	/*
	 1. Create a node name temp and assign value to it's data members
	 2. if last is NULL already than, assign temp to last
	 3. Assign temp's nextNode member to last
	 4. Else it already had node, temp's nextNode the value of last's nextNode
	 * assign temp to last's nextNode
	 * and assign last the temp 
	 */
	node *newNode = new node;	/*allocate space for new node*/
   
    
    newNode->data = value;	/*assign value to data member in node*/
    /*if linkedlist does not have any node*/
    if (last == NULL){			
        last = newNode; /*assign last to newNode,because temp is first and last element. so,last will be pointing to temp*/
        newNode->nextNode = last;  /*as newNode is first and last node, it will point to first node of linkedlist. Basically pointing towards itself*/
    }
    else{
		/*if node is already presents in linked list*/
		newNode->nextNode = last->nextNode;	/*temp will be last element of linked list, so newNode should point to last's nextNode*/ 
        last->nextNode = newNode;	/*last node points to last element as well*/	
        last = newNode;	/*now temp is last node*/
	

    }


}

template <class T>
void circularLinkedList<T>::display(){
	node *temp = new node;
	
	temp = last;
	
	do{
		std::cout << temp->data << std::endl;
		temp = temp->nextNode;
		
		}while(temp != last);
	}


template<class T>
void circularLinkedList<T>::addAtFront(T value){
		if(last == NULL){
			std::cout << "Linked list is already empty!" << std::endl;
			return;
		}
	node *temp = new node;/*allocate a new node*/
	temp->data = value;	/*enter value into data member*/
	
	temp->nextNode = last->nextNode; /*point temp's
	nextNode to lists first node's nextNode,poiting to first
	 node
	*/
	last->nextNode = temp;	/*last node should always 
	keep track of last node so temp is last node*/
	
}

template<class T>
void circularLinkedList<T>::addAfter(int pos,T value){
	if(last == NULL){
		std::cout << "List is empty!" << std::endl;
		return;
	}
	
	node *newNode = new node;
	node *currentNode = new node;
	
	currentNode = last->nextNode;
	
	for(int i =0;i < pos-1;i++){
		currentNode = currentNode->nextNode;
		
		if(currentNode == last->nextNode){	/*if current node itself matches the first node*/
			std::cout << "Only " << pos << "in list" << std::endl;
			return;
		}
		
		newNode->nextNode = currentNode->nextNode; /*we have address of current node and we have to join this new node to its next node
		so we will point it to simply the nextNode of current's ahead node*/
		newNode->data = value;	/*assign data to newNode*/
		currentNode->nextNode = newNode;	 /*Now current node's next node has been inserted so, it should point to newNode*/
		
		}
		/*if position was last position of linked list*/
		if(currentNode == last){
			last = newNode;	/*last element is now current element*/
			}
	
	
	

}

template <class T>
void circularLinkedList<T>::deleteNode(T value){
	node *temp = new node;	/*temporary node*/
	node *iterator = new node;	/**/
	
	iterator = last->nextNode;
	/*if first element contains only one element and element that has to be deleted*/
	if(last->nextNode == last && last->data == value){
		temp = last;	/*hold the address of element to be deleted*/
		last = NULL;	/*set last to NULL because it is first element*/
		free(temp);	/*free the space*/
		return;
		}
	/*if value matches first element that has to be deleted*/	
	if(iterator->data == value){
		temp = iterator;	/*hold the current iterator*/
		iterator->nextNode = iterator->nextNode; /*move address of previous node to next next node*/	
		free(temp);	/*deallocate memory*/
		return;
			
			}
	/*if element is to deleted from between*/
	while(iterator->nextNode != last){	/*iterate over the linked list*/
		/*if value matches the data of linked list*/
		if(iterator->nextNode->data == value){
			temp = iterator->nextNode;	/*hold the nextNode node address to temp variable*/
			iterator->nextNode = temp->nextNode;	/*move one node ahead and connect it to next node to previous*/
			free(temp);	/*deallocate memory*/
			return;
			
			}
		iterator = iterator->nextNode;	/*iterate ahead to nextNode*/
		}
	/*if element is last element of linkedlist*/
	if(iterator->nextNode->data == value){
		temp = iterator->nextNode;
		iterator->nextNode = last->nextNode;
		free(temp);
		last = iterator;	/*now second last element is last*/
		}
}
template<class T>
int circularLinkedList<T>::search(T value){
		
		node *temp = new node;
		int counter = 0;
		temp = last->nextNode;	/*assign first node value to temp*/
		
		/*traversing the linked list*/
		while(temp != last){/*while temp does not reach last element*/
			counter++;	/*increment by 1*/
			if(temp->data == value){	/*if it matches,than return counter which tells the position*/
				return counter; 
				} 
				temp = temp->nextNode; /*move ahead to next node*/
			};
			
			return false;
	
	}
