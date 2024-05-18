/*
Given a string S, check if it is palindrome or not.

Example 1:

Input: S = "abba"
Output: 1
Explanation: S is a palindrome
Example 2:

Input: S = "abc" 
Output: 0
Explanation: S is not a palindrome
*/
// 1. brute force - find reverse of string and check if string is equal to reverse. time space complexiy n;

bool isPalindrome(string s)
	{
        int temp =s;
        if(reverse(temp)==s)return true;
        else false;
	}


// 2. check wheher last element is equal to first element. then inc first and reduce last time complexity n; space 0

int isPalindrome(string s)
	{
	    int i =0;
	    int j = s.length()-1;
	    
	    while(i<j){
	        if(s[i++]!=s[j--]) return 0;
	    }
	    return 1;
	}
