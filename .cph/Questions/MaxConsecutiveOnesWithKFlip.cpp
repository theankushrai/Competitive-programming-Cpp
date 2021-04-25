//binary array find maximum consecutive ones where you can flip k zeroes;

#include<iostream>
using namespace std;
 
int maxOnes(int a[],int n,int k){
    int maxones=0;
    int i =0;
    int zerocount=0;
    for (int j = i; j < n; j++)
    {
        if(a[j]==0) zerocount++;
        while(zerocount>k){
            if(a[i]==0){
                zerocount--;
            }
            i++;
        }
        maxones=max(j-i+1,maxones);
    }
    return maxones;
    
}

int main()
{
    int k =3;
    int a[] ={0,1,1,1,0,0,0,1,1,0};
    cout<<maxOnes(a,10,k)<<endl;
    return 0;
}