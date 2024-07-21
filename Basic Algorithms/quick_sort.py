#time complexity n log n 
def partition(arr, left,right):
    pivot=arr[left]
    i=left
    j=right
    while i<j:
        while i<=right and arr[i]<=pivot:i+=1
        while j>=left and arr[j]>pivot:j-=1
        if i<j:arr[i],arr[j]=arr[j],arr[i]

    arr[left],arr[j]=arr[j],arr[left]
    return j

def quicksort(arr,left,right):
    if left<right:
        partition_index=partition(arr,left,right)
        quicksort(arr,left,partition_index-1)
        quicksort(arr,partition_index+1,right)

    
arr=[4,1,3,9,7]
print(arr)
quicksort(arr,0,4)
print(arr)