 
#include<iostream>
using namespace std;
 
int main()
{
    int size;
    cin>>size;
    int a[size];
    for (int i = 0; i <size; i++)
    {
        cin>>a[i];
    }
    int length=2;
    int previous_difference=a[1]-a[0];
    int current_subarray_length=2;
    int j =2;
    
    while(j<size){
        if(previous_difference==(a[j]-a[j-1])){
            current_subarray_length++;
        }
        else{
            previous_difference=a[j]-a[j-1];
            current_subarray_length=2;
        }
        length=max(length,current_subarray_length);
        j++;
    }
    cout<<length<<endl;
    
    return 0;
}