# 3. Longest Substring Without Repeating Characters
# Solved
# Medium
# Topics
# Companies
# Hint
# Given a string s, find the length of the longest 
# substring
#  without repeating characters.

 

# Example 1:

# Input: s = "abcabcbb"
# Output: 3
# Explanation: The answer is "abc", with the length of 3.
# Example 2:

# Input: s = "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# Example 3:

# Input: s = "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3.
# Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

#1. brute force check all substring
# TC - O(n2)
# SC - O(1)

#2 hashmap and sliding window
# TC - O(n)
# SC- O(n)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        map=set()
        l=0
        maxlength=0
        for r in range(len(s)):
            val=s[r]
            if val in map:
                while val in map:
                    map.remove(s[l])
                    l+=1
            maxlength=max(maxlength,r-l+1)
            map.add(val)
        
        return maxlength