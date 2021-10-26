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
bool ispar(string x)
    {
        stack<char> s;
        for(int i =0;i<x.length();i++){
            char c=x[i];
            if(c=='(')s.push(')');
            else if(c=='{')s.push('}');
            else if(c=='[')s.push(']');
            else{
                if(s.empty()||s.top()!=c)return false;
                s.pop();
            }
        }
        return s.empty();
    }