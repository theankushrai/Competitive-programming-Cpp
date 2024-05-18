// all the nos are repeated except one. find that no;

 
#include<iostream>
using namespace std;
 
int get_bit(int n,int pos){
    return (n&(1<<pos))!=0;
}

int set_bit(int n, int pos){
    return n|(1<<pos);
}


int unique_no(int n, int a[]){
    int result=0;
    //i is position array from position 0 to 63
for (int i = 0; i < 64; i++)
{
    int sum=0;
    //j is no array to check whether the bit at given position occurs three times or not
    for(int j =0;j<n;j++){
        if(get_bit(a[j],i)){
            sum++;
        }
    }
    if (sum%3!=0)
    {
       result= set_bit(result,i);
    }
    
}
return result;
    
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
    cout<<unique_no(n,a);
    
    return 0;
}