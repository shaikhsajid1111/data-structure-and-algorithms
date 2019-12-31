#include<iostream>
#include<cstdlib>

int binarySearch(int arr[],int start,int end,int value);

int main(int argc, char const *argv[])
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int res = binarySearch(arr,0,12,10);
	std::cout << res << std::endl;
	system("pause");
	return 0;
}
int binarySearch(int arr[],int start,int end,int value){
	int middle = start + (end - start) / 2;
	/*if element is present itself in middle place*/
	if(arr[middle] == value){
		return middle;
	}
	/*if element is smaller than middle, than it can be only found on left sub array*/

	if(arr[middle] > value){
		return binarySearch(arr,start,middle-1,value);	/*parameter explanation : recursing the function, but passing the position of array from left to the middle 
		that is start - middle - 1 = left sub array
		*/
	}

	else{
		/*if value is greater than middle value of array*/
	return binarySearch(arr,middle+1,end,value);	/*recursingly passing value as right sub array that is middle+1 - to the last of 
	the array*/

}
  	return -1;
}