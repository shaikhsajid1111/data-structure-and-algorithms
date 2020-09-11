#include<iostream>
#ifndef MAX
#define MAX 1000
#endif

template<typename T>
class Queue{
	int first = -1;
	int last = -1;
	T array[MAX];
public:
	Queue(){
		/*-1 represents that queue is empty*/
		first = -1;
		last = -1;
	}
	Queue(T value){

		array[++last] = value;
		first++;
		}
	void enqueue(T value);	/*method to add element to queue*/
	void dequeue();	/*method to delete element of queue*/
	void printThis();	/*method traverse queue*/


	/* Structure
	FIFO(first in first out)
		  ____Dequeue(Removing element)			
	 ___ | _____
	|			|------->Front = first
	| Data - 1	|
	|___________|
	| Data - 2	|
	|___________|
	| Data - 3	|		
	|____   ____|	-->Back = last
		  |	
		  |____Enqueue(Inserting element)
	*/

};

int main(int argc, char const *argv[])
{
	Queue<char> queue('s');
	//queue.enqueue('s');
	queue.enqueue('a');
	queue.enqueue('j');
	queue.enqueue('i');
	queue.enqueue('d');
	
	//queue.dequeue();
	//queue.dequeue();
	//queue.dequeue();
	
	queue.printThis();
	return 0;
}

template<typename T>
void Queue<T>::enqueue(T value){
	/*if queue is already empty*/
	if(first == -1){
		first++;				
	}
	array[++last] = value;	/*insert element at the last+1 position*/
	/*
	Demonstration:
		  
	 ___________
	|			|------->Front = first variable will be increased by 1
	| 			|
	|___________|
	| 			|
	|___________|
	| Data - 1	|	-->data will move up as new data is being entered	
	|____   ____|	-->Back = last
		  |	
		  |____Enqueued(Inserted element) - so, last will be incremented once 
	


	*/
}
template<class T>
void Queue<T>::dequeue(){
	/*Dequeue is the process of removing one element from the queue, in Queues, we remove element from the bottom
	as per the rule of FIFO*/
	if(first == -1){
		std::cout << "Queue is empty!" << std::endl;
		return;
		}
	first++;	/*move first ahead to next element and first element will be skipped,resulting in deleteion of first element*/
}
template<class T>
void Queue<T>::printThis(){
	if(first != -1){
		for(int i = first;i <= last;i++){
			std::cout << array[i] << std::endl;
		}
	}
}
