 
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
    int result=0;
    for(int i =0;i<size;i++){
        int temp=0;
        for(int j=i;j<size;j++){
            temp+=a[j];
            result+=temp;

        }
    }
    // for (int i = 0; i < size; i++)
    // {
    //     result+=a[i]*(size-i)*(i+1);
    // }
    
    cout<<result;
    
    return 0;
}