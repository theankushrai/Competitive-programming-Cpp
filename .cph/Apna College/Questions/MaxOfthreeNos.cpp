 
#include<iostream>
using namespace std;

int max(int a, int b, int c){
    if(a>b&&a>c) return a;
    else if(b>a && b>c) return b;
    else return c;
} 

int main()
{
    cout<<"Enter the three nos";
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max(a,b,c);
    return 0;
}