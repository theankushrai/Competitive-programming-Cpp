// subset of an array using bit manipulation

 
#include<iostream>
using namespace std;
 
void subsets(int n, int a[]){
    for (int i = 0; i < (1<<n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i&(1<<j)) //(i&(i<<j)==true)
            {
                cout<<a[j]<<" ";
            }
            
        }cout<<endl;
        
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
    subsets(n,a);

    
    return 0;
}