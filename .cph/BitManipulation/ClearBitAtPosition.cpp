 
#include<iostream>
using namespace std;
 
int clear_bit(int n,int i){
    int mask = ~(1<<i);
    return (n&mask);
}

int main()
{
    int n,i;
    cin>>n>>i;
    cout<<clear_bit(n,i);
    return 0;
}