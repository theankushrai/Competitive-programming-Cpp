/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

Example 1:

Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}

Example 2:
Input:
A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Explanation:
Minimum length subarray is {10}
*/

// 1.brute force. find the sum of all subarrays return smallest subarray with sum greater then given no
// time complexity n2;

 int smallestSubWithSum(int a[], int n, int x)
    {
        int count=INT_MAX;
        for(int i =0;i<n;i++){
            int temp=0;
            int currcount=0;
            for(int j=i;j<n;j++){
                temp+=a[j];
                currcount++;
                if(temp>x){
                    count=min(count,currcount);
                }
            }
        } 
        return count;
    }

// 2. sliding window time compelxity n
// inc window if sum<x and reduce window if sum>x;

int smallestSubWithSum(int a[], int n, int x)
    {
        int i =0;
        int j =0;
        int sum=0;
        int count=INT_MAX;
        
        while(j<n&&i<=j){
            while(sum<=x&&j<n) sum+=a[j++];
            while(sum>x&&i<n){
                count=min(count,j-i);
                sum-=a[i++];
            }
        }
        return count;
    }