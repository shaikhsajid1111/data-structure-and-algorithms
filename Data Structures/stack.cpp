#include<iostream>
#include<cstdlib>
#define MAX 1000

/*stack class*/
template<typename T>
class Stack{
	int top = -1;	
public:
	T array[MAX];
	Stack(){
		top = -1;

	}
	Stack(T value){
		array[++top] = value;
	
		}

	/*Stack's method*/
	bool push(T);
	bool pop();
	int peek();
	bool isEmpty();
	int getTop();
	void traverse();
	

};



int main(int argc, char const *argv[])
{
	
	Stack<int> stack(4);
	stack.push(5);
	stack.push(6);
	
	stack.push(7);

	stack.traverse();
	
	
	return 0;
}
/*Stack function defintion*/
template<class T>
bool Stack<T>::push(T value){
	/*push function of stack is use for inseting value in stack*/
	/*checking if stack is already full or overflowing*/
	if(top >= (MAX-1)){				/*if content of top variable is bigger than equals to 999, because array limit is 1000*/
		std::cout << "Stack Overflow!" << std::endl;		
		return false;						/*responding error for the following request*/
	}
	else{
		/*else, first indexing of top incrementation, and sending value to the array*/
		array[++top] = value;				/*array[pre incrementing, top] and assigning the value to the array*/
		return true;			/*returning success*/
	}
}
template<class T>
bool Stack<T>::pop(){
	/*pop removes the last value from the stack*/
	/*checking if, stack is empty*/
	if(top < 0){				/*if top == -1, than stack is empty. -1 in stack represents that stack is empty*/
		std::cout << "Stack Underflow!" << std::endl;
		return false;				/*responding error*/
	}
	else{
		/*if stack has some values in it*/
		array[--top];			/*deleting the content from stack, as reducing the value of top*/
		return true;		/*returning success*/
	}

}
template<class T>
int Stack<T>::peek(){
	/*peek function lets you have a look at the current value of stack*/
	/*if top is not equals to -1*/
	if(top < 0){
		std::cout << "Stack Underflow!" << std::endl;
		return 0;
	}
	else{
		/*returns current value*/
		return array[top];
	}
}
template<class T>
bool Stack<T>::isEmpty(){
	/*if top is less than 0, it is empty*/
	return (top < 0);
}
template<class T>
int Stack<T>::getTop(){
	return top;
}
template<class T>
void Stack<T>::traverse(){
	int i = 0;
	/*iterating over the stack's array*/
	do{
		std::cout << array[i] << std::endl;
		i++;
	}while(i <= top);
}
