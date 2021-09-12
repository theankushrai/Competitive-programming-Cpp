/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

// 1. count each element using hash table time complexity 2n space complexity n

//2. moores voting algorithm time n space 1
int majorityElement(vector<int>& a) {
        
        pair<int,int> p;
        p.first=a[0];
        p.second=1;
        
        for(int i =1;i<a.size();i++){
            
            if(p.second==0){
                p.first=a[i];
                p.second=1;
            }
            else if(a[i]==p.first) (p.second)++;
            else p.second--;
        }
        return p.first;
    }
