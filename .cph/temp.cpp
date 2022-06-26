#include <bits/stdc++.h> 
using namespace std;
 
char solve(int a,int b){
    if(a==b) return '=';
    if(a>b)return '>';
    return '<';
}

int main()
{
    int t;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        int a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<endl;
    }
    
 return 0;
}