# A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

# Given a string s, return true if it is a palindrome, or false otherwise.

 

# Example 1:

# Input: s = "A man, a plan, a canal: Panama"
# Output: true
# Explanation: "amanaplanacanalpanama" is a palindrome.
# Example 2:

# Input: s = "race a car"
# Output: false
# Explanation: "raceacar" is not a palindrome.
# Example 3:

# Input: s = " "
# Output: true
# Explanation: s is an empty string "" after removing non-alphanumeric characters.
# Since an empty string reads the same forward and backward, it is a palindrome.
 

# Constraints:

# 1 <= s.length <= 2 * 105
# s consists only of printable ASCII characters.


# 1. reverse and compare
# Time complexity O(n)
# space complexity O(n)

# 2. two pointers
# Time complexity O(n)
# space complexity O(q)

class Solution:
    def isPalindrome(self, s: str) -> bool:
        i=0
        j=len(s)-1
        def isvalid(c):
            return (
                ord('A')<=ord(c)<=ord('Z') or
                ord('a')<=ord(c)<=ord('z') or
                ord('0')<=ord(c)<=ord('9')
            )

        while i<j:
            if isvalid(s[i]) and isvalid(s[j]):
                if s[i].lower()==s[j].lower():
                    i+=1
                    j-=1
                else:
                    return False
            elif isvalid(s[i]):
                j-=1
            else:
                i+=1
        
        return True
