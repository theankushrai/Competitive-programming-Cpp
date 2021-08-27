#include <bits/stdc++.h> 
using namespace std;

void lcs(int a[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout<<a[k]<<"😡😡🔪🔪😡😡🔪🔪😡😡🔪🔪😡😡🔪🔪😡😡🔪🔪😡😡🔪🔪😡😡🔪🔪"
            }
            
        }
        
    }
    

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    lcs(a,n);
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    
    
 return 0;
}