/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/

//rainwater at a[i] = min(maxofleft,maxofright)-a[i]

// 1.brute force - check max for left and right
//time complexity n2;
int trap(vector<int>& a) {
        int n=a.size();
        int count=0;
        for(int i =0;i<n;i++){
            int maxL=a[i];
            int maxR=a[i];
            for(int l =i-1;l>=0;l--)maxL=max(maxL,a[l]);
            for(int r=i+1;r<n;r++)maxR=max(maxR,a[r]);
            count=count+(min(maxR,maxL)-a[i]);
        }
        return count;
    }

//2. keeping maxR arr;
//time complexity n;
//space complexity n;

int trap(vector<int>& a) {
        int n=a.size();
        int count=0;
        int maxR=INT_MIN;
        int maxL=INT_MIN;
        int maxarr[n];
        for(int i =n-1;i>=0;i--){
            maxR=max(maxR,a[i]);
            maxarr[i]=maxR;
        }
        for(int i =0;i<n;i++){
            maxL=max(maxL,a[i]);
            count=count+(min(maxarr[i],maxL)-a[i]);
        }
        return count;
    }

//3.two pointer approach;
int trap(vector<int>& a) {
        int water =0;
        int i =0;
        int j=a.size()-1;
        int maxL=a[0];
        int maxR=a[a.size()-1];
        while(i<=j){
            
            if(maxL<=maxR){
                maxL=max(maxL,a[i]);
                if(maxL>a[i])water+=(maxL-a[i]);
                i++;
            }
            else{
                maxR=max(maxR,a[j]);
                if(maxR>a[j])water+=(maxR-a[j]);
                j--;
            }
        }
        return water;
    }