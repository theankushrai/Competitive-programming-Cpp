#include<stack>
#include<string> 
#include<iostream>
using namespace std;
 
bool balancedParenthesis(string x)
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
int main()
{
    string s ="({[([)]})";
    cout<<balancedParentesis(s)<<endl;

    return 0;
}