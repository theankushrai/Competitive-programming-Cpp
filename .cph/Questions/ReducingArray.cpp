#include<vector> 
#include<iostream>
#include<algorithm>
using namespace std;
 
bool mycom(pair<int,int> p1, pair<int,int> p2){
    return p1.first<p2.first;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i]   ;
    }

    vector<pair<int,int>> v ;

    for (int i = 0; i < n; i++)
    {
        v.push_back(make_pair(arr[i],i));
    }
    
    sort(v.begin(),v.end(),mycom);
    
    for (int i = 0; i < n; i++)
    {
        arr[i]=v[i].second;
        cout<<arr[i]<<" ";
    }
    

    
    

    return 0;
}