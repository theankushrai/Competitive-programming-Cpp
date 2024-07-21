#time complexity n log n 
#auxillary space n 
def merge(a,l,m,r):
    i=l
    j=m+1
    temp_arr=[]
    
    while(i<=m and j<=r):
        if a[i]<=a[j]:
            temp_arr.append(a[i])
            i+=1
        else:
            temp_arr.append(a[j])
            j+=1
    
    while(i<=m):
        temp_arr.append(a[i])
        i+=1
    
    while(j<=r):
        temp_arr.append(a[j])
        j+=1

    
    for k in range(l,r+1): a[k]=temp_arr[k-l]
    


def mergesort(a,l,r):
    if l>=r:return
    mid=int((l+r)/2)
    mergesort(a,l,mid)
    mergesort(a,mid+1,r)
    merge(a,l,mid,r)

a=[9,8,7,6,5,4,3,2,1]
print(a)

mergesort(a,0,8)
print(a)
