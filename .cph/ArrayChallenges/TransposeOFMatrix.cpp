 
#include<iostream>
#include<math.h>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    // int t[m][n];
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         t[i][j]=a[j][i];
    //     }
        
    // }
    //    for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout<<t[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
       for (int i = 0; i <sqrt(n) ; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
        
    }
       for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}