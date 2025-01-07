# Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

# You must write an algorithm that runs in O(n) time and without using the division operation.

 

# Example 1:

# Input: nums = [1,2,3,4]
# Output: [24,12,8,6]
# Example 2:

# Input: nums = [-1,1,0,-3,3]
# Output: [0,0,9,0,0]
 

# Constraints:

# 2 <= nums.length <= 105
# -30 <= nums[i] <= 30
# The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

# Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

# 1. two arrays prefix and postfix and then product them both
# Time complexity O(n)
# space complexity 2n O(n)

# #2 optimize using prefix product
# Time complexity O(n)
# space complexity O(n)

# 3 use digonal  prefix and suffix
# Time complexity O(n)
# space complexity O(1)

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n=len(nums)
        result=[1]*n
        prefix=1
        for i in range(n-1):
            prefix*=nums[i]
            result[i+1]=prefix
        
        postfix=1
        for i in range(n-1,0,-1):
            postfix*=nums[i]
            result[i-1]*=postfix
        
        return result



