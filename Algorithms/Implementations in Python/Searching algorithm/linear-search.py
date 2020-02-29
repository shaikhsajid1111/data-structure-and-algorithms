def linear_search(arr,value):
	for i in range(len(arr)):
		if arr[i] == value:
			return i
		else:
			return False 	

print(linear_search([1,2,8,9,5],00))		#outputs - > 4