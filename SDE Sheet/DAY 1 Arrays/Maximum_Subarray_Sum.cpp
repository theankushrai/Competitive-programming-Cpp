

USING BRUTE FORCE 
USING BRUTE FORCE OPTIMIZED
KADENES ALGORITHM






/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

// 1.n3 solution
int maxSubArray(vector<int> &a)
{
    int n = a.size();
    int sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int temp = 0;
            for (int k = i; k <= j; k++)
            {
                temp += a[k];
            }
            sum = max(temp, sum);
        }
    }
    return sum;
}

// 2.n2 solution
int maxSubArray(vector<int> &a)
{
    int n = a.size();
    int sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = i; j < n; j++)
        {
            temp += a[j];
            sum = max(temp, sum);
        }
    }
    return sum;
}
// 3. n solution kadanes algorithm

// Initialize:
//     max_so_far = INT_MIN
//     max_ending_here = 0

// Loop for each element of the array
//   (a) max_ending_here = max_ending_here + a[i]
//   (b) if(max_so_far < max_ending_here)
//             max_so_far = max_ending_here
//   (c) if(max_ending_here < 0)
//             max_ending_here = 0
// return max_so_far

int maxSubArray(vector<int> &nums)
{
    int msf = INT_MIN;
    int meh = 0;
    for (auto it : nums)
    {
        meh += it;
        msf = max(msf, meh);
        if (meh < 0)
            meh = 0;
    }
    return msf;
}