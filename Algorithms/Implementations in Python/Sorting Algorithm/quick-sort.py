def quick_sort(arr):
	if len(arr) == 0:
		return arr
	pivot = arr[int(len(arr)/2)]		#find the middle value of array
	left = [x for x in arr if x < pivot]	#left sub array
	middle = [x for x in arr if x == pivot]	#right sub array
	right = [x for x in arr if x > pivot]	#pivot == middle
	return quick_sort(left) + middle + quick_sort(right) 
print(quick_sort([5,4,28,88,0,1,-9,-99,55]))		#outputs -> [-99,-9,0,1,4,5,28,55,88]