#include<vector>
#include<stack> 
#include<iostream>
using namespace std;
 
int largest_area(vector<int> a){
    stack<int> st;
    int n =a.size();
    int ans=0;
    int i =0;

    //push 0 in stack so that stack is not empty;
    st.push(0);
    while(i<n){
        while(!st.empty()&& a[i]<a[st.top()]){
            int h =a[st.top()];
            st.pop();
            if(st.empty()){
                ans=max(ans,h*i);
            }else{
                int len=i-st.top()-1;
                ans=max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;

}

int main()
{
    vector<int> a ={2,1,5,6,2,3};
    cout<<largest_area(a)<<endl;
    return 0;
}