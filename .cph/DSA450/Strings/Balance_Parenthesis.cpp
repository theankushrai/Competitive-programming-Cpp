/*
Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

Example 1:

Input:
{([])}
Output: 
true
Explanation: 
{ ( [ ] ) }. Same colored brackets can form 
balaced pairs, with 0 number of 
unbalanced bracket.
Example 2:

Input: 
()
Output: 
true
Explanation: 
(). Same bracket can form balanced pairs, 
and here only 1 type of bracket is 
present and in balanced way.
Example 3:

Input: 
([]
Output: 
false
Explanation: 
([]. Here square bracket is balanced but 
the small bracket is not balanced and 
Hence , the output will be unbalanced.
*/

// 1. using stack time and space complexity n;

bool isValid(string a) {
        stack<char> st;
        for(int i =0;i<a.length();i++){
            if(a[i]=='('||a[i]=='['||a[i]=='{'){
                st.push(a[i]);
            }
            else{
                switch(a[i]){
                case ')':if(st.size()==0||st.top()!='(')return false;
                    break;
                case ']':if(st.size()==0||st.top()!='[')return false;
                    break;
                case '}':if(st.size()==0||st.top()!='{')return false;
                    break;
            }
            st.pop();
        }
        }   
        if(st.empty())return true;
        return false;
    }