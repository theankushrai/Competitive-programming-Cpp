/*
Minimum swaps and K together 
Medium Accuracy: 47.98% Submissions: 35937 Points: 4
Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

Example 1:

Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
Output : 1
Explanation:
To bring elements 2, 1, 3 together, swap element '5' with '3'
such that final array will be- arr[] = {2, 1, 3, 6, 5}

Example 2:

Input : arr[ ] = {2, 7, 9, 5, 8, 7, 4} and K = 6 
Output :  2 
*/

// 1. brute force - find the target elements. find the elements in each subarry of size target which are not in k
// time compelxity n2

//2. sliding window n;
/*
Find count of all elements which are less than or equals to ‘k’. Let’s say the count is ‘cnt’
Using two pointer technique for window of length ‘cnt’, each time keep track of how many elements in this range are greater than ‘k’. Let’s say the total count is ‘bad’.
Repeat step 2, for every window of length ‘cnt’ and take minimum of count ‘bad’ among them. This will be the final answer.
*/

int minSwap(int *a, int n, int k) {
    
    int kcount=0;
    for(int l =0;l<n;l++) if(a[l]<=k)kcount++;
    if(kcount==0)return 0;
    
    int bad=0;
    for(int l=0;l<kcount;l++)if(a[l]>k)bad++;
    
    int minswap=bad;
    int j=kcount;
    int i=1;
    
    if(a[0]>k)bad--;
    while(j<n){
        if (a[j] > k){++bad;}
        minswap = min(minswap, bad);
        if (a[i] > k){--bad;}
        i++;
        j++;
    }
    return minswap;
}