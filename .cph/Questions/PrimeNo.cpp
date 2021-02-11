 
#include<iostream>
#include<math.h>
using namespace std;
 
int main()
{
    cout<<"Enter the no";
    int n;
    cin>>n;
    bool flag=1;
    if(n==0||n==1) flag=0;
    else{
        for (int i = 2; i <sqrt(n); i++)
        {
            if (n%i==0)
            {
                flag=0;
                break;
            }
            
        }
    }
    str result=(flag==0)? "no is nor prime":"no is prime";
    cout<<result;
    return 0;
}