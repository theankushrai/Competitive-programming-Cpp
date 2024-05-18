/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
*/

// 1.brute force- counting each element
//time complexity n2
vector<int> majorityElement(vector<int>& a) {
        int n=a.size();
        int count=floor((float)n/3);
        unordered_set<int> s;
        
        for(int i =0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(a[i]==a[j]){
                    temp++;
                    if(temp>count) s.insert(a[i]);
                }
            }
        }
        vector<int> ans(s.begin(),s.end());
        return ans;
    }
//2.sort and count
//time compelxity nlogn;
//space complexity 0;
int majorityElement(vector<int>& nums) {
        int n =nums.size();
        if(n==1)return nums[0];
        sort(nums.begin(),nums.end());
        int count=0;
        int curr=nums[0];
        int limit=n/3;
        for(int i =1;i<n;i++){
            if(nums[i]==curr)count++;
            else{
                curr=nums[i];
                count=1;
            }
            if(count>limit)return curr;
        }
        return 0;
    }
//3.using hashmap
//time complexity n/ nlogn
vector<int> majorityElement(vector<int>& a) {
        unordered_map<int,int> temp;
        vector<int> ans;
        int count=a.size()/3;
        for(auto it:a){
            temp[it]++;
            if(temp[it]>count)ans.push_back(it);
        }
        return ans;
    }

//4. modified moores voting algorithm
//time complexity 0n
vector<int> majorityElement(vector<int>& a) {
        int c1=0,c2=0;
        int el1=-1,el2=-1;
        
        for(auto it:a){
            if(it==el1){
                c1++;
            }
            else if(it==el2){
                c2++;
            }
            else if(c1==0){
                el1=it;
                c1++;
            }
            else if(c2==0){
                el2=it;
                c2++;
            }
            
            else{
                c1--;
                c2--;
            }
        }
        int count=a.size()/3;
        c1=c2=0;
        for(auto it:a){
            if(it==el1)c1++;
            else if(it==el2)c2++;
        }
        vector<int> ans;
        if(c1>count)ans.push_back(el1);
        if(c2>count)ans.push_back(el2);
        return ans;
    }