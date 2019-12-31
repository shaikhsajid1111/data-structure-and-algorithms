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

}
void Queue::dequeue(){
	if(first == -1){
		std::cout << "Empty!" << std::endl;
		return;
	}
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