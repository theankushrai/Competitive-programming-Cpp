 
#include<iostream>
using namespace std;
 
int main()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int a[n1][n2];
    int b[n2][n3];
    int N1=n1;
    int N2=n3;
    int result[N1][N2];

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cin>>a[i][j];
        }
        
    }
     for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            cin>>b[i][j];
        }
        
    }   
    for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < N2; j++)
        {
           result[i][j]=0;
        }
        
    }   
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                result[i][j]+=a[i][k]*b[k][j];
            }
            
        }
        
    }
     for (int i = 0; i < N1; i++)
    {
        for (int j = 0; j < N2; j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }     
    

    
    
    return 0;
}