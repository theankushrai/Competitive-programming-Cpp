/*
Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.

Example 1:

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
Your Task:
You just have to complete the function maxLen() which takes two arguments an array A and n, where n is the size of the array A and returns the length of the largest subarray with 0 sum.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
-1000 <= A[i] <= 1000, for each valid i
*/

// 1.brute force - check all subarray in n3
//time complexity n3
int maxLen(vector<int>&a, int n)
    {   
        int maxl=0;
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                int currlen=0;
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=a[k];
                    currlen++;
                }
                if(sum==0)maxl=max(currlen,maxl);
            }
        }
        return maxl;
    }
//2. optimized brute force 
//time complexity n2

int maxLen(vector<int>&a, int n)
    {   
        int maxl=0;
        for(int i =0;i<n;i++){
                int currlen=0;
                int sum=0;
            for(int j=i;j<n;j++){
                sum+=a[j];
                currlen++;
                if(sum==0)maxl=max(currlen,maxl);
            }
        }
        return maxl;
    }
// using hashmap
// time complexity n;
// space complexity n

int maxLen(vector<int>&a, int n)
    {   
        unordered_map<int,int> temp;
        int sum=0,maxl=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(sum==0)maxl=i+1;//if sum is 0. it means the subarray from starting to i gives zero   
            if(temp.find(sum)==temp.end())temp[sum]=i;
            else maxl=max(maxl,i-temp[sum]);
        }
        return maxl;
    }