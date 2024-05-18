// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]

// 1. using logic
void nextPermutation(vector<int>& a) {
        
        int n =a.size();
        int i ,j;
        //i will be the first break point (when the array will first decrease from last)
        // j will be first point greater then i from the last
        for(i=n-2;i>=0;i--){//finding 1st break point
            if(a[i]<a[i+1])break;
        }
        if(i<0){
            reverse(a.begin(),a.end());
            return;//if no break point reverse and return;
        }
        else{
            for(j=n-1;j>i;j--){// finding value greater then bre
                if(a[j]>a[i]) break;
            }
            swap(a[i],a[j]);
            reverse(a.begin()+i+1,a.end());
        }
        
    }