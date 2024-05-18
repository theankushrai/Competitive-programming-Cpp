 
#include<iostream>
using namespace std;
 
void insertion_sort(int a[],int size){
    for (int i = 1; i < size; i++)
    {
        int key=a[i];
        int j =i-1;
        
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    
}

int main()
{
    int size;
    cin>>size;
    int a[size];

    for(int i =0;i<size;i++) cin>>a[i];
    insertion_sort(a,size);
    for(int i =0;i<size;i++) cout<<a[i]<<" ";
    return 0;
}