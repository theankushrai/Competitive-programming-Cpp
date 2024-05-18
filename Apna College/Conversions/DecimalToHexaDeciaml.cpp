#include<math.h> 
#include<iostream>
using namespace std;
 
int main()
{
    int n,digit ;
    cin>>n;
    string result="";
    while (n!=0)
    {
        digit=n%16;
        switch (digit)
        {   
            case 11:result="A"+result;
            case 12:result="B"+result;
            case 13:result="C"+result;
            case 14:result="D"+result;
            case 15:result="E"+result;
            default: result=to_string(digit)+result;
                    n/=16;
                    break;
        }
        
    }
    cout<<result;
    
    return 0;
}