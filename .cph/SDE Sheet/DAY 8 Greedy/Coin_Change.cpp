/*
Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.


Example 1:

Input: V = 30, M = 3, coins[] = {25, 10, 5}
Output: 2
Explanation: Use one 25 cent coin
and one 5 cent coin
Example 2:
Input: V = 11, M = 4,coins[] = {9, 6, 5, 1} 
Output: 2 
Explanation: Use one 6 cent coin
and one 5 cent coin

Your Task:  
You don't need to read input or print anything. Complete the function minCoins() which takes V, M and array coins as input parameters and returns the answer.

Expected Time Complexity: O(V*M)
Expected Auxiliary Space: O(V)

Constraints:
1 ≤ V*M ≤ 106
All array elements are distinct

1. using greedy methord
time complexity n;
*/

int minCoins(int coins[], int M, int V) 
	{ 
	    sort(coins,coins+M);
	    int count=0;
	    
	    for(int i=M-1;i>=0;i--){
	        if(V>=coins[i]){
	            count+=(V/coins[i]);
	            V%=coins[i];
	            if(V==0)return count;
	        }
	    }
	    if(V>0)return -1;
	} 