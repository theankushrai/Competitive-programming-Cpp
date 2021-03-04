 
#include<iostream>
using namespace std;
 
int partitian(int a[],int l,int r){
    int i=l-1;
    int pivot=a[r];

    for(int j=l;j<r;j++){
        if (a[j]<pivot)
        {
            i++;
            if(a[i]!=a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    a[r]=a[i+1];
    a[i+1]=pivot;
    return i+1;
}

void quicksort(int a[],int l,int r){
    if(l>=r) return;
    int pi = partitian(a,l,r);
    quicksort(a,l,pi-1);
    quicksort(a,pi+1,r);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}