
#include<iostream>
using namespace std;
 
 
void bubble_sort(int a[],int size){
    bool swapped=false;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapped=true;
            }
        }
     if(swapped=false) break;   
    }

}
bool isSumK(int a[],int n,int k){
    bubble_sort(a,n);
    int low=0;
    int high = n-1;
    while(low<high){
        if(a[low]+a[high]==k) return true;
        else if(a[low]+a[high]<k) low++;
        else high--;
    }
    return false;
}
 
int main()
{
    int k;
    cin>>k;
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<isSumK(a,n,k);

    
    
    return 0;
}