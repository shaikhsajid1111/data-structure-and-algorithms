import os

def selection_sort(arr):
	if len(arr)<2:
		return arr
	for i in range(len(arr)):
		min_index = i
		for j in range(i+1,len(arr)):
			if arr[min_index] > arr[j]:
				min_index = j
		arr[i],arr[min_index] = arr[min_index],arr[i]
		return arr
print(selection_sort([9,8,0,-9])) #outputs -> [-9,8,0,9]		
os.system("pause")