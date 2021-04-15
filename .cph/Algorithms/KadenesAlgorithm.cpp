// Kardenes algorithm is used to find max sum in asubarray
 
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
    // int currentSum=INT_MIN;
 
    // for (int i = 0; i < n; i++)
    // {
    //     int temp=0;
    //     for (int j = i; j < n; j++)
    //     {
    //         temp+=a[j];
    //         if(temp>currentSum){
    //             currentSum=temp;
    //         }
    //     }
      
        
        
    // }
    // cout<<currentSum;
     int currentmax=a[0];
    int finalmax=a[0];
   
    for (int i = 0; i < n; i++)
    {
        currentmax=max(a[i],currentmax+a[i]);
        finalmax=max(finalmax,currentmax);
    }
    cout<<finalmax;
    return 0;
}