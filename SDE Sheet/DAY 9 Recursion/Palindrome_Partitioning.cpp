/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.*/

// 1. using recursion;
// time complexity 

bool is_palindrome(string s , int left, int right){
        while(left<right){
            if(s[left++]!=s[right--])return false;
        }
        return true;
    }
    void par(int idx,string s, vector<string> &temp, vector<vector<string>> &ans){
        if(idx==s.length()){
            ans.push_back(temp);
            return;
        }
        for(int i =idx;i<s.length();i++){
            if(is_palindrome(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                par(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        par(0,s,temp,ans);
        return ans;
    }