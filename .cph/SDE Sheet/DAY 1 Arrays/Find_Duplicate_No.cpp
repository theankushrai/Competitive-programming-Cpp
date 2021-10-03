/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [1,1]
Output: 1
Example 4:

Input: nums = [1,1,2]
Output: 1
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 

Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/

// 1. using sort
// time complexity nlogn;
int findDuplicate(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i =1;i<a.size();i++)if(a[i-1]==a[i])return a[i];
        return -1;
    }


// 2. using count hashmap/count vector
// time complexity n;
// space complexity n;

 int findDuplicate(vector<int>& a) {
        vector<int> count(a.size(),0);
        for(int i =0;i<a.size();i++){
            count[a[i]]++;
            if(count[a[i]]==2)return a[i];
        }
        return -1;
    }

// 3. using graph and hare and tortoise algorithm
// time complexiy n;

 int findDuplicate(vector<int>& a) {
        int slow=a[0];
        int fast=a[0];
        do{
            slow=a[slow];
            fast=a[a[fast]];
        }while(slow!=fast);
        
        slow=a[0];
        while(slow!=fast){
            slow=a[slow];
            fast=a[fast];
        }
        return slow;
    }