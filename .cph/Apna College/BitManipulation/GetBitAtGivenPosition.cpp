 
#include<iostream>
using namespace std;
 
int main()
{
    int n,i;
    cin>>n>>i;
    int temp= 1<<i;
    n=temp&n;
    if (n!=0&&(n>>i)!=0)
    {
        cout<<1;
    }
    else cout<<0;
    
    return 0;
}