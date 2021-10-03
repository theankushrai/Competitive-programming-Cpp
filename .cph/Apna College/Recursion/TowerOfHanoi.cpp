 
#include<iostream>
using namespace std;
 
void towerOfHanoi(int n, char src, char dstn, char hlpr){
    if(n==0) return;//base case
    towerOfHanoi(n-1,src,hlpr,dstn);
    cout<<"move from "<<src<<" to "<<dstn<<endl;
    towerOfHanoi(n-1,hlpr,dstn,src);
}

int main()
{
    int n;
    cin>>n;
    char src,dstn,hlpr;
    cin>>src>>dstn>>hlpr;
    towerOfHanoi(n,src,dstn,hlpr);
    return 0;
}