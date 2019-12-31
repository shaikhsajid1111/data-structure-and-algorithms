#include<iostream>
#include<cstdlib>

void bubble_sort(int arr[],int size);


int main(int argc, char const *argv[])
{
	int arr[20] = {5,4,7,89,5,6,4,10,1,2,3,5,4,67,99,888,85,8,9,20};
	int length = sizeof(arr)/sizeof(int);
	bubble_sort(arr,20);
	for(int i =0;i < length;i++){
		std::cout << arr[i] << ",";
	}
/*output : 1,2,3,4,4,4,5,5,5,6,7,8,9,10,20,67,85,89,99,888*/
	system("pause");
	return 0;
}
void bubble_sort(int arr[],int size){	/*expected parameters are array and it's length or size*/

	for(int i = 0;i < size-1;i++){ /*loop from 0 - length -1 of array index*/
		
		for(int j = i+1;j < size;j++){			/*loop from i+1 i.e 1 - length of array*/
			
			if(arr[i] > arr[j]){			/*if arr[i] number is greater than arr[j], i.e previous value is greater than after*/
					/*swap place*/
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}