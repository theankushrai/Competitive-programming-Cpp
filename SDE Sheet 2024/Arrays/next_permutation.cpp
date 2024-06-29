

SEARCH FOR DECREASING PATTERN -> SEARCH FOR IMMEDIATELY BIGGER ELEMENT THEN ACTIVE ELEMENT 
SWAP AND REVERSE THE ARRAY.  


// ----------------------------------------------------------------------------------------

// <!-- A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100 -->

// 1. using next permutation function in stl
//Time complexity - O(1)
//space complexity - (o)

void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end())
    }

//2 printing all permutation and finding next one
//Time complexity O(n!*n)+O(n)
//space complexity O(2n)

//

//3 using next permutation algorithm
//Time Complexit O(3n);
//space complexity O(1)

class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int index=-1,n=a.size();

        for(int i =n-1;i>0;i--){
            if(a[i]>a[i-1]){
                index=i-1;
                break;
            }
        }
        if(index==-1){
            reverse(a.begin(),a.end());
            return;
        }

        for(int i =n-1;i>index;i--){
            if(a[i]>a[index]){
                swap(a[i],a[index]);
                break;
            }
            
        }
        reverse(a.begin()+index+1,a.end());
        
        
    }
};