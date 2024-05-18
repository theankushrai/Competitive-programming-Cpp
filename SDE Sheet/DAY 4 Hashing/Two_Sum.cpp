/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/

//1.brute force 
//time complexity n2;
vector<int> twoSum(vector<int>& a, int target) {
        vector<int> ans;
        int n = a.size();
        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]+a[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }

//2. hash table
//time complexity n;
//space complexity n;

vector<int> twoSum(vector<int>& a, int target) {
        vector<int> ans;
        unordered_map<int,int> temp;
        for(int i =0;i<a.size();i++){
            if(temp.find(target-a[i])==temp.end())temp[a[i]]=i;
            else{
                ans.push_back(temp[target-a[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }