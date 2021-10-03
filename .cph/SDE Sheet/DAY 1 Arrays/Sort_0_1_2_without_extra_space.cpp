/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is 0, 1, or 2.
*/

// 1. brute force - sort array
// time compelxity - nlogn
// space complexity -1

void sortColors(vector<int>& a) {
        sort(a.begin(),a.end());
    }

//2. count sort 
//time complexity - 2n;
//space complexity - 3
 void sortColors(vector<int>& a) {
        
        int zero=0;
        int one = 0;
        int two=0;
        
        for(auto it:a){
            if(it==0)zero++;
            else if(it==1)one++;
            else two++;
        }
        for(int i =0;i<zero;i++){
            a[i]=0;
        }
        for(int i =zero;i<zero+one;i++){
            a[i]=1;
        }
        for(int i =zero+one;i<a.size();i++){
            a[i]=2;
        }
    }

// 3. DNF sort algorithm
// time complexity - n;
// space complexity -1

void sortColors(vector<int>& a) {
       
        int low=0;
        int mid=0;
        int high=a.size()-1;
        while(mid<=high){
            if(a[mid]==0) swap(a[mid++],a[low++]);
            else if(a[mid]==1) mid++;
            else swap(a[mid],a[high--]);
        }
    }