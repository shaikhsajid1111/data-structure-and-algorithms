def insertion_sort(arr):
	'''this function takes list'''
	for index in range(1,len(arr)):			#loop from 1 to length of the array
		current_value = arr[index]		#current value of the arr[index]
		position  = index 			#position of the index
		'''Loop until position is greater than 0 and arr[previous position] is greater than the next one '''
		while position > 0 and arr[position-1] > current_value:			
			arr[position] = arr[position-1]				#copy previous one to the next one 
			position -= 1					#again go the the previous value 
		arr[position] = current_value	#and change the value copied from next one
	return arr
print(insertion_sort([8,9,7,2,1]))		#outputs -> [1,2,7,8,9]


