#include<math.h> 
#include<iostream>
using namespace std;
 
int main()
{
    int n,digit ;
    cin>>n;
    int result=0;
    int i =0;
    while (n!=0)
    {
        digit=n%2;
        result=result+(digit*pow(10,i));i++;
        n/=2;
    }
    cout<<result;
    
    return 0;
}