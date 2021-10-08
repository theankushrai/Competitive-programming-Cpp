/*
Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

//1.brute force - check all substrings
//time complexity n3
//space complexity n for checking repeating elements

int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxl=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                int count=0;
                unordered_set<char> temp;
                for(int k =i;k<=j;k++){
                    if(temp.find(s[k])!=temp.end())break;
                    temp.insert(s[k]);
                    count++;
                }
                maxl=max(count,maxl);
            }
        }
        return maxl;
    }

//2.optimized brute force - check all substrings
//time complexity n2
//space complexity n for checking repeating elements

 int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int maxl=0;
        for(int i =0;i<n;i++){
            int count=0;
            unordered_set<char> temp;
            for(int j =i;j<n;j++){
                if(temp.find(s[j])!=temp.end()){
                    temp.clear();
                    count=0;
                }
                    temp.insert(s[j]);
                    count++;
                maxl=max(count,maxl);
            }
        }
        return maxl;
    }

//3.using sliding window
//time complexity 2n;
//space complexity n;

 int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_set<char> temp;
        int maxl=0;
        int l=0;
        for(int r =0;r<n;r++){
            if(temp.find(s[r])==temp.end()) temp.insert(s[r]);
            else{
                while(l+1<=r&&s[l]!=s[r]){
                    temp.erase(s[l]);
                    l++;
                }
                l++;
            }
            maxl=max(maxl,r-l+1);
        }
        return maxl;
    }

//4. optimized sliding window using hashmap- instead of using while loop to move l, we can use hashmap to store index and directly move l there;
//time complexity n;
//space complexitty n;

 int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> temp;
        int maxl=0;
        int l=0;
        for(int r =0;r<n;r++){
            if(temp.find(s[r])==temp.end()) temp[s[r]]=r;
            else{
                l=max(temp[s[r]]+1,l);//if l is greater then s[r] then return l
                temp[s[r]]=r;
            }
            maxl=max(maxl,r-l+1);
        }
        return maxl;
    }