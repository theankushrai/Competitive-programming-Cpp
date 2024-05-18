// remove duplicate character from a string

 
#include<iostream>
#include<string>
using namespace std;
 
string compress(string s){
    if(s.length()==0) return "";
    char ch=s[0];
    string ans=compress(s.substr(1));
    
    if(ch==ans[0]) return ans;
    else return (ch+ans);
}

int main()
{
    string s;
    cin>>s;
    cout<<compress(s);
    return 0;
}