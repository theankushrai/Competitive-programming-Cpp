#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
 
int main()
{
     string s;
    cin>>s;
    sort(s.begin(),s.end(),greater<int>());
    // int jadoo = stoi(s);
    cout<<s;
    return 0;
}