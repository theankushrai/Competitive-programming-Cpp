// path from start to end in an array matrix of size n;

 
#include<iostream>
using namespace std;

int count(int n, int i,int j) {
    if(j==n-1||i==n-1) return 1;
    if(j>n||i>n) return 0;

    return count(n,i+1,j)+count(n,i,j+1);
}

int main()
{
    int n;
    cin>>n;
    cout<<count(n,0,0);
    return 0;
}