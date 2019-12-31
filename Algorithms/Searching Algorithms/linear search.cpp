#include<iostream>
#include<cstdlib>

int linear_search(int arr[],int size,int value);

int main(int argc, char const *argv[])
{
	int arr[5] = {1,5555,66,88,9};
	std::cout << linear_search(arr,5,5555) << std::endl;

	/*return 1*/
	system("pause");
	return 0;
}

int linear_search(int arr[],int size,int value){	/*parameters = array,length of array,value to find*/
	for(int i = 0;i < size;i++){			/*loop iterating from 0 to last length of array*/
		if(arr[i] == value){		/*if array[i] is equals to value*/
			return i;				/*returns i as a position*/
		}
	}	
	return -1;			/*returns -1 if value is not there in array*/
}