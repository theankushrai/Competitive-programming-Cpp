// check if a given array is sorted or not

 
#include<iostream>
using namespace std;
 
bool is_sorted(int n, int a[]){
    if(n==0||n==1) return true;
    if(a[n-1]<a[n-2]) return false;
    return is_sorted(n-1,a);
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
    cout<<is_sorted(n,a);
    
    return 0;
}