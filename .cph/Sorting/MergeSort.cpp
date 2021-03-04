#include<iostream>
using namespace std;
 
void merge(int arr[], int mid, int l , int r){
    //initailaizing two arrays
    
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];

    for (int i = 0; i < n1; i++)
    {
        a[i]=arr[i+l];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i]=arr[mid+1+i];
    }
    //replacing old array with merged sorted array

    int i =0,j=0,k=l;

    while(i<n1&&j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
        }
    }

    // if either i or j has not reached n1 or n2

    while(i<n1){
        arr[k]=a[i];
            i++;
            k++;
    }
    while(j<n2){
        arr[k]=b[j];
            j++;
            k++;
    }    
}

void mergesort(int arr[],int l, int r){
    if(l>=r) return ;
    int mid = (l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,mid,l,r);
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

    mergesort(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}