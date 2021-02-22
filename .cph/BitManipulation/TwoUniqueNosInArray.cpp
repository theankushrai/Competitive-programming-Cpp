// all the nos are repeated except two. find that no;

 
#include<iostream>
using namespace std;
 
 //returns if setbit is in given position or not
bool set_bit(int n, int pos){
    return ((n&(1<<pos))!=0);
}

void unique_no(int n, int a[]){
    int xorsum=0;
    for (int i = 0; i < n; i++)
    {
        xorsum^=a[i];
    }
    int tempxor=xorsum;
    //finding the rightmost set bit in xorsum
    int setbit=0;
    int pos=-1;
    while(setbit!=1){
        setbit=tempxor&1;
        pos++;
        tempxor=tempxor>>1;
    }
    int newxor=0;
    for (int i = 0; i < n; i++)
    {
        if (set_bit(a[i],pos))
        {
            newxor^=a[i];
        }
        
    }
    cout<<newxor<<endl;
    cout<<(newxor^xorsum);
    
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
    unique_no(n,a);    
    return 0;
}