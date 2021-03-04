 
#include<iostream>
using namespace std;
 
void count_sort(int arr[],int n){
    //making an array of range.
    int k= arr[0];
    for (int i = 1; i < n; i++)
    {
        k=max(arr[i-1],arr[i]);
    }
    

    //initializing count array elements to 0
    int count_arr[10]={0};
    //counting the elements;


    for (int i = 0; i <n; i++)
    {
        count_arr[arr[i]]++;
    }
    // modifying the count array to get position

    for (int i = 1; i <=k; i++)
    {
        count_arr[i]+=count_arr[i-1];
    }
    //modifying original arry for sorted array

    int output[n];
    for (int i = n-1; i >=0; i--)
    {
        output[--count_arr[arr[i]]=arr[i]];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i]=output[i];
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
    count_sort(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    return 0;
}