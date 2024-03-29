/*Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
 

Constraints:

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106*/


// 1. place in new array and sort array 
//time complexity n+m;
//space complexity n+m;

//3. merge in place using shell sort
//time complexity nlogn

//2. using merge in mergesort
// time complexity k

// 4. using binary search
//time complexity log(min(n1,n2));

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n2<n1)return findMedianSortedArrays(nums2,nums1);
        int low=0;
        int high=n1;
        int halfelements=(n1+n2+1)/2;
        while(low<=high){
            int cut1=(low+high)/2;
            int cut2=halfelements-cut1;
            
            int left1=(cut1==0)?INT_MIN:nums1[cut1-1];
            int left2=(cut2==0)?INT_MIN:nums2[cut2-1];
            int right1=(cut1==n1)?INT_MAX:nums1[cut1];
            int right2=(cut2==n2)?INT_MAX:nums2[cut2];
            
            if(left1<=right2&&left2<=right1){
                if((n1+n2)%2==0){
                    return ((max(left1,left2)+min(right1,right2))/2.0);
                }
                else return max(left1,left2);
            }
            if(left1>right2){
                high=cut1-1;
            }
            else low=cut1+1;
        }
        return 0;
    }