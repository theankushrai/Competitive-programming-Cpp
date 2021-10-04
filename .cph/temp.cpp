#include <bits/stdc++.h> 
#include<vector>
using namespace std;
 
int combination(float i,float j){
        if(i==0||j==0)return 1;
        j=min(i-j,j);
        float res=1;
        while(i>j&&j>0)
           res*=(i--/j--);
        return res;
    }

int main()
{
  cout<<combination(7,5);
 return 0;
}