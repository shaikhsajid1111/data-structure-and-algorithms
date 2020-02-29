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
	/*Divide and break rule. Divide array into 2 sub arrays left and right*/
	int i,j,k;

	int length_of_left_arr = m-l+1;		/*middle - left + 1*/
	int length_of_right_arr = r-m;		/*right most of the array - middle of the array*/	

	int left_array[length_of_left_arr];		/*left sub array, with initilization of length of left array*/
	int right_array[length_of_right_arr];	/*init. of right sub array*/

	/*copying left part of array to the sub array*/
	for (int i = 0; i < length_of_left_arr; ++i)
	{
		left_array[i] = arr[l+i];
	}
	/*copying right part of the array to the right sub array*/
	for (int j = 0; j < length_of_right_arr; ++j)
	{
		right_array[j] = arr[m + 1 + j];
	}
	i = 0;
	j = 0;
	k = l;		/*iteration starts from first element, that is left array*/

	while(i < length_of_left_arr & j < length_of_right_arr){
		/*if left array has value less than the right one*/
		if (left_array[i] <= right_array[j])
		{
			/*arr[k] -> 0,1,2,...,n*/
			/*if left sub array has lowest value as compare to the right sub array, than left array's value will 
			be copied to the arr*/
			arr[k] = left_array[i];
			i++;	
		}
		else{
			/*if right array has lower value compare to the left array, than arr[] will have tha values*/
			arr[k] = right_array[j];
			j++;
		}
		k++;	/*increment every time,the value is inserted in arr[]*/

	}
	/*checking if any value is left in sub array left array, if so than it will be copied to the the arr[]*/
	while(i < length_of_left_arr){
		arr[k] = left_array[i];
		i++;
		k++;
	}
	/*checking if any value is left in right sub array*/
	while(j < length_of_right_arr){
		arr[k] = right_array[j];
		j++;
		k++;
	}

}
void mergeSort(int arr[],int left,int right){
	/*left is starting value of the array*/
	/*if starting value is lower than the last*/
	if(left < right){
		int m = l + (r - l)/2;		/*finding middle value*/
		mergeSort(arr,l,m);
		mergeSort(arr,m + 1,r);
		merge(arr,l,m,r);
	}
}