# 20. Valid Parentheses
# Solved
# Easy
# Topics
# Companies
# Hint
# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# An input string is valid if:

# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Every close bracket has a corresponding open bracket of the same type.
 

# Example 1:

# Input: s = "()"

# Output: true

# Example 2:

# Input: s = "()[]{}"

# Output: true

# Example 3:

# Input: s = "(]"

# Output: false

# Example 4:

# Input: s = "([])"

# Output: true

 

# Constraints:

# 1 <= s.length <= 104
# s consists of parentheses only '()[]{}'.


# stack
# Time complexity O(n)
# space complexit O(N)
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        match = {")": "(", "}": "{", "]": "["}
        for c in s:
            if c in match:
                if stack and stack[-1] == match[c]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)

        return len(stack) == 0
