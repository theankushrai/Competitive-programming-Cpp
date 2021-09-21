#include <bits/stdc++.h> 
#include<string>
using namespace std;
 
int solve(int n ,string s){
    int count=0;
    int l=INT_MAX;
    for(int i =0;i<n;i++){
        if(s[i]=='1'){
            l=i;
            continue;
        }
        
        int r=INT_MAX;
        for(int j =i+1;j<n;j++){
            if(s[j]=='1') {
                    r=j;
                    break;
                }
            }
        if(l==INT_MAX&&r==INT_MAX) return 0;
        count+=(min(abs(l-i),abs(r-i)));
    }
    return count;
}

int main()
{
    int t;
    cin>>t;
    for(int i =0;i<t;i++){
        int n;
        string s;
        cin>>n>>s;
        cout<<"case #"<<i+1<<": "<<solve(n,s)<<endl;

    }
 return 0;
}