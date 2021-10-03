// 0
// 1 0
// 0 1 0
// 1 0 1 0                       
// 0 1 0 1 0


#include<iostream>
using namespace std;
 
int main()
{
    for (int i = 1; i <=5; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout<<(i+j+1)%2<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}