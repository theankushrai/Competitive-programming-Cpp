# Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

# You must write an algorithm that runs in O(n) time.

 

# Example 1:

# Input: nums = [100,4,200,1,3,2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
# Example 2:

# Input: nums = [0,3,7,2,5,8,4,6,0,1]
# Output: 9
 

# Constraints:

# 0 <= nums.length <= 105
# -109 <= nums[i] <= 109

#1. sort
# Time complexity O(nlogn)
# space complexity O(1)

#2 put in set and check
# Time complexity O(n)
# space complexity O(n)

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        map=set(nums)
        if len(nums)==0:
            return 0
        maxresult=1
        for it in map: # we are using map to reduce time complxity 
            if it-1 in map:
                continue
            result=1
            while it+result in map:
                result+=1
            maxresult=max(result,maxresult)
        
        return maxresults