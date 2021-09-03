#include <bits/stdc++.h> 
using namespace std;
#include<unor
 
void move(int a[],int n){
   int low=0;
    int mid=0;
    while(low<=mid&&mid<n){
        if(a[mid]<0){
            swap(a[mid],a[low]);
            mid++;
            low++;
          }
        else mid++;
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

    move(a,n);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    

 return 0;
}