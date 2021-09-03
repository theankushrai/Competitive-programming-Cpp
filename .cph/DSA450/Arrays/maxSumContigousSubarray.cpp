// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.


// Example 1:

// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9
// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which 
// is a contiguous subarray.

 long long maxSubarraySum(int a[], int n){
        
        long long currmax=0;
        long long finalmax=INT_MIN;
        
        for(int i =0;i<n;i++){
            currmax+=a[i];
            finalmax=max(currmax,finalmax);
            if(currmax<0) currmax=0;
        }
        return finalmax;
    }