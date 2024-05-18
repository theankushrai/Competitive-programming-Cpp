/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:


Input: heights = [2,4]
Output: 4
 

Constraints:

1 <= heights.length <= 105
0 <= heights[i] <= 104*/

// 1.brute force - (leftsmaller-rightsmaller)*val;
//time complexity n2;

int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        int maxarea=INT_MIN;
        
        for(int i=0;i<n;i++){
            int leftboundry=-1;
            int rightboundry=-1;
            for(int j=i;j<n;j++){
                if(a[j]<a[i]){
                    rightboundry=j-1;
                    break;
                }
                else if(j==n-1)rightboundry=j;
            }
            for(int j =i;j>=0;j--){
                if(a[j]<a[i]){
                    leftboundry=j+1;
                    break;
                }
                else if(j==0)leftboundry=j;
            }
            maxarea=max(maxarea,(rightboundry-leftboundry+1)*a[i]);
        }
            return maxarea;
    
    }

//2. using leftsmaller and right smaller array and stack;
//time complexity 2n;
//space complexity 3n - two array 1 stack;
int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        stack<int> st;
        
        //for left boundry;
        vector<int> left(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(!st.empty()) left[i]=st.top()+1;
            st.push(i);
        }
        
        //empty the stack
        while(!st.empty())st.pop();
        
        // for right boundry;
        vector<int> right(n,n-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(!st.empty()) right[i]=st.top()-1;
            st.push(i);
        }
        
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,a[i]*(right[i]-left[i]+1));
        }
            return maxarea;
    
    }

//3.optimizing the space to do it in one array space;
//time complexity 2n;
//space complexity n;

 int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        stack<int> st;
             
        // for right boundry;
        vector<int> right(n,n-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(!st.empty()) right[i]=st.top()-1;
            st.push(i);
        }
        
        //empty the stack
        while(!st.empty())st.pop();
        
        int maxarea=0;
        for(int i=0;i<n;i++){
            int leftboundry=0;
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(!st.empty()) leftboundry=st.top()+1;
            st.push(i);
            maxarea=max(maxarea,a[i]*(right[i]-leftboundry+1));
        }
            return maxarea;
    
    }