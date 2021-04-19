#include<string>
#include<stack> 
#include<iostream>
using namespace std;
 
void reverseusingstack(string s){
    stack<string> st;
    int i=0;
    string word="";
    while(i<=s.size()){
        if(s[i]==' '||i==s.size()){
            st.push(word);
            word="";
        }else{
            word+=s[i];
        }
        i++;
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main()
{
    string s="Hey!! how are you doing?";
    reverseusingstack(s);
    return 0;
}