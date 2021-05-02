#include<iostream>
#include<algorithm>
using namespace std;

long int gcd(long int a, long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

long int solution(long int a,long int b){
    long int count=0;
    for (long int i = 2; i <= gcd(a,b); i++)
    {
        if(((a%i)==0)&&((b%i)==0)) count++;
    }
    return count+1;
    
}
int  main()
{
    long int a,b;
    cin>>a>>b;
    cout<<solution(a,b);
    return 0;
    
}