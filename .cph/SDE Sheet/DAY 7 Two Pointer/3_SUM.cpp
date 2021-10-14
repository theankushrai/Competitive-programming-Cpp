/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []
Example 3:

Input: nums = [0]
Output: []
 

Constraints:

0 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

//1.brute force 
// time complexity n3+nlogn(insertion)
//space complexity n;

vector<vector<int>> threeSum(vector<int>& a) {
        set<vector<int>> temp;
        int n = a.size();
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                for(int k =j+1;k<n;k++){
                    if(a[i]+a[j]+a[k]==0) if(i!=j!=k){
                        vector<int> arr={a[i],a[j],a[k]};
                        sort(arr.begin(),arr.end());
                        temp.insert(arr);
                    }
                }
            }
        }
        vector<vector<int>> ans(temp.begin(),temp.end());
        return ans;
    }

// 2. using hashmap
//time complexity n2;
//space complexity n
vector<vector<int>> threeSum(vector<int>& a) {
        unordered_map<int,int> temp;
        set<vector<int>> s;
        int n = a.size();
        
        //insertion in hash table
        for(int i =0;i<n;i++)temp[a[i]]++;
        for(int i =0;i<n;i++){
            t1=temp[a[i]];
            if(temp[a[i]]==1)temp.erase(a[i]);
            else temp[a[i]]--;
            for(int j =i+1;j<n;j++){
                t2=temp[a[j]];
                if(temp[a[j]]==1)temp.erase(a[j]);
                else temp[a[j]]--;
                if(i!=j)if(temp.find(-a[i]-a[j])!=temp.end()){
                    vector<int> arr={a[i],a[j],-a[i]-a[j]};
                    sort(arr.begin(),arr.end());
                    s.insert(arr);
                }
                temp[a[j]]++;;
            }
            temp[a[i]]++;
        }
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
//3. loop and 2 pointer
//time complexity n2;
//space complexity O(1);

int inc(vector<int>& a, int i){
        while(i+1<a.size()&&a[i+1]==a[i])i++; 
        i++;
        return i;
    }
    int red(vector<int>& a, int i){
        while(i-1>=0&&a[i-1]==a[i])i--;
        i--;
        return i;
    }
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        if(a.size()<3)return ans;
        sort(a.begin(),a.end());   
        
        
        int i =0;
        while(i<a.size()-2){
            int target=-a[i];
            int l=i+1;
            int r=a.size()-1;
            while(l<r){
                if(a[l]+a[r]==target){
                    ans.push_back({a[i],a[l],a[r]});
                    l=inc(a,l);
                    r=red(a,r);
                    }
                else if(a[l]+a[r]>target) r=red(a,r);
                else l=inc(a,l);
            }
            i=inc(a,i);
        }
        return ans;
    }