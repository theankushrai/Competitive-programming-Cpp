 
#include<iostream>
#include<math.h>
using namespace std;
 
int main()
{
    int n,digit;
    int sum=0;
    cout<<"Enter the no";
    cin>>n;
    int number=n;
    while(n!=0){
        digit=n%10;
        sum+=pow(digit,3);
        n/=10;
    }
    if (sum==number)
    {
        cout<<"armstrong no";
    }else cout<<"not an armstrong no";
    
    return 0;
}