

### 📚 Problem Description  

You are given an array of strings `words` and a string `pref`. Your task is to count how many strings in `words` contain `pref` as a **prefix**.  

A **prefix** of a string is any leading contiguous substring of the string.  

---

### 📝 Examples  

#### **Example 1:**  
**Input:**  
`words = ["pay","attention","practice","attend"], pref = "at"`  
**Output:**  
`2`  
**Explanation:**  
- The strings `"attention"` and `"attend"` contain `"at"` as a prefix.  

#### **Example 2:**  
**Input:**  
`words = ["leetcode","win","loops","success"], pref = "code"`  
**Output:**  
`0`  
**Explanation:**  
- No string contains `"code"` as a prefix.  

---

### 💡 Approaches  

#### **Approach 1: Brute Force (Using `startswith`)**  
We iterate through the list of words and check for each word whether it starts with the given prefix using Python's built-in `startswith` method.

#### **Approach 2: Optimized Solution Using a Trie**  
A Trie (prefix tree) is an efficient data structure for prefix-related operations.  
1. **Build a Trie:**  
   - Insert all words into the Trie while keeping track of prefix counts.  
2. **Count Matching Prefixes:**  
   - Traverse the Trie for the given prefix and return its count.  

---

### 🧑‍💻 Code Implementations  

#### **Solution 1: Brute Force**  

```python
class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        count = 0
        for word in words:
            if word.startswith(pref):
                count += 1
        return count
```

#### **Solution 2: Trie Implementation**  

```python
class PrefixNode:
    def __init__(self):
        self.count = 0
        self.children = {}

class PrefixTree:
    def __init__(self):
        self.root = PrefixNode()

    def add(self, word: str) -> None:
        curr = self.root
        for char in word:
            if char not in curr.children:
                curr.children[char] = PrefixNode()
            curr = curr.children[char]
            curr.count += 1

    def count(self, prefix: str) -> int:
        curr = self.root
        for char in prefix:
            if char not in curr.children:
                return 0
            curr = curr.children[char]
        return curr.count

class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        trie = PrefixTree()
        for word in words:
            trie.add(word)
        return trie.count(pref)
```

---

### 🚀 Complexity Analysis  

#### **Solution 1: Brute Force**  
1. **Time Complexity:**  
   - Iterating through `words` → O(n).  
   - Checking the prefix using `startswith` → O(m), where `m` is the length of `pref`.  
   - Total: **O(n * m)**.  

2. **Space Complexity:**  
   - No additional data structures used → O(1).  

---

#### **Solution 2: Trie**  
1. **Time Complexity:**  
   - Building the Trie: O(n * l), where `l` is the average length of words.  
   - Querying the prefix: O(p), where `p` is the length of `pref`.  
   - Total: **O(n * l + p)**.  

2. **Space Complexity:**  
   - Storing the Trie → O(n * l).  

---

### 🐾 Example Walkthrough  

#### **Input:**  
`words = ["pay","attention","practice","attend"], pref = "at"`  

**Solution 1:**  
- Iterate through words and check:  
  - `"pay"`: Does not start with `"at"`.  
  - `"attention"`: Starts with `"at"`.  
  - `"practice"`: Does not start with `"at"`.  
  - `"attend"`: Starts with `"at"`.  
- **Output:** `2`.  

**Solution 2:**  
- Build a Trie with `"pay"`, `"attention"`, `"practice"`, and `"attend"`.  
- Traverse the Trie for `"at"` and return the count → `2`.  

---

### 🐱 Call to Action: Prefix Counting Made Easy! 🐱  
Try both approaches on your own examples! Explore how the Trie-based solution scales for larger inputs!