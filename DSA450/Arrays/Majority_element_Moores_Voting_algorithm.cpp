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

//0. check the count of each element using for loop time cimplexity n2

// 1. count each element using hash table time complexity 2n space complexity n

//2. moores voting algorithm time n space 1
 int majorityElement(vector<int>& a) {
        
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
        return el;
    }