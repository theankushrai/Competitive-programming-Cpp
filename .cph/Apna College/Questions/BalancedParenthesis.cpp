#include<stack>
#include<string> 
#include<iostream>
using namespace std;
 
bool balancedParentesis(string s){
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        else{
            switch (s[i])
            {
            case ')':
                if(st.top()!='(') return false;
                break;
            
            case ']':
                if(st.top()!='[') return false;
                break;
            case '}':
                if(st.top()!='{') return false;
                break;
            default:
                cout<<"WRONG EXPRESSION"<<endl;
                break;
            }
            st.pop();
        }
    }
    return true;
}

int main()
{
    string s ="({[([)]})";
    cout<<balancedParentesis(s)<<endl;

    return 0;
}