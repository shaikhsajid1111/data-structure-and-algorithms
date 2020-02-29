def binary_search(arr,start,end,value):
        if end >= start:
                mid = int(start+(end - start)/2)
  
        # If element is present at the middle itself 
                if arr[mid] == value:
                        return mid
          
                # If element is smaller than mid, then it can only 
                # be present in left subarray 
                elif arr[mid] > value:
                        return binary_search(arr, start, mid-1, value) 
          
                # Else the element can only be present in right subarray 
                else:
                        return binary_search(arr, mid+1, end, value)
        else:
                return -1
  
        
l = [i for i in range(65)]

print(binary_search(l,0,len(l)-1,45))           #output->45			
