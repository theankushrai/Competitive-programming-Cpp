 
#include<iostream>
using namespace std;

int factorial(int n){
    if (n<=1) return 1;
    else {
        return n* factorial(n-1);
    }
} 

int main()
{
    cout<<"Enter N and R";
    int N,R;
    cin>>N>>R;
    cout<<(factorial(N))/(factorial(N-R)*factorial(R));
    return 0;
}
