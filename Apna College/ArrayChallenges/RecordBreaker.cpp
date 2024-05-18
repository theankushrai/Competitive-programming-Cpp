 
#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    a[n]=-1;
    int answer=0;
    int mx=0;
    if (n==0)
    {
        answer==1;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]>a[mx]) 
        {
            if (a[i]>a[i+1])
            {
                mx=i;
                answer++;
            }
            
        }
        
    }
    cout<<answer;
    
    return 0;
}