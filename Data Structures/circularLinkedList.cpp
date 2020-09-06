#include<iostream>
#include<cstdlib>

template<typename T>
class circularLinkedList{
	private:
	struct node{
		T data;
		node *nextNode;
		};
	
	node *head;
	
	
	public:
		/*default construvtor*/
		circularLinkedList(){
			head = NULL;
			}
		circularLinkedList(T value){
			node *temp = new node;	/*create a mode*/
			temp->data = value;	/*assign value to node's member*/
			head = temp;	/*now head is temp, because temp is the only member first and last at the same time*/
			temp->nextNode = head;	/*now temp's nextNode should point to head as it is the first node*/
		
		}
	void insert(T value);	
	void display();
	
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
	cll.display();
	system("pause");
	return 0;
	}

template <class T>
void circularLinkedList<T>::insert(T value){ 
	
	node *temp = new node;	/*allocate space for new node*/
    temp->data = value;	/*assign value to data member in node*/
    /*if linkedlist does not have any node*/
    if (head == NULL){			
        head = temp; /*assign head to temp,because temp is first and last element. so,head will be pointing to temp*/
        temp->nextNode = head;  /*as temp is last node, it will point to first node of linkedlist. Basically pointing towards itself*/
    }
    else{
		/*if node is already presents in linked list*/
        temp->nextNode = head->nextNode;	/*temp will be last element of linked list, so temp should point to head's nextNode*/ 
        head->nextNode = temp;	/*head points to last element as well*/	
        head = temp;	/*now temp is last node*/


    }


}

template <class T>
void circularLinkedList<T>::display(){
	node *temp = new node;
	
	temp = head;
	
	do{
		std::cout << temp->data << std::endl;
		temp = temp->nextNode;
		
		}while(temp != head);
	}
