 
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