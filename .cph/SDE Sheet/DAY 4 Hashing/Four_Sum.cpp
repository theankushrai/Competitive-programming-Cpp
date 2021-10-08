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
//time complexity n3 = n2for loop and n for 2 sum

int skipduplicates(vector<int>& a,int i){
        while(i+1<a.size()&&a[i+1]==a[i])i++;
        return i;
    }
    int skipr(vector<int>&a,int r){
         while(r-1>=0&&a[r-1]==a[r])r--;  
        return r;
    }
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        vector<vector<int>> ans;
        int n=a.size();
        if(n<4)return ans;
        sort(a.begin(),a.end());
        
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l=j+1,r=n-1;
                int temp=target-a[i]-a[j];
                //two sum
                while(l<r){
                    if(a[l]+a[r]==temp){
                        ans.push_back({a[i],a[j],a[l],a[r]});
                        l=skipduplicates(a,l);
                        l++;
                        r=skipr(a,r);
                        r--;
                    }
                    else if(a[l]+a[r]<temp){
                        l=skipduplicates(a,l);
                        l++;
                    }
                    else{
                        r=skipr(a,r);
                        r--;
                    }
                }
                j=skipduplicates(a,j);
            }
            i=skipduplicates(a,i);
            
        }
        
        return ans;
    }
