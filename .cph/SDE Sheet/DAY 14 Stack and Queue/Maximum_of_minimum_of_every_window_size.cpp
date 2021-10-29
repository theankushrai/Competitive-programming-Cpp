/*Given an integer array. The task is to find the maximum of the minimum of every window size in the array.
Note: Window size varies from 1 to the size of the Array.

Example 1:

Input:
N = 7
arr[] = {10,20,30,50,10,70,30}
Output: 70 30 20 10 10 10 10 
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1. Minimums of windows
of size 1 are {10}, {20}, {30}, {50},
{10}, {70} and {30}. Maximum of these
minimums is 70. 
Second element in output indicates
maximum of minimums of all windows of
size 2. Minimums of windows of size 2
are {10}, {20}, {30}, {10}, {10}, and
{30}. Maximum of these minimums is 30 
Third element in output indicates
maximum of minimums of all windows of
size 3. Minimums of windows of size 3
are {10}, {20}, {10}, {10} and {10}.
Maximum of these minimums is 20. 
Similarly other elements of output are
computed.
Example 2:

Input:
N = 3
arr[] = {10,20,30}
Output: 30 20 10
Explanation: First element in output
indicates maximum of minimums of all
windows of size 1.Minimums of windows
of size 1 are {10} , {20} , {30}.
Maximum of these minimums are 30 and
similarly other outputs can be computed
Your Task:
The task is to complete the function maxOfMin() which takes the array arr[] and its size N as inputs and finds the maximum of minimum of every window size and returns an array containing the result. 

Expected Time Complxity : O(N)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 105
1 <= arr[i] <= 106*/

//SAME AS LARGEST RECTANGLE IN HISTOGRAM


// 1.brute force
// time complexity n2*k;

vector <int> maxOfMin(int a[], int n)
    {
        vector<int> ans;
        for(int i =1;i<=n;i++){
            int currmax=INT_MIN;
            for(int j=0;j<=n-i;j++){
                int currmin=INT_MAX;
                for(int k =j;k<j+i;k++){
                    currmin=min(currmin,a[k]);
                }
                currmax=max(currmin,currmax);
            }
            ans.push_back(currmax);
            currmax=INT_MAX;
        }
        return ans;
    }

// 2. using leftsmaller and rightsmaller of largest rectangle in histogram to calculate max for every window size
//time complexity 4n;
//space complexity 3n;

vector <int> maxOfMin(int a[], int n)
    {
        stack<int> st;
        
        //for left smaller;
        vector<int> left(n,-1);
        for(int i =0;i<n;i++){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(!st.empty())left[i]=st.top();
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        
        //for right smaller
        vector<int> right(n,n);
        for(int i =n-1;i>=0;i--){
            while(!st.empty()&&a[st.top()]>=a[i])st.pop();
            if(!st.empty())right[i]=st.top();
            st.push(i);
        }
        
        //getting window sizes(len) in which a[i] is smaller and 
        //putting max for all window sizes
        vector<int> ans(n,0);
        for(int i =0;i<n;i++){
            int len=right[i]-left[i]-1;
            ans[len-1]=max(ans[len-1],a[i]);//index=len-1;
        }
        
        
        //since we know that if i>j then maxofmin[i]>=maxofmin[j];
        //if ans[i] is not filled that means ans[i] is same as ans[i+1]or ans[i+2]
        for(int i=n-2;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        return ans;
    }