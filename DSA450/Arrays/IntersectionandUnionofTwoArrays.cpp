vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u;
        for(auto it: nums1){
            u.insert(it);
        }
        vector<int> ans;
        int count=0;
        for(auto it: nums2){
            if(u.find(it)!=u.end()){
                ans.push_back(it);
                u.erase(it);
            }
        }
        
        return ans;
    }

vector<int> union(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> u;
        for(auto it: nums1){
            u.insert(it);
        }
        for(auto it: nums2){
            u.insert(it);
        }
        vector<int> ans;
        for(auto it: u){
            ans.push_back(it);
        }
        
        return ans;
    }
