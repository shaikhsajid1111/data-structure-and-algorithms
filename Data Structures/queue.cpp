#include<iostream>
#ifndef MAX
#define MAX 1000
#endif

class Queue{
	int first,last,array[MAX];
public:
	Queue(){
		/*-1 represents that queue is empty*/
		first = -1;
		last = -1;
	}
	void enqueue(int value);
	void dequeue();
	void printThis();


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
	Queue queue;
	queue.enqueue(2);
	queue.enqueue(5);
	queue.printThis();
	return 0;
}
void Queue::enqueue(int value){\
	/*if queue is already empty*/
	if(first == -1){
		first++;				
	}
	array[++last] = value;	/*insert value at increment value of last variable*/
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
void Queue::dequeue(){
	/*Dequeue is the process of removing one element from the queue, in Queues, we remove element from the bottom
	as per the rule of FIFO*/
	if(first == -1){		/*if the first value is empty itself, queue is empty*/
		std::cout << "Empty!" << std::endl;
		return;
	}
	/*for maintaining Queue, it is necessary that start and last count should be equals*/
	if(first == last){
		first = -1;
		last = -1;
		return;
	}
	first++;
}
void Queue::printThis(){
	if(first != -1){
		for(int i = first;i <= last;i++){
			std::cout << array[i] << std::endl;
		}
	}
}