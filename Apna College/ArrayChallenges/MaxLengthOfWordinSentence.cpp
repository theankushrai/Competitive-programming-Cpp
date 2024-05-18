 
#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    char a[n];
    cin.getline(a,n);
    cin.ignore();

    int temp=0;
    int maxLength=0;
    int i =0;
    while(i<n){
        if (a[i]==' '||a[i]=='\0')
        {
            maxLength=max(temp,maxLength);
            temp=0;
        }
        else
            temp++;

        if (a[i]=='\0')
             break;
         i++;
            
        
        
    }
    
    cout<<maxLength;
    
    return 0;
}