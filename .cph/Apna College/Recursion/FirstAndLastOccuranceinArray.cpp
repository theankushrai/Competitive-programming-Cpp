 
#include<iostream>
using namespace std;
 
int f_occurance(int key, int n,int i, int a[]){
    if(i==n) return -1;
    if(a[i]==key) return i;
    return f_occurance(key,n,i+1,a);
}
int l_occurance(int key, int n, int l ,int a[]){
    if(l==-1) return -1;
    if(a[l]==key) return l;
    return l_occurance(key,n,l-1,a);
}

int main()
{
    int n,key;
    cin>>n>>key;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<f_occurance(key,n,0,a)<<endl;
    cout<<l_occurance(key,n,n-1,a);
    
    return 0;
}