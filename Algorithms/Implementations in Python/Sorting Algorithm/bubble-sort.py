def bubble_sort(arr):
	for i in range(len(arr)):
		for j in range(len(arr)):
			if arr[i] < arr[j]:
				arr[i],arr[j] = arr[j],arr[i]
	return arr	
	
print(bubble_sort([1,5,8,9,6,-8,-8,8,-9895,0]))	#outputs - > [-9895,-8,-8,0,1,5,6,8,8,9]