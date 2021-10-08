/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
// 1.brute force sort and find
//time complexity nlogn

int longestConsecutive(vector<int>& a) {
        if(a.size()==0)return 0;
        sort(a.begin(),a.end());
        int maxl=1;
        int curr=1;
        for(int i =1;i<a.size();i++){
            if(a[i]==a[i-1]+1)curr++;
            else if(a[i]==a[i-1])continue;
            else curr=1;
            maxl=max(curr,maxl);
        }
        return maxl;
    }

//2.using hashset 
//time compleixty 3n

int longestConsecutive(vector<int>& a) {
        if(a.size()==0)return 0;
        unordered_set<int> temp(a.begin(),a.end());//pushing everything in hashset
        int maxl=1;
        for(int i=0;i<a.size();i++){
            if(temp.find(a[i]-1)!=temp.end())continue;
            else{//if number-1 is not present  i.e number is the least no
                int j=1;
                int count=1;
                while(temp.find(a[i]+j)!=temp.end()){//check how many no in order more then number is preseent
                    count++;
                    j++;
                }
                maxl=max(maxl,count);
            }
        }
        return maxl;
    }