#include<iostream>
#include<cstdlib>
void swap(int *a,int *b);
void selection_sort(int arr[],int size);

int main(int argc, char const *argv[])
{
	
	int arr[5] = {5,4,8,21,4};
	selection_sort(arr,5);
	for(int i = 0;i < 5;i++){
		std::cout << arr[i] <<",";
	}
	system("pause");
	return 0;
}
void swap(int *a,int *b){
							//a = 10 , b = 5
	*a = *a+*b;				//10 + 5 = a = 15
	*b = *a-*b;				// b = 15-5 = 10
	*a = *a-*b;					//a = 10, 15-10 = 5
}
void selection_sort(int arr[],int size){
	int i,j,min_idx;

	for(i = 0;i < size-1;i++){			/*loop ranges from 0 - array -1*/
		min_idx = i;					/*contains minimum value i.e starts from 0*/
		for(j = i + 1;j < size;j++){			/*j iterates from i + 1 to array's last element*/
			if(arr[j] < arr[min_idx]){			/*if after value is smaller than before value*/
				min_idx = j;					/*min_idx holds the after value,which is smaller than previous*/

				swap(&arr[min_idx],&arr[i]);	/*swap value, that is switch values,smaller is getting in previous and bigger gets into after value*/
			}
		}
	}
}