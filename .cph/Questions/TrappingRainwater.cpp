#include<stack>
#include<vector> 
#include<iostream>
using namespace std;
 
int rainwater(vector<int> a ){
    stack<int> st;
    int n =a.size(),ans=0;

    for (int i = 0; i < n; i++)
    {
        while(!st.empty()&&a[st.top()]<a[i]){
            int cur=st.top();
            st.pop();

            if(st.empty()) break;
            int diff=i-st.top()-1;
            ans+=(min(a[st.top()],a[i]))*diff;
        }
        st.push(i);
    }
    return ans; 
    
}

int main()
{
    vector<int> v={2,0,2};
    cout<<rainwater(v)<<endl;
    return 0;
}