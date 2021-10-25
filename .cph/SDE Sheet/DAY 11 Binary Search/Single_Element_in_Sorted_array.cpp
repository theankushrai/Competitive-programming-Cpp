/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105*/

//you can tru count array , checking with next elements as well as xor of all elements

//since its given that we have to solve this in logn time we will directly go for binary search
// 1. using binary search
//time complexity logn

int singleNonDuplicate(vector<int>& nums) {
        int n =nums.size();
        int low=0;
        int high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            int tocheck;
            if(mid%2==0)tocheck=mid+1;
            else tocheck=mid-1;
            if(nums[mid]==nums[tocheck])low=mid+1;//if same that means we are in left half so we move to right half
            else high=mid-1;//if not same that means we are in right half so we move to left half;
        }
        return nums[low];
    }