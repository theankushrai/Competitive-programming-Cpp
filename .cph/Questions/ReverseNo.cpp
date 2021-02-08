#include<math.h>
#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cout<<"Enter the no";
    cin>>n;
    int digit;
    int reversedn=0;
    while(n!=0){
        digit=n%10;
        reversedn=reversedn*10+digit;
        n/=10;
    }
    cout<<reversedn;
    return 0;
}