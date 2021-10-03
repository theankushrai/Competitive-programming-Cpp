// print words from phone digits

#include<string> 
#include<iostream>
using namespace std;

 string keypadArr[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s , string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code= keypadArr[ch-'0'];
    for (int i = 0; i < code.length(); i++)
    {
        keypad(s.substr(1),ans+code[i]);
    }
    
}


int main()
{
    string s;
    cin>>s;
   
    keypad(s,"" );
    return 0;
}