#include <iostream>
#include<cstdlib>
#include<stdexcept>
using namespace std;
template <class T> class dynamicArray{
private:
	T arr[];
	unsigned int len = 0;	//length user thinks
	unsigned int capacity = 0;	//actual array size

public:
	/*constructors*/
	dynamicArray(){
		this->capacity = 16;
	}
	dynamicArray(int capacity){
		this->capacity = capacity;
		arr = (T[]) new dynamicArray[capacity];
	}

	int size();
	bool isEmpty();
	T get(int index);
	void set(int index,T elem);
	void clear();
	void add(T elem);
	T removeAt(int rm_index);
	bool remove(dynamicArray obj);

	int indexOf(dynamicArray obj);
	bool containc(dynamicArray obj);
};

int main(int argc, char const *argv[])
{

	system("pause");
	return 0;
}
template<class T>//
//			^^^^
int dynamicArray<T>::size(){
	return len;
}
template <class T>
bool dynamicArray<T>::isEmpty(){
	return size == 0;
}
template <class T>
T dynamicArray<T>::get(int index){
	return arr[index];
}
template <class T>
void dynamicArray<T>::set(int index,T elem){
	arr[index] = elem;
}

template <class T>
void dynamicArray<T>::clear(){
	for (int i = 0; i < len; ++i)
	{
		arr[i] = '\0';
	}
	len = 0;
}
template <class T>

void dynamicArray<T>::add(T elem){
	if (len + 1 >= capacity)
	{
		if (capacity == 0)
		{
			capacity = 1;
		}
		else{
			capacity *= 2;
		}
	}


	T new_arr[] = (T[]) new dynamicArray[capacity];

	for (int i = 0; i < len; ++i)
	{
		arr[new_arr];
	}

	arr[len++] = elem;
}
template<class T>
T dynamicArray<T>::removeAt(int rm_index){
	if(rm_index >= len || rm_index < 0) throw new std::out_of_range("Index out of bound!");
	T data = arr[rm_index];

	T new_arr[] = (T[]) new dynamicArray[len-1];



}