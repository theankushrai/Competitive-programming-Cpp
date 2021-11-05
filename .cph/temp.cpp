#include <bits/stdc++.h> 
using namespace std;
 

    int compareVersion(string v1, string v2) {
        int n1=v1.length();
        int n2=v2.length();
        int i =0;
        int j =0;
        while(i<n1&&j<n2){
            string temp1,temp2;
            
            while(i<n1&&v1[i]!='.')temp1+=v1[i++];
            while(j<n2&&v2[i]!='.')temp2+=v2[j++];
            
            if(stoi(temp1)<stoi(temp2))return -1;
            if(stoi(temp1)>stoi(temp2))return  1;
            
            i++;
            j++;
        }
        return 0;
    }

int main()
{
    string s1,s2;
    cin>>s1>>s2;
   cout<<compareVersion(s1,s2);
 return 0;
}