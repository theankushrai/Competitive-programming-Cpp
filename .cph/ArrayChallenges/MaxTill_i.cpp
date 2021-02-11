 
#include<iostream>
using namespace std;
 
int main()
{
    int size;
    cin>>size;
    int a[size];
    for (int i = 0; i <=size; i++)
    {
        cin>>a[i];
    }
    int mx=a[0];
    for (int i = 0; i <= size; i++)
    {
        mx=max(mx,a[i]);
        
    }
    cout<<mx;
    
    
    return 0;
}