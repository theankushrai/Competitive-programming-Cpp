// if we have to find the no of students who have taken both spanish and french. i add only frech and spanish and remove comon students

// find the no between 1 and n divisible by both a and b;

 
#include<iostream>
using namespace std;
 
void divisible(int n, int a, int b){
    int c1=n/a;
    int c2= n/b;
    int c3= n/(a*b);
    cout<<c1+c2-c3;
}

int main()
{
    int n;
    cin>>n;
    int a, b;
    cin>>a>>b;
    divisible(n,a,b);
    return 0;
}