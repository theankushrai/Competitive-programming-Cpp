 
#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    char a[n+1];
    cin>>a;
    int high=n-1;
    int low=0;
    bool isPalindrome=true;
    while(low<high){
        if (a[low]==a[high])
        {
                low++;
                high--;
        }
        else {isPalindrome=false; break;}
        
    }
    cout<<isPalindrome;
    return 0;
}