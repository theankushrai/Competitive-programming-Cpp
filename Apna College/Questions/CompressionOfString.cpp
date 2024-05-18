// Compression means removing of consecutive repeating characters

 
#include<iostream>
#include<string>
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    char ans[s.size()+2];
    int j =1;
    ans[0]=s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i]!=s[i-1]){
            ans[j]=s[i];
            j++;
        }
        
    }
    cout<<ans;
    
    return 0;
}