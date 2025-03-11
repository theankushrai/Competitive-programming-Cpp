# 1143. Longest Common Subsequence
# Medium
# Topics
# Companies
# Hint
# Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

# A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

# For example, "ace" is a subsequence of "abcde".
# A common subsequence of two strings is a subsequence that is common to both strings.

 

# Example 1:

# Input: text1 = "abcde", text2 = "ace" 
# Output: 3  
# Explanation: The longest common subsequence is "ace" and its length is 3.
# Example 2:

# Input: text1 = "abc", text2 = "abc"
# Output: 3
# Explanation: The longest common subsequence is "abc" and its length is 3.
# Example 3:

# Input: text1 = "abc", text2 = "def"
# Output: 0
# Explanation: There is no such common subsequence, so the result is 0.
 

# Constraints:

# 1 <= text1.length, text2.length <= 1000
# text1 and text2 consist of only lowercase English characters.

# 1. using recursion
# time complexity O(2^n)
# space complexity O(2^n)
class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        
        def dfs(i,j):
            if i==len(s1) or j==len(s2):
                return 0
            if s1[i]==s2[j]:
                return 1 + dfs(i+1,j+1)
            return max(dfs(i+1,j),dfs(i,j+1))
    
        return dfs(0,0)

# 2. using recursion with memoization
# time complexity O(m*n) where m is the length of s1 and n is the length of s2
# space complexity O(m*n)
class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        dp={}
        def dfs(i,j):
            if (i,j) in dp:
                return dp[(i,j)]
            if i==len(s1) or j==len(s2):
                dp[(i,j)] =0
            elif s1[i] == s2[j]:
                dp[(i,j)] = dfs(i+1,j+1) +1
            else:
                dp[i,j]=max(dfs(i+1,j),dfs(i,j+1))
            return dp[(i,j)]
        
        return dfs(0,0)