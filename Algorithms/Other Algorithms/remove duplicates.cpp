#include<iostream>
#include<cstdlib>


int *insertion_sort(int arr[],int size);
int removeDuplicate(int arr[],int size);


int main(int argc, char const *argv[])
{
	int arr[] = {1,2,2,3,3,4,5,6,7};
	int size = sizeof(arr) / sizeof(arr[0]);
	removeDuplicate(arr,size);
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << std::endl;
	}
	system("pause");
	return 0;
}
int *insertion_sort(int arr[],int size){
	for(int i = 1;i < size;i++){
		int current_value = arr[i];
		int position = i;
		while(position > 0 & arr[position-1] > current_value){
			arr[position] = arr[position-1];
			position--;
		}

		arr[position] = current_value;
	}
	return arr;
}
int removeDuplicate(int arr[],int size){
	if (size <= 1)
	{
		return size;
	}
	arr = insertion_sort(arr,size);
	int temp[size];
	int j = 0;
	for (int i = 0; i < size-1; ++i)
	{
		if(arr[i] != arr[i+1]){
			temp[j++] = arr[i];
		}
		temp[j++] = arr[size-1];
	}
	for (int index = 0; index < j; ++index)
	{
		arr[index] = temp[index];
	}
	return j;
}