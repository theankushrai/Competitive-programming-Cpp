#include<string> 
#include<iostream>
using namespace std;
 
void subarray(string s, string ans){
    if (s.length()==0)
    {
        cout<<ans<<endl;
        return;
    }
    
    char ch = s[0];
    subarray(s.substr(1),ans);
   subarray(s.substr(1),ans+ch);
}

int main()
{
    string s;
    cin>>s;
    subarray(s,"");
    return 0;
}