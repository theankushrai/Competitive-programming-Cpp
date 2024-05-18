/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

// 1.using recursion;
// time complexity 2^n;
// space complexity n

    void subset(vector<int> &a,int idx,vector<int> &temp,vector<vector<int>>& ans){
        ans.push_back(temp);
        for(int i =idx;i<a.size();i++){
            if(i!=idx&&a[i]==a[i-1])continue;
            temp.push_back(a[i]);
            subset(a,i+1,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(a.begin(),a.end());
        subset(a,0,temp,ans);
        return ans;
    }
