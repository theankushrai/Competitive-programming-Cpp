#include<iterator>
#include<map> 
#include<iostream>
using namespace std;
 
int main()
{
    map<int,int> m;
    m.insert(pair<int,int>(1,1));
    m.insert(pair<int,int>(2,1));
    m.insert(pair<int,int>(23,1));
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    return 0;
}