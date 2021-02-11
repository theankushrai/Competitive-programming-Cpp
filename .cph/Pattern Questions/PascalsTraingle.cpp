 
#include<iostream>
using namespace std;
 

int factorial(int n){
    if (n<=1) return 1;
    else {
        return n* factorial(n-1);
    }
} 
int NCR(int n,int r){
    return (factorial(n))/(factorial(n-r)*factorial(r));
}

int main()
{
    cout<<"Enter the no of rows";
    int row;
    cin>>row;
    int a[row][row];

    for (int i = 1; i <=row; i++)
    {
        for (int j = 0; j <i; j++)
        {
            cout<<NCR(i,j)<<"";
        }
        cout<<endl;
    }
    return 0;
}