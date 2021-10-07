/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

 

Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
 

Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
*/

// 1.brute force 
// time complexity n2

int reversePairs(vector<int>& a) {
        int count=0;
        int  n=a.size();
        
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if((double)a[i]/2>(double)a[j])count++;
            }
        }
        return count;
    }


//2. using modified mergesort
//time complexity n logn 
int merge(vector<int>& arr, int l , int mid, int r){
        int count=0;
        int n=mid-l+1;
        int m=r-mid;
        int a[n],b[m];
        
        for(int i =0;i<n;i++) a[i]=arr[i+l];
        for(int i =0;i<m;i++) b[i]=arr[mid+i+1];
        
        //main
        int i =0,j=0;
        for(i=0;i<n;i++){
            while(j<m&&(a[i]>2LL*b[j]))j++;
            count+=(j);
        }
        
        
        i=0,j=0;
        int k=l;
        
        while(i<n&&j<m){
            if(a[i]<=b[j]) arr[k++]=a[i++];
            else arr[k++]=b[j++];
        }
        
        while(i<n) arr[k++]=a[i++];
        while(j<m) arr[k++]=b[j++];
        
        
        return count;
    }
    
    int mergesort(vector<int>& a,int l, int r){
        int count=0;
        if(l>=r)return count;
        int mid=(l+r)/2;
        count+=mergesort(a,l,mid);
        count+=mergesort(a,mid+1,r);
        count+=merge(a,l,mid,r);
        return count;
    }
    int reversePairs(vector<int>& a) {
        return mergesort(a,0,a.size()-1);
    }