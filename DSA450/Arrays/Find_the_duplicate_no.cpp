// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.

// You must solve the problem without modifying the array nums and uses only constant extra space.

 

// Example 1:

// Input: nums = [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: nums = [3,1,3,4,2]
// Output: 3


//1. using brute force

int findDuplicate(vector<int>& nums) {
        if(nums.size()<=1)return -1;

        for(int i =0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(a[i]==a[j])return a[i];
            }
        }
        return -1;
    }

// 2. using count array
int findDuplicate(vector<int>& nums) {
        if(nums.size()<=1)return -1;

        vector<int> count(nums.size(),0); //we count the occurance of all value using count vecor

        for(int i =0;i<nums.size();i++){
            count[nums[i]]++;
            if(count[nums[i]]>1)return nums[i]; // if any items occurs more then once i.e is repeated we return that item.
        }
        return -1;
    }