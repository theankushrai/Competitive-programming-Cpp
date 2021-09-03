#include "bits/stdc++.h"
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int idx) {
    if (idx == nums.size()) {
        cout<<nums<<endl;
        return ;
    }
    for (int i = idx; i < nums.size(); i++) {
        if(i != idx and nums[i]==nums[idx])
            continue;
        swap(nums[i], nums[idx]);
        solve(nums, ans, idx + 1);
        
}
}

vector<vector<int>> permute(vector<int> nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    solve(nums,ans,0);
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &it: a){
        cin>>it;
    }
    vector<vector<int>> ans=permute(a);
    for(auto i:ans){
        for(auto j: ){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}