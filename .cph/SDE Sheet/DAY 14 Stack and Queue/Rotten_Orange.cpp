/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.*/

// 1. using BFS
// time complexity n2; 
//space complexity n2

  int orangesRotting(vector<vector<int>>& a) {
        if(a.empty())return 0;
        int n=a.size();
        int m =a[0].size();
        int total=0;
        queue<pair<int,int>> q;
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(a[i][j]!=0)total++;
                if(a[i][j]==2)q.push({i,j});
            }
        }
        
        int dr[4]={0,0,-1,+1};//left right top bottom
        int dc[4]={-1,+1,0,0};
        
        int count=0;
        int mins=0;
        
        while(!q.empty()){
            int i=q.size();
            count+=i;
            while(i--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i =0;i<4;i++){
                    int nr=r+dr[i];//new row
                    int nc=c+dc[i];//new col
                    if(nr<0||nr>=n||nc<0||nc>=m||a[nr][nc]!=1)continue;
                    a[nr][nc]=2;
                    q.push({nr,nc});
                }
            }
            if(!q.empty())mins++;
        }
        return (total==count?mins:-1);
    }

