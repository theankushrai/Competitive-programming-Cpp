 
#include<iostream>
using namespace std;
 
int main()
{   int sum;
    cin>>sum;
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int j=0;
    int start=0;
    int curr_sum=0;
    int end=0;
  while(j<n){
      curr_sum+=a[j];
      if (curr_sum<sum)
        {
            j++;
        }
        else if(curr_sum>sum){
            start++;
            curr_sum=0;
            j=start;
        }
         else{
            end=j;
            break;
        }
         

        
  }
    if (end==0)
    {
        cout<<"no subarray";
    }
    else{
        for (int i = start; i <= end; i++)
        {
            cout<<a[i]<<" ";
        }
        
    }
    return 0;
}