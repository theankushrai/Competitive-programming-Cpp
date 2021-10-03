#include <bits/stdc++.h> 
using namespace std;
 
void shellSort(int a[],int n){
    int gap=ceil((float)n/2);
    cout<<gap<<endl;
    while(gap>0){
        int i =0;
        int j =gap;
        while(j<n){
            if(a[i]>a[j]) swap(a[i],a[j]);
            i++;j++;
        }
        if(gap==1)break;
        gap=ceil(gap/2);
        cout<<gap<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++)cin>>a[i];
    shellSort(a,n);
    for(int i =0;i<n;i++)cout<<a[i]<<" ";
 return 0;
}