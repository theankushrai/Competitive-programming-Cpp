/*The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
 

Constraints:

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 104
All integers in nums1 and nums2 are unique.
All the integers of nums1 also appear in nums2.
 */

// 1.brute force - for every element check the next greater element;
//time complexity n2

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i =0;i<nums1.size();i++){
            for(int k=0;k<nums2.size();k++){
                if(nums2[k]==nums1[i]){
                bool found=false;
                for(int j =k+1;j<nums2.size();j++){
                    if(nums2[j]>nums2[k]){
                        ans.push_back(nums2[j]);
                        found=true;
                        break;
                    }
                }
                if(found==false)ans.push_back(-1);
                }
            }
        }
        return ans;
    }
//2. using stack

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans;
        unordered_map<int,int> temp;
        for(int i =nums2.size()-1;i>=0;i--){
            int val=nums2[i];
            while(!st.empty()&&st.top()<val){
                st.pop();
            }
            if(st.empty()) temp[val]=-1;
            else temp[val]=st.top();
            st.push(val);
        }
        for(int i =0;i<nums1.size();i++) ans.push_back(temp[nums1[i]]);
        return ans;
    }

/*Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109*/

vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i =2*n-1;i>=0;i--){
            int val=nums[i%n];
            while(!st.empty()&&st.top()<=val){
                st.pop();
            }
            if(i<n&&!st.empty()){
                ans[i]=st.top();
            }
            st.push(val);
        }
        return ans;
    }

