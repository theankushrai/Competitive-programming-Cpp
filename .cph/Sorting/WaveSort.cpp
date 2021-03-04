 
#include<iostream>
using namespace std;
 void swp(int a[],int n1, int n2){
    int temp=a[n1];
    a[n1]=a[n2];
    a[n2]=temp;
}
void wave_sort(int a[],int n){
    for (int i = 1; i < n; i=i+2)
    {
        if(a[i]>a[i-1]) swp(a,i,i-1);
         if((a[i]>a[i+1])&&i<=n-2)swp(a,i,i+1);
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
    wave_sort(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    
    return 0;
}