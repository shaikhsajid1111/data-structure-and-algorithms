#include<iostream>
#include<cstdlib>

int *insertion_sort(int arr[],int size);
void printArray(int arr[],int size);
int main(int argc, char const *argv[])
{
	int arr[5] = {5,8,9,0,4};
	
	insertion_sort(arr,5);
	printArray(arr,5);
	/*output : 2,3,4,5,8*/
	system("pause");
	return 0;
}
int *insertion_sort(int arr[],int size){
	/*iterate from 1 - length of array*/
	/*logic:
	arr = {5,4,3,2,1} -> 
	start from 1 till the last index of array
	1) position is greater than 0? and [position-1] i.e value before this position in 
	array is greater than the current?,{5,4,3,2,1}, arr[1] and arr[0] > 4. So condition is true 
		
		if both condition are true than,
		replace current position[value] with the previous one[value], -> {5,5,3,2,1}
		so, index will be decremented by 1, so it becomes 0, so while loop will terminate
		arr[0] = current_value; which is 4. So array becomes {4,5,3,2,1}
		
		
	*/
	for(int index = 1;index < size;index++){
		int current_value = arr[index];			//index's value in array
		int position = index;				//current index
		while(position > 0 & arr[position-1] > current_value){	/*if position is <1 and previous position is larger number*/
			arr[position] = arr[position-1];				/*copy the larger one to the previous value*/
			position--;							
		}		
		arr[position] = current_value;
	}
	return arr;
	
}
void printArray(int arr[],int size){
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
}


/*
void insertion_sort(int arr[],int size){
	for(int i = 1;i < size;i++){
		int value_to_be_sorted = arr[i];	/*value of array,starts iterating from 0*/
		/*int j = i;			/*iterator*/
		/*while(j > 0 && arr[j-1] > value_to_be_sorted){	/*while j is greater than 0 and previous value is greater than the after*/
		/*	arr[j] = arr[j-1];			/*swap elements,e.g if 6,5 than it follows logic that it'll become it'll become 5,5*/
		/*	j -= 1;
		}
		arr[j] = value_to_be_sorted;	/*after coming out of iteration, the next value is again 5,6*/
	/*}
}*/
/*
array = {5,4,2,3,8};
iteration 1:
i = 1
value_to_be_sorted = 4,because a[1] = 4
j = 1
1 > 0 and 5 > 4
so, arr[1] = 5 and after iteration - arr[0] = 4

after 1 iteration - {4,5,2,3,8}

iteration 2:
i = 2
value_to_be_sorted = 2,because a[2] = 2
j = 2
arr[j-1] = arr[1] = 5
2 > 0 and 5 > 4
so, arr[2] = 2 and after iteration - arr[0] = 4

after 2 iteration - {4,2,5,3,8}

*/
