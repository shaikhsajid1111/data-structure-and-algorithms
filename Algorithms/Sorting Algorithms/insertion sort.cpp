#include<iostream>
#include<cstdlib>

void insertion_sort(int arr[],int size);

int main(int argc, char const *argv[])
{
	int arr[5] = {5,4,2,3,8};
	insertion_sort(arr,5);
	for(int i = 0;i < 5;i++){
		std::cout << arr[i] << ","; 
	}	
	/*output : 2,3,4,5,8*/
	system("pause");
	return 0;
}
void insertion_sort(int arr[],int size){
	for(int i = 1;i < size;i++){
		int value_to_be_sorted = arr[i];	/*value of array,starts iterating from 0*/
		int j = i;			/*iterator*/
		while(j > 0 && arr[j-1] > value_to_be_sorted){	/*while j is greater than 0 and previous value is greater than the after*/
			arr[j] = arr[j-1];			/*swap elements,e.g if 6,5 than it follows logic that it'll become it'll become 5,5*/
			j -= 1;
		}
		arr[j] = value_to_be_sorted;	/*after coming out of iteration, the next value is again 5,6*/
	}
}
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