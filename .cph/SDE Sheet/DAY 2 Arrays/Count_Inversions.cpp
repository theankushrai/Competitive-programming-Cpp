/*
Count Inversions in an array | Set 1 (Using Merge Sort)
Difficulty Level : Hard
Last Updated : 28 Jun, 2021
 
Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j 
Example: 

Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).


Input: arr[] = {3, 1, 2}
Output: 2

Explanation: Given array has two inversions:
(3, 1), (3, 2) */

// 1.brute force - count all the inversions;
// time complexity n2;

long long int inversionCount(long long a[], long long n)
    {
        long long int count=0;
        for(long long i=0;i<n;i++){
            for(long long j=i+1;j<n;j++){
                if(i<j&&a[i]>a[j])count++;
            }
        }
        return count;
    }


// 2. using merge sort merge
//time complexity nlog n;
//space complexity n;

 long long int merge(long long arr[],long long l, long long mid, long long r){
        long long int count=0;
        
        long long n=mid-l+1;
        long long m=r-mid;
        long long a[n],b[m];
        for(long long i =0;i<n;i++) a[i]=arr[i+l];
        for(long long i=0;i<m;i++)b[i]=arr[i+mid+1];
        
        long long i =0;
        long long j = 0;
        long long k=l;
        
        while(i<n&&j<m){
            if(a[i]<=b[j]) arr[k++]=a[i++];
            else {
                arr[k++]=b[j++];
                count+=(n-i);
            }
        }
        while(i<n)arr[k++]=a[i++];
        while(j<m)arr[k++]=b[j++];
        return count;
    }
    long long int mergeSort(long long a[],long long l,long long r){
        if(l>=r)return 0;
        long long int count=0;
        long long mid=(l+r)/2;
        count+=mergeSort(a,l,mid);
        count+=mergeSort(a,mid+1,r);
        count+=merge(a,l,mid,r);
        return count;
    }
    long long int inversionCount(long long a[], long long n)
    {
        return mergeSort(a,0,n-1);
    }