/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.*/


// 1.using vector/stack to store every word and then reverse vector/print stack
//it doesnt handle edge cases of string starting with multiple spaces;
//time complexity 3n;
//space complexity n;

string reverseWords(string s) 
    { 
         stack<string> st;
        string temp="";
        for(auto it:s){
            if(it=='.'){
                st.push(temp);
                temp="";
            }
            else temp+=it;
        }
        st.push(temp);
        temp="";
        while(st.empty()==false){
            temp+=st.top();st.pop();
            if(!st.empty())temp+='.';
        }
        return temp;
    } 

//2. find end of each word and then reverse it;
//time complexity n;
//space complexity O(1);
string reverseWords(string s) {
        
        //remove side spaces
        while(s[0]==' ')s=s.substr(1);
        while(s[s.size()-1]==' ')s=s.substr(0,s.size()-1);
        
        int n =s.size();
        string ans;
        int i=n-1;
        
        while(i>=0){
            if(s[i]==' '){
                ans+=' ';
                while(s[i]==' ')i--;
            }
            else{
                int j=i;
                while(j>=0&&s[j]!=' ')j--;
                i=j;
                j++;
                while(j<n&&s[j]!=' ')ans+=s[j++];
            }
        }
        return ans;
    }