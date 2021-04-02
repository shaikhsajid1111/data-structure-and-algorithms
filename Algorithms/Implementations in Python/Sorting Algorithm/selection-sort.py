
def selection_sort(arr):
	if len(arr)<2:
		return arr
	for i in range(len(arr)): #traversing array and holding one element at a time
		min_index = i #assume first element to be the smallest
		for j in range(i+1,len(arr)):#now traverse from the smallest assumption to the end
			if arr[min_index] > arr[j]:
				#if minimum assumption was lower then current element
				min_index = j #change min to current
		arr[i],arr[min_index] = arr[min_index],arr[i] #now swap the smallest with the current one
		return arr
print(selection_sort([9,8,0,-9])) #outputs -> [-9,8,0,9]		
