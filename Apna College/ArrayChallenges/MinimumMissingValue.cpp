 
#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int N=1e6+2;
    bool barray[N];
    for (int i = 0; i < N; i++)
    {
        barray[i]=false;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]>=0)
        {
            barray[a[i]]=true;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (barray[i]==false)
        {
            cout<<i;
            break;
        }
        
    }
    
    
    
    return 0;
}