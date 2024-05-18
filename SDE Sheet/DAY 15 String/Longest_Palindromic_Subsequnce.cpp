/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
// 1.brute force ;
//time complexity n3;
bool ispalindrome(string s){
        int i =0;
        int j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        int n =s.size();
        for(int i =0;i<n;i++){
            string temp="";
            for(int j =i;j<n;j++){
                temp+=s[j];
                if(ispalindrome(temp)&&temp.size()>ans.size()){
                    ans=temp;
                }
            }
        }
        return ans;
    }
//2. using two pointers to move left and right from array.
//time complexity n2;

string longestPalin (string s) {
        int n =s.length();
        string ans;
        int start;
        int maxlength=0;
        for(int i =0;i<n;i++){
            
            //for odd length
            int l=i;
            int r=i;
            
                while(l>=0&&r<n&&s[l]==s[r]){
                    l--;
                    r++;
                }
                l++;
                r--;
                if(s[l]==s[r]&&r-l+1>maxlength){
                    maxlength=r-l+1;
                    start=l;
                }

            //for even length
            l=i;
            r=i+1;
           
                while(l>=0&&r<n&&s[l]==s[r]){
                    l--;
                    r++;
                }
                l++;
                r--;
                if(s[l]==s[r]&&r-l+1>maxlength){
                    maxlength=r-l+1;
                    start=l;
                }
            
        }
        while(maxlength--){
            ans+=s[start++];
        }
        return ans;
    }
