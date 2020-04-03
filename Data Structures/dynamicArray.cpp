#include <iostream>
#include<cstdlib>
#include<stdexcept>
using namespace std;
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
	bool remove(dynamicArray obj);

	int indexOf(dynamicArray obj);
	bool contains(dynamicArray obj);
};

/*main function*/
int main(int argc, char const *argv[])
{
	dynamicArray<int> arr;
	//arr.add(1);
	arr.add(5);
	arr.add(45);
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	

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
	if(rm_index >= len || rm_index < 0) throw new std::out_of_range("Index out of bound!");
	T data = arr[rm_index];

	T new_arr[len-1];

	for (int i = 0; i < len; ++i)
	{
		if (rm_index == i)
		{
			continue;
		}
		else{
			new_arr[i] = arr[i];
		}
	}
	arr = new_arr;
	capacity = --len;
	return data;

}
template <class T>
bool dynamicArray<T>::remove(dynamicArray obj){
	int index = indexOf(obj);
	if (index == -1)
	{
		return false;
	}
	removeAt(index);
	return true;
}
template<class T>
int dynamicArray<T>::indexOf(dynamicArray obj){
	for (int i = 0; i < len; ++i)
	{
		if (obj == NULL)
		{
			if (arr[i] == NULL)
			{
				return i;
			}
			else{
				if(obj.equals(arr[i])){
					return i;
				}
			}
		}
	}
	return -1;
}
template <class T>
bool dynamicArray<T>::contains(dynamicArray obj){
	return indexOf(obj) != -1;
}