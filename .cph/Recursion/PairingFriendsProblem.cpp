// find the no of ways in whicha  friend can be single or can be paired up

 
#include<iostream>
using namespace std;

int pairingways(int n){
    // if(n==0) return 0;
    // if(n==1) return 1;
    // if(n==2) return 2;
    if(n<=2) return n;

    return pairingways(n-1)+pairingways(n-2)*(n-1);
} 

int main()
{
    int n;
    cin>>n;
    cout<<pairingways(n);
    return 0;
}