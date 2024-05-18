 
#include<iostream>
using namespace std;
 
void bubble_sort(int a[],int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(a[j]<a[i]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        
    }

}

int main()
{
    int size;
    cin>>size;
    int a[size];
    for(int i =0;i<size;i++) cin>>a[i];
    bubble_sort(a,size);
    for (int i =0;i<size;i++) cout<<a[i]<<" ";
    
    return 0;
}