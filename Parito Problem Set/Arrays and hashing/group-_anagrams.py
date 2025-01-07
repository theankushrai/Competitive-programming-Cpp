# Given an array of strings strs, group the 
# anagrams
#  together. You can return the answer in any order.

 

# Example 1:

# Input: strs = ["eat","tea","tan","ate","nat","bat"]

# Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

# Explanation:

# There is no string in strs that can be rearranged to form "bat".
# The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
# The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
# Example 2:

# Input: strs = [""]

# Output: [[""]]

# Example 3:

# Input: strs = ["a"]

# Output: [["a"]]

 

# Constraints:

# 1 <= strs.length <= 104
# 0 <= strs[i].length <= 100
# strs[i] consists of lowercase English letters.


# 1. check every word if they can merge
# TC O(n2) n2 for iterating and nlogn for sorting
# SC O(1)

# 2. take a map of each word and sorted values and return the resultant values in map
# TC - O(nlogn)
# SC - O(n)
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        map=defaultdict(list)

        for word in strs:
            sortedword=''.join(sorted(word))
            map[sortedword].append(word)
        
        return list(map.values())
# 3. map the values of counthashmap to every value. 
# TC - O(m.n) n is the string m is the length of every word
# SC - O(26) O(1)

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        
        map=defaultdict(list)

        for word in strs:
            count=[0]*26
            for c in word:
                count[ord(c)-ord('a')]+=1
            map[tuple(count)].append(word)
            
        print(map)
        return list(map.values())

