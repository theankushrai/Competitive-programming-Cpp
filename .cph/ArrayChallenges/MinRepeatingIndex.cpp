 
#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int N=1e+2;
    int aidx[N];
    for (int i = 0; i < N; i++)
    {
        aidx[i] =-1;
    }
    int midx=INT16_MAX;

    for (int i = 0; i < n; i++)
    {
        if (aidx[a[i]]!=-1)
        {
            midx=min(midx,aidx[a[i]]);
        }
        else{
            aidx[a[i]]=i;
        }
    }

    if (midx==INT16_MAX)
    {
        cout<<"-1"<<endl;
    }
    else cout<<midx+1<<endl;
 
    return 0;
}