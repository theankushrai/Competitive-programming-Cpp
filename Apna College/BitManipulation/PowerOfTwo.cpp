// check if the no is power of two;

 
#include<iostream>
using namespace std;
 
bool ispoweroftwo(int n){
    if(n==0)return true;
    else if((n&(n-1))==0) return true;
    else return false;
}

int main()
{
    int n ;
    cin>>n;
    cout<<ispoweroftwo(n);
    return 0;
}