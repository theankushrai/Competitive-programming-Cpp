/*
121. Best Time to Buy and Sell Stock
Easy

11171

430

Add to List

Share
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

// 1. brute force - check profit for every pair
//time complexity n2;

 int maxProfit(vector<int>& a) {
        int profit=0;
        for(int i =0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                profit=max(profit,a[j]-a[i]);
            }
        }
        return profit;
    }

// 2. linear methord by maintaining min
//time complexity n

int maxProfit(vector<int>& a) {
        int profit=0;
        int minel=INT_MAX;
        for(int i =0;i<a.size();i++){
            minel=min(minel,a[i]);
            profit=max(profit,a[i]-minel);
        }
        return profit;
    }