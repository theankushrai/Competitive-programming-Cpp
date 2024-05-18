#include<stack>
#include<string> 
#include<iostream>
#include<algorithm>
using namespace std;
 
int prec(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    return -1;

}

string infixtoprefix(string s ){
    reverse(s.begin(),s.end());
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='('){
            s[i]=')';
        }
        else if(s[i]==')'){
            s[i]='(';
        }
    }
    stack<char> st;
    string res="";

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='a'&&s[i]<='z'){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                res+=st.top();
                st.pop();
                
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty()&&(prec(s[i])<=prec(st.top()))){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}

int main()
{
    string s ="(a-b/c)*(a/k-l)";
    cout<<infixtoprefix(s)<<endl;
    return 0;
}