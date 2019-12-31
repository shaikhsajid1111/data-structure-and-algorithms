#include<iostream>
#include<cstdlib>
#define MAX 1000

/*stack class*/
class Stack{
	int top;	
public:
	int array[MAX];
	Stack(){
		top = -1;

	}

	/*Stack's method*/
	bool push(int value);
	bool pop();
	int peek();
	bool isEmpty();
	int getTop();
};

void traverseStack(Stack object);

int main(int argc, char const *argv[])
{
	Stack stack;
	for(int i = 0;i < 20;i++){
		stack.push(i + 1);
	}
	traverseStack(stack);
	system("pause");
	return 0;
}
/*Stack function defintion*/
bool Stack::push(int value){
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
bool Stack::pop(){
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
int Stack::peek(){
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
bool Stack::isEmpty(){
	/*if top is less than 0, it is empty*/
	return (top < 0);
}
int Stack::getTop(){
	return top;
}

void traverseStack(Stack object){
	int i = 0;
	/*iterating over the stack's array*/
	while(i < object.peek()){
		std::cout << object.array[i] << std::endl;
		i++;
	}
}