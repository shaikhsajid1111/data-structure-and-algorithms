def insertion_sort(arr):
	for index in range(1,len(arr)):
		current_value = arr[index]
		position = index
		while position > 0 and arr[position-1] > current_value:
			arr[position] = arr[position-1]
			position -= 1
		arr[position] = current_value
	return arr		
def bucket_sort(x):
	arr = []
	slot_num = 10
	for i in range(slot_num):
		arr.append([])
	for j in x:
		index_b = int(slot_num * j)
		arr[index_b].append(j)
	for i in range(slot_num):
		arr[i] = insertion_sort(arr[i])
	k = 0
	for i in range(slot_num):
		for j in range(len(arr[i])):
			x[k] = arr[i][j]
			k += 1
	return x		 	
x = [0.20,0.20,0.30,0.80,0.10,0.25]	
print(bucket_sort(x))