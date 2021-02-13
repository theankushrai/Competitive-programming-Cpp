 
#include<iostream>
using namespace std;
 

int kadenes(int a[],int n){
    int currentmax=a[0];
    int finalmax=a[0];
   
    for (int i = 0; i < n; i++)
    {
        currentmax=max(a[i],currentmax+a[i]);
        finalmax=max(finalmax,currentmax);
    }
    return finalmax;
    
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    int array_sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        array_sum+=a[i];
    }
    int wrapSum,nonWrapSum;
    nonWrapSum=kadenes(a,n);
    for (int i = 0; i < n; i++)
    {
        a[i]=-a[i];
    }
    
    wrapSum=array_sum+kadenes(a,n);
    cout<<max(nonWrapSum,wrapSum);
    
    
    return 0;
}