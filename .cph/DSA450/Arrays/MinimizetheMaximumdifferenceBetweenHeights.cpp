// Que =>Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

// A slight modification of the problem can be found here.


// Example 1:

// Input:
// K = 2, N = 4
// Arr[] = {1, 5, 8, 10}
// Output:
// 5
// Explanation:
// The array can be modified as 
// {3, 3, 6, 8}. The difference between 
// the largest and the smallest is 8-3 = 5.

// 1. using for loop
int getMinDiff(int a[], int n, int k) {
        
        sort(a,a+n);
        
        int ans=a[n-1]-a[0];
        int smallest=a[0]+k;
        int largest=a[n-1]-k;
        int finalmin,finalmx;
        
        for(int i =0;i<n-1;i++){
            
            finalmin=min(smallest,a[i+1]-k);
            finalmx=max(largest,a[i]+k);
            if(finalmin<0)continue;
            ans=min(ans,finalmx-finalmin);
        }
        return ans;
        
    }
// 2.using pairs 
