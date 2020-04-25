#include <iostream>
#include<cstdlib>
#include<stdexcept>

template <typename T> class dynamicArray{
private:
	
	unsigned int len = 0;	//length user thinks
	unsigned int capacity = 0;	//actual array size
	T *arr = new T;

public:
	/*constructors*/
	dynamicArray(){
		capacity = 2;
	}
	
	int size();
	bool isEmpty();
	T get(int index);
	void set(int index,T elem);
	void clear();
	void add(T elem);
	T removeAt(int rm_index);
	bool remove();

	int indexOf(T elem,int start = 0);
	void traverse();
	
};

/*main function*/
int main(int argc, char const *argv[])
{
	/*dynamicArray<int> arr;
	for (int i = 0; i < 10; ++i)
	{
		arr.add(i);
	}
	arr.removeAt(5);
	cout << arr.get(5) << endl;
	cout << arr.size();
	for (int i = 0; i < 10; ++i)
	{
		cout << arr.get(i) << endl;
	}
	arr.clear();
	cout << "GEt" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << arr.get(i) << endl;
	}*/
	dynamicArray<double> arr;

	//std::cout << arr.isEmpty();
	for (int i = 0; i < 150; ++i)
	{
		arr.add(i + 3);
	}
	arr.traverse();
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
	return len == 0;
}
template <class T>
T dynamicArray<T>::get(int index){
	/*get element according to index given*/
	return arr[index];
}
template <class T>
void dynamicArray<T>::set(int index,T elem){
	/*set element to particular index in the array, it replaces the previous value with the given one
	*/
	arr[index] = elem;
}

template <class T>
void dynamicArray<T>::clear(){
	/*make the array NULL*/
	for (int i = 0; i < len+1; ++i)
	{
		arr[i] = '\0';
	}
	len = 0;
}


template <class T>
void dynamicArray<T>::add(T elem){
	/*if the capacity is less tnan increase it by x2 */
	if (len + 1 > capacity)
	{
		if (capacity == 0)
		{
			capacity += 1;
		}
		else{
			capacity *= 2;
		}
	}

	//cout << capacity << endl;
	T *new_arr;
	new_arr = new T[capacity];
	for (int i = 0; i < len; ++i)
	{
		/* copy the value from array to new array */
		new_arr[i] = arr[i];
	}
	/*adding the last value*/
	new_arr[len++] = elem;
	arr = new_arr;
	
	
 }


template<class T>
T dynamicArray<T>::removeAt(int rm_index){
	/*
	given index, delete element at the given position

	*/
	//if index is greater than length or negative
	if(rm_index >= len || rm_index < 0) 
		//throws indexOutOfBoundException
		throw new std::out_of_range("Index out of bound!");
	T data = arr[rm_index];				/*value of array at this index*/
	/*array which is 1 value smaller than the actual array*/
	/*creating new array with 1 element less space for element*/
	T *new_arr = new T[len-1];

	int j = 0;
	for(int i = 0; i < len; i++){
  	/*if i matches the removed index*/
  	if(i == rm_index){
    	continue;
  	}
  		new_arr[j] = arr[i];
  		j++;
	}
	arr = new_arr;	/*copy*/
	capacity = --len;
	return data;

}
template <class T>
bool dynamicArray<T>::remove(){
	/*removes the last element*/
	arr.removeAt(len);
	return true;
}
template<class T>
int dynamicArray<T>::indexOf(T elem,int start){
	/*searching for element, start provides the start position from where
	we have to start findding the element in the array*/
	for (int i = start; i < len; ++i)
	{
		/*if given element matches in given array*/
		if (arr[i] == elem)
		{
			/*retruns the position*/
			return i;
		}
	}
	/*if element was not present, it will return -1*/
	return -1;
}
template <class T>
void dynamicArray<T>::traverse(){
	if (len == 0)
	{
		std::cout << "Array is empty!" << std::endl;
	}
	for (int i = 0; i < len; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}