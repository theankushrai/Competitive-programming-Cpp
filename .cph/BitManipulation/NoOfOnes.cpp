// no of ones in binary representation of the no;

 
#include<iostream>
using namespace std;
 
 int noOFONes(int n){
     int count=0;
     while(n!=0){
         n=n&(n-1);
         count++;
     }
     return count;
 }

int main()
{
    int n;
    cin>>n;
    cout<<noOFONes(n);
    return 0;
}