/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/
// 1.brute force
// time complexity n4;
vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        int n = a.size();
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                for(int k =j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                      if(a[i]+a[j]+a[k]+a[l]==target)ans.push_back({a[i],a[j],a[k],a[l]});
                    }
                }
            }
        }
        return ans;
    }
//2, Three pointer +binary search
//time complexity n3logn+nlogn;
vector<vector<int>> fourSum(vector<int>& a, int target) {
        sort(a.begin(),a.end());
        vector<vector<int>> ans;
        int n = a.size();
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                for(int k =j+1;k<n;k++){
                   if(binary_search(a.begin()+k+1,a.end(),target-(a[i]+a[j]+a[k]))){
                        ans.push_back({a[i],a[j],a[k],target-(a[i]+a[j]+a[k])});
                   }
                }
            }
        }
        return ans;
    }

//3. Two pointer + 2 sum property
//time complexity nlog n +n2+n

vector<vector<int>> ans;