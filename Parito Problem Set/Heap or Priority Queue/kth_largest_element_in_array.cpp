// 215. Kth Largest Element in an Array
// Solved
// Medium
// Topics
// Companies
// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.

// Can you solve it without sorting?

 

// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
 

// Constraints:

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104


// 0 array and sort 
// time complexity O(n log n ) +k
// space complexity O(1)

// 1 priority queue 
// time complexity O(n)+klogn
// space complexity O(n)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(),nums.end());
        for(int i=1;i<k;i++){
            pq.pop();
        }
        return pq.top();
    }
};

// 3. quick selct average time complexity n and wost n2
// space complxity O(1);

class Solution {
public:
    int quickselect(int left, int right, vector<int>& nums, int k){
        int p=left;
        int pivot=nums[right];
        for(int i=left;i<right;i++){
            if(nums[i]<=pivot)swap(nums[i],nums[p++]);
        }
        swap(nums[p],nums[right]);
        if(p==k)return nums[p];
        if(p<k)return quickselect(p+1,right,nums,k);
        else return quickselect(left, p-1,nums,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        k=nums.size()-k;
        return quickselect(0,nums.size()-1,nums,k);
    }
};