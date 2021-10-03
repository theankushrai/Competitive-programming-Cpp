 
#include<iostream>
using namespace std;
 
int max(int a, int b, int c){
    if(a>b&&a>c) return a;
    else if(b>a && b>c) return b;
    else return c;
}  
bool ifPythagorusTriplet(int a, int b, int c) {
    switch (max(a,b,c))
    {
    case a:
        return a*a==b*b+c*c;
    case b:return b*b==a*a+c*c;
    case c: return c*c==a*a+b*b;
    }
}
int main()
{
    cout<<"Enter the three nos";
    int a,b,c   ;
    cin>>a>>b>>c;
    cout<<ifPythagorusTriplet(a,b,c);
    return 0;
}