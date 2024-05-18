 
#include<iostream>
using namespace std;
 
int toggle_bit(int n , int i){
    return (n xor(1<<i));
}

int main()
{
    int n,i;
    cin>>n>>i;
    cout<<toggle_bit(n,i);
    return 0;
}