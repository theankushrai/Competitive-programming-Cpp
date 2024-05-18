#include<stack>
#include<string> 
#include<iostream>
using namespace std;

int prefixEvaluation(string s){
    stack<int> st;
    for(int i=s.size()-1; i>=0;i--){
        if(s[i]>='0'&&s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int op1=st.top();st.pop();
            int op2=st.top();st.pop();
             
             switch (s[i])
             {
             case '+':
                 st.push(op1+op2);
                 break;
            
             case '-':
                 st.push(op1-op2);
                 break;
            
             case '*':
                 st.push(op1*op2);
                 break;
            
             case '/':
                 st.push(op1/op2);
                 break;
             
             default:
             cout<<"wrong symbol"<<endl;
                 break;
             }
        }
    }
    return st.top();
}

int main()
{
    string s ="-+7*45+20";
    cout<<prefixEvaluation(s)<<endl;
    return 0;
}