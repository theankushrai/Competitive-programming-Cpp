#include<vector> 
#include<iostream>
#include<string>
using namespace std;
 
int longestsubstring(string a ){
    int maxlen=0,start=-1;
    vector<char> dict(256,-1);
    for (int i = 0; i < a.size(); i++)
    {
        if(dict[a[i]]>start){
            start=dict[a[i]]    ;
        }
        dict[a[i]]=i;
        maxlen=max(maxlen,i-start);
    }
    return maxlen;
}

int main()
{
    string a ="abccabcdaabcdb";
    cout<<longestsubstring(a);
    return 0;
}