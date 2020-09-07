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
	void insert(T value);	
	void display();
	void addAtFront(T value);
	void addAtPosition(int pos,T value);
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
	cll.addAtPosition(2,22);
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
		newNode->nextNode = last->nextNode;	/*temp will be last element of linked list, so temp should point to last's nextNode*/ 
        last->nextNode = newNode;	/*last points to last element as well*/	
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
void circularLinkedList<T>::addAtPosition(int pos,T value){
	if(last == NULL){
		std::cout << "List is empty!" << std::endl;
		return;
	}
	
	node *newNode = new node;
	node *iter = new node;
	
	iter = last->nextNode;
	
	for(int i =0;i < pos-1;i++){
		iter = iter->nextNode;
		
		if(iter == last->nextNode){
			std::cout << "Only " << pos << "in list" << std::endl;
			return;
		}
		
		newNode->nextNode = iter->nextNode; /*Join newNode to its next element*/
		newNode->data = value;	/*assign data to newNode*/
		iter->nextNode = newNode;	 /*join current's node back node to newNode*/
		
		}
		/*if position was last position of linked list*/
		if(iter == last){
			last = newNode;	/*last element is now current element*/
			}
	
	
	

}
