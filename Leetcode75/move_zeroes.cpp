// # Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// # Note that you must do this in-place without making a copy of the array.

 

// # Example 1:

// # Input: nums = [0,1,0,3,12]
// # Output: [1,3,12,0,0]
// # Example 2:

// # Input: nums = [0]
// # Output: [0]
 

// # Constraints:

// # 1 <= nums.length <= 104
// # -231 <= nums[i] <= 231 - 1
 

// # Follow up: Could you minimize the total number of operations done?

// # 1. sort and reverse
// # time complexity O(n)+O(nlogn)
// #space complexity - O(1)

// #2 take a new array and add all the non zero elements
// # time complexity O(n)
// # space complexity O(n)

// #swap non zero values to first
// #time complexity O(n)
// #space complexity O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0;
        int j = 0;

        while(j<nums.size()){
            if(nums[j]){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
    }
};