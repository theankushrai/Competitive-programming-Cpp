#include<string>
#include<iostream>
using namespace std;
 
void countPath(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    
    for(int i =0;i<s.length();i++){
        char ch = s[i];
        string ros=s.substr(0,i)+s.substr(i+1);
        countPath(ros,ans+ch);
    }
}

int main()
{
    string s;
    cin>>s;
    countPath(s,"");
    return 0;
}