/*The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.
Example 2:

Input: 
N = 6, price[] = [10 4 5 90 120 80]
Output:
1 1 2 4 5 1
Explanation:
Traversing the given input span for 10 
will be 1, 4 is smaller than 10 so the 
span will be 1, 5 is greater than 4 so 
the span will be 2 and so on. Hence, the 
output will be 1 1 2 4 5 1.
User Task:
The task is to complete the function calculateSpan() which takes two parameters, an array price[] denoting the price of stocks, and an integer N denoting the size of the array and number of days. This function finds the span of stock's price for all N days and returns an array of length N denoting the span for the i-th day.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ C[i] ≤ 105*/

//the program is same as left greater element problem


//1. brute force = calculating previous greater for all elements
// time complexity n2

vector <int> calculateSpan(int a[], int n)
    {
        vector<int> ans;
       for(int i =0;i<n;i++){
           
           for(int j=i;j>=0;j--){
               if(a[j]>a[i]) {
                   ans.push_back(i-j);
                   break;
               }
               else if(j==0)ans.push_back(i+1);
           }
       }
       return ans;
    }

// 2.using stack
//time complexity 2n;
//space complexity n;

vector <int> calculateSpan(int a[], int n)
    {
        vector<int> ans(n);
        stack<int> st;
       for(int i =0;i<n;i++){
           while(!st.empty()&&a[i]>=a[st.top()])st.pop();
           if(!st.empty())ans[i]=i-st.top();
           else ans[i]=i+1;    
           st.push(i);
       }
       return ans;
    }