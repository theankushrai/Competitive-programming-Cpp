/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-231 <= nums[i] <= 231 - 1*/

// 1. brute force checking for every element n2
//time complexity n2;

 int majorityElement(vector<int>& a) {
        
        int n=a.size();
        int count=a.size()/2;
        
        for(int i =0;i<n;i++){
            int temp=0;
            for(int j =0;j<n;j++){
                if(a[j]==a[i]){
                    temp++;
                    if(temp>count) return a[i];
                }
            }
        }
        return -1;
    }

//2.using unordered map (hashmap)
// time complexity nlogn
//space complexity n;
int majorityElement(vector<int>& a) {
        unordered_map<int,int> temp;
        int count=a.size()/2;
        for(auto it:a){
            temp[it]++;
            if(temp[it]>count)return it;
        }
        return -1;
    }

//3. moores voting algorithm
//time complexity n;

 int majorityElement(vector<int>& a) {
        
        if(n==1)return a[0];//if zero element
        int count=0;
        int el=a[0];
        
        for(auto it: a){
            if(count==0){
                el=it;
                count++;
            }
            else if(it==el)count++;
            else count--;
        }
        // if no majority element
        count=0;
        for(auto it:a){
            if(it==el)count++;
        }
        if(count>(a.size()/2))return el;
        return -1;
    }