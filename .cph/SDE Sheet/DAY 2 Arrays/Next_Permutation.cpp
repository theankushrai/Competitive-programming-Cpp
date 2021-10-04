/*

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100

*/

// 1. using next permutation build in function
// time complexity n;
void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }

//2. printing all permutation and finding the next permutation;
// time complexity n2;

//3, logic
// time complexity n;
void nextPermutation(vector<int>& a) {
        int n=a.size();
        int l=-1,r=-1;
        for(int i =n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                l=i;
                break;
            }
        }
        if(l==-1){
            reverse(a.begin(),a.end());
            return;
        }
        for(int i =n-1;i>=0;i--){
            if(a[i]>a[l]){
                r=i;
                break;
            }
        }
        
        swap(a[l],a[r]);
        reverse(a.begin()+l+1,a.end());
        
    }

