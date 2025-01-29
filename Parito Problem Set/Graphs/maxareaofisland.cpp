// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

 

// Example 1:


// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.
// Example 2:

// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.


// 1. using dfs recursion
//time complexity O(mn)
//space complexity 2mn =O(mn)

class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<bool>> & visited,int row, int col, int &area){
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||visited[row][col]||grid[row][col]==0) return;

        visited[row][col]=true;
        area++;
        dfs(grid,visited,row+1,col,area);
        dfs(grid,visited,row,col+1,area);
        dfs(grid,visited,row-1,col,area);
        dfs(grid,visited,row,col-1,area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea =0;
        int n =grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]){
                    int area=0;
                    dfs(grid,visited,i,j,area);
                    maxarea=max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n,m=len(grid),len(grid[0])

        def dfs(r,c):
            if r==n or r<0 or c==m or c<0 or grid[r][c]==0:
                return
            nonlocal area
            area+=1
            grid[r][c]=0
            dfs(r-1,c)
            dfs(r+1,c)
            dfs(r,c+1)
            dfs(r,c-1)

        maxarea=0
        for r in range(n):
            for c in range(m):
                if grid[r][c]==1:
                    area=0
                    dfs(r,c)
                    maxarea=max(maxarea,area)
        
        return maxarea