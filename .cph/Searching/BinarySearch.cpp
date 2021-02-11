 
#include<iostream>
using namespace std;
 
int binary_search(int array[], int size, int key){
    int s=0;
    int e=size-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(key<array[mid]) e=mid-1;
        else if(key>array[mid]) s=mid+1;
        else return mid;
    }
    return -1;
}


int main()
{
    int size; int key; int array[size];
    cin>>size;
    cin>>key;

    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
    }
    cout<<binary_search(array ,size ,key);
    
    return 0;
}