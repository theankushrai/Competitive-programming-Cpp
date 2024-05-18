 
#include<iostream>
using namespace std;
 
int main()
{
    int n,m,target;
    cin>>n>>m>>target;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
        
    }
    int i=0;
    int j=2;
    while(i<n&&j<m){
        if(a[i][j]==target){
            break;
        }
        else if (a[i][j]>target)
        {
            j--;
        }
        else i++;
    }
    cout<<i<<" "<<j;
    return 0;
}