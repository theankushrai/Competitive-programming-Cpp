// Given a "2xn" board and tiles of size "2x1" . Count the no of ways to tile a given board;

 
#include<iostream>
using namespace std;

int tilingways(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    return tilingways(n-1)+tilingways(n-2);// it becomes a formula of a fibonacci sequence
} 

int main()
{
    int n;
    cin>>n;
    cout<<tilingways(n);
    return 0;
}