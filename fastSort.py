# fast sort
def partition(arr,low,high): 
	i = ( low-1 )		 
	pivot = arr[high]	 

	for j in range(low , high): 

		if arr[j] <= pivot: 
		
			i = i+1
			arr[i],arr[j] = arr[j],arr[i] 

	arr[i+1],arr[high] = arr[high],arr[i+1] 
	return ( i+1 ) 
 
def quickSort(arr,low,high): 
	if low < high: 

            # pi is partitioning index, arr[p] is now 
            pi = partition(arr,low,high)
            if pi-low<50:
                insertionSort(arr)
            else:
                quickSort(arr, low, pi-1)
            if high-pi<50:
                insertionSort(arr)
            else:
                quickSort(arr, pi+1, high) 

def insertionSort(arr): 

    for i in range(1, len(arr)): 
  
        key = arr[i] 
        j = i-1
        while j >= 0 and key < arr[j] : 
                arr[j + 1] = arr[j] 
                j -= 1
        arr[j + 1] = key 

arr = []
import random
for x in range(44):
   arr.append(random.randint(1,1000))
print(arr)
n = len(arr) 
quickSort(arr,0,n-1) 
print(arr)
#print ("Sorted array is:") 
#for i in range(n): 
#	print ("%d" %arr[i])

