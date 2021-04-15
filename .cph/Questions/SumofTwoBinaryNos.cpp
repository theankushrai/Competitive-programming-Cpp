#include<math.h>
#include<iostream>
using namespace std;
 
int main()
{
    int a, b, da=0,db=0,result=0,i=0,sum=0;
    bool carry=false;
    cin>>a>>b;
    while(a!=0||b!=0){
        da=a%10;
        db=b%10;
        a/=10;
        b/=10;

    if(carry){
        if(da==1&&db==1) {sum=1; carry=true;}
        else if(da==0&&db==0) {sum=1; carry=false;}
        else {sum=0; carry=true;}
    }
    else{
        if(da==1&&db==1)  {sum=0; carry=true;}
        else if(da==0&&db==0) {sum=0; carry=false;}
        else {sum=1; carry=false;}
    }

    result=result+(sum*pow(10,i));i++;
    }
    if(carry){
        result=result+(1*pow(10,i));i++;
    }
    cout<<result;
    return 0;
}