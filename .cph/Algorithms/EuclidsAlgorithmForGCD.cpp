// finding gcd or HCF between two nos

 
#include<iostream>
using namespace std;
 
int gcd(int a, int b){
    int reminder=a%b;
    while(reminder!=0){
        a=b;
        b=reminder;
        reminder=a%b;
    }
    return b;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}