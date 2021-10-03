// all the nos are repeated except one. find that no;

 
#include<iostream>
using namespace std;
 
int unique_no(int n, int a[]){
    int un=0;
    for (int i = 0; i < n; i++) 
    {
        un^=a[i];
    }
    return un;
    
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<unique_no(n,a);
    
    return 0;
}