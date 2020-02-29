#include <iostream>
#include <cstdlib>

void merge(int arr[],int l,int m,int r);
void mergeSort(int arr[],int l,int r);

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
int main(int argc, char const *argv[])
{
	int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
	system("pause");
	return 0;

}
void merge(int arr[],int l,int m,int r){
	int i,j,k;
	int length_of_left_arr = m-l+1;
	int length_of_right_arr = r-m;

	int left_array[length_of_left_arr];
	int right_array[length_of_right_arr];

	for (int i = 0; i < length_of_left_arr; ++i)
	{
		left_array[i] = arr[l+i];
	}
	for (int j = 0; j < length_of_right_arr; ++j)
	{
		right_array[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;
	while(i < length_of_left_arr & j < length_of_right_arr){
		if (left_array[i] <= right_array[j])
		{
			arr[k] = left_array[i];
			i++;	
		}
		else{
			arr[k] = right_array[j];
			j++;
		}
		k++;

	}
	while(i < length_of_left_arr){
		arr[k] = left_array[i];
		i++;
		k++;
	}
	while(j < length_of_right_arr){
		arr[k] = right_array[j];
		j++;
		k++;
	}

}
void mergeSort(int arr[],int l,int r){
	if(l < r){
		int m = l + (r - l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m + 1,r);
		merge(arr,l,m,r);
	}
}