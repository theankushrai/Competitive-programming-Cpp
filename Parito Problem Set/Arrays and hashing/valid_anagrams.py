# Given two strings s and t, return true if t is an 
# anagram
#  of s, and false otherwise.

 

# Example 1:

# Input: s = "anagram", t = "nagaram"

# Output: true

# Example 2:

# Input: s = "rat", t = "car"

# Output: false

 

# Constraints:

# 1 <= s.length, t.length <= 5 * 104
# s and t consist of lowercase English letters.
 

# Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


# 1. sorting
# time complexity O(nlogn)
# space complexity O(n)

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
             return False
        
        s=sorted(s)
        t=sorted(t)
        return s==t
# 2. hashmap 
# time complexity O(n)
# space complexity O(n)

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s)!=len(t):
             return False
        s=collections.Counter(s)
        t=collections.Counter(t)

        return s==t