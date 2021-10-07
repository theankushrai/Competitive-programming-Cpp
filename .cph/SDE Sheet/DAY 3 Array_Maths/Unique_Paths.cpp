/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
Example 3:

Input: m = 7, n = 3
Output: 28
Example 4:

Input: m = 3, n = 3
Output: 6
 

Constraints:

1 <= m, n <= 100
It's guaranteed that the answer will be less than or equal to 2 * 109.
*/

// 1.brute force via recursion
//time complexity nlogn*mlogm;
int paths(int i ,int j, int n, int m){
        if(i==n||j==m)return 0;
        if(i==n-1||j==m-1)return 1;
        return paths(i+1,j,n,m)+paths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
        return paths(0,0,n,m);
    }

//2.dynamic programming
// time complexity n*m
//space complexity n*m
int paths(int i ,int j, int n, int m,vector<vector<int>>&a){
        
        if(i==n||j==m)return 0;
        if(i==n-1||j==m-1)return 1;
        
        if(a[i][j]!=-1)return a[i][j];
        return a[i][j]= paths(i+1,j,n,m,a)+paths(i,j+1,n,m,a);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> temp(n,vector<int> (m,-1));
        return paths(0,0,n,m,temp);
    }

//3. combinations total paths=m-1+n-1=m+n-2.
//out of which we have to find either m-1 path or n-1 path
// find n+m-2 Combination n-1
//time complexity m-1 or n-1;

 int combination(int n,int r){
        double result=1;
            for(int i =1;i<=r;i++){
                result=result*(n-r+i)/i;
            }
            return (int)result;
    }
    int uniquePaths(int m, int n) {
        if(m==1||n==1)return 1;
        int N=m+n-2;
        int r=min(m-1,n-1);
        return combination(N,r);
    }