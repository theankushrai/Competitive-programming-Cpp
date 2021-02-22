#include<string> 
#include<iostream>
using namespace std;
 
string movetoend(string s){
    if(s.length()==0) return "";
    char ch=s[0];
    string ans = movetoend(s.substr(1));

    if(ch=='x') return ans+ch;
    else return ch+ans; 
}

int main()
{
    string s;
    cin>>s;
    cout<<movetoend(s);
    return 0;
}