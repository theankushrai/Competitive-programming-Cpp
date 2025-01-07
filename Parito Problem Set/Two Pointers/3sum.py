# 15. 3Sum
# Solved
# Medium
# Topics
# Companies
# Hint
# Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

# Notice that the solution set must not contain duplicate triplets.

 

# Example 1:

# Input: nums = [-1,0,1,2,-1,-4]
# Output: [[-1,-1,2],[-1,0,1]]
# Explanation: 
# nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
# nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
# nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
# The distinct triplets are [-1,0,1] and [-1,-1,2].
# Notice that the order of the output and the order of the triplets does not matter.
# Example 2:

# Input: nums = [0,1,1]
# Output: []
# Explanation: The only possible triplet does not sum up to 0.
# Example 3:

# Input: nums = [0,0,0]
# Output: [[0,0,0]]
# Explanation: The only possible triplet sums up to 0.
 

# Constraints:

# 3 <= nums.length <= 3000
# -105 <= nums[i] <= 105


# 1. brute force
# TC O(n3)
# SC O(1)


# 2. loop over every element + 2sum
# TC - O(n2) n2 for loop an dnlogn for sort
# SC- O(1)


# optimized n2 skipping duplicates
# TC - O(n2) n2 for loop and nlogn for sort
# SC - O(1) 
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n=len(nums)
        nums=sorted(nums)
        result=[]

        for i,val in enumerate(nums):
            if i>0 and val==nums[i-1]:
                continue
            l,r=i+1,n-1
            while l<r:
                total=val+nums[l]+nums[r]
                if total==0:
                    result.append([val,nums[l],nums[r]])
                    l+=1
                    while nums[l]==nums[l-1] and l<r:
                        l+=1
                elif total<0:
                    l+=1
                else:
                    r-=1

        return result
                    
                
