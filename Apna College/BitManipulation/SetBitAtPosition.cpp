 
#include<iostream>
using namespace std;
 
int set_bit(int n,int i){
    return (n|(1<<i));
}

int main()
{
    int n,i;
    cin>>n>>i;
    cout<<set_bit(n,i);
    return 0;
}