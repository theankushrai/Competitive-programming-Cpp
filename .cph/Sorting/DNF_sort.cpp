 
#include<iostream>
using namespace std;

void swp(int a[],int n1, int n2){
    int temp=a[n1];
    a[n1]=a[n2];
    a[n2]=temp;
}

void dnf_sort(int a[],int n){
   int low=0;
   int mid=0;
    int high=n-1;
    while(mid<=high){
        if(a[mid]==0){
            swp(a,mid,low);
            low++;
            mid++;

        }
        else if(a[mid]==2){
            swp(a,mid,high);
            high--;
        }
        else{
            mid++;
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
    dnf_sort(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
  
    return 0;
}