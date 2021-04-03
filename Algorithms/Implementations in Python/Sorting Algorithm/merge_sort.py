import sys

sys.setrecursionlimit(100000)

def merge(arr,left,middle,right):

    length_of_left_arr = middle-left+1
    length_of_right_arr = right-middle

    left_arr = []
    right_arr = []
    #split the array into 2 arrays based on equal length
    for i in range(length_of_left_arr):
        #copying left part to left array
        left_arr[i] = arr[left+i]
    
    for j in range(length_of_right_arr):
        #copying right part to right array
        right_arr[j] = arr[m + 1 + j]
    #now we have 2 arrays left and right

    i,j,k = 0

    while i < length_of_left_arr and j < length_of_right_arr:
        #until and unless both the 
        # iterating on both array does not reaches end
        if left_arr[i] <= right_arr[j]:
            #if length of left array element 
            # was greater then right array element
            arr[k] = left_arr[i]
            i += 1
        else:
            #else just add element to array
            arr[k] = right_arr[j]
            j += 1        
        k += 1
    #if by chance due to AND condition 
    # even one side of array was left out, iterate over it and add to arr 
    while i < length_of_left_arr:
        arr[k] = left_arr[i]
        i += 1
        k += 1
    
    while j < length_of_right_arr:
        arr[k] = right_arr[j]
        j += 1
        k += 1
def merge_sort(arr,left,right):
    if left < right:
        m = left + (right - left) / 2
        merge_sort(arr,left,m)
        merge_sort(arr,m+1,right)
        merge(arr,left,m,right)

arr = list(reversed([i for i in range(51)]))
merge_sort(arr,0,len(arr))
print(arr)