/*
In daily share trading, a buyer buys shares in the morning and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, whereas the second transaction can only start after the first one is complete (Buy->sell->Buy->sell). Given stock prices throughout the day, find out the maximum profit that a share trader could have made.

Examples: 

Input:   price[] = {10, 22, 5, 75, 65, 80}
Output:  87
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80
Input:   price[] = {2, 30, 15, 10, 8, 25, 80}
Output:  100
Trader earns 100 as sum of 28 and 72
Buy at price 2, sell at 30, buy at 8 and sell at 80
Input:   price[] = {100, 30, 15, 10, 8, 25, 80};
Output:  72
Buy at price 8 and sell at 80.
Input:   price[] = {90, 80, 70, 60, 50}
Output:  0
Not possible to earn.*/

// 1. brute force - check for profit among all elements; and return max profit; n2 time compelxity

#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
int a[]={2,30,15,10,8,25,80};
// int a[]={90,80,70,60,50};
int n=7;
// int n=5;
    
int firstprofit=INT_MIN;
int secondprofit=INT_MIN;
int maxprofit=INT_MIN;

for(int i =0;i<n;i++){
    for(int j=0;j<=i;j++){
        if(a[i]>a[j]) firstprofit=max(a[i]-a[j],firstprofit);
    }
    for(int j=i+1;j<n;j++){
        if(a[j]>a[i+1]) secondprofit=a[j]-a[i+1];
    }
    maxprofit=max(firstprofit,secondprofit);
    firstprofit=INT_MIN;
    secondprofit=INT_MIN;
}
if(maxprofit==INT_MIN) cout<<"not possible to earn"; 
else cout<<maxprofit<<endl;
 return 0;
}

// 2. using dynamic programming
