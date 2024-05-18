#include<vector>
#include<algorithm>
#include<stack> 
#include<iostream>
using namespace std;
 
vector<int> stockspan(vector<int> a){
    vector<int> ans;
    stack<pair<int,int>> st;    
    for (auto price:a)
    {
        int days = 1;
        while(!st.empty()&&st.top().first<=price){
             days+=st.top().second;
             st.pop();
        }
        st.push(make_pair(price,days));
        ans.push_back(days);
    }
    return ans;
    
}

int main()
{
    vector<int> a={100,80,60,70,60,75,85};
    vector<int> v= stockspan(a);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}