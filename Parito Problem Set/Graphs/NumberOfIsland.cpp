// 200. Number of Islands
// Solved
// Medium
// Topics
// Companies
// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

// using dfs
//Time complexity O(mn)
//space complexity O(mn)
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n=len(grid)
        m=len(grid[0])
        # visited=[[False]*m for it in grid]
        def dfs(r,c):
            if r==n or r<0 or c==m or c<0 or grid[r][c]=='0' or grid[r][c]=='#': # visited[r][c]:
                return
            # visited[r][c]=True
            grid[r][c]='#'
            dfs(r-1,c)
            dfs(r+1,c)
            dfs(r,c+1)
            dfs(r,c-1)

        count=0
        for r in range(n):
            for c in range(m):
                if grid[r][c]=='1':
                    dfs(r,c)
                    count+=1
        
        return count

// 1. using queue
//time complexity mn for traversing and mulktiplied by 4 for 4 directions = O(mn)
//space complexity mn for visited and mn for queue = 2mn= O(mn)
class Solution {
public:

    void bfs(vector<vector<char>> &grid,vector<vector<bool>> &visited,int i, int j){

        queue<pair<int,int>> qq;

        qq.push({i,j});
        visited[i][j]=true;


        while(!qq.empty()){
            pair<int,int> temp = qq.front();
            qq.pop();
            i=temp.first;
            j=temp.second;

            vector<pair<int,int>> directions={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

            for(auto it :directions){
                int nrow=i+it.first;
                int ncol=j+it.second;

                if(nrow>=0&&nrow<grid.size()&&ncol>=0&&ncol<grid[0].size()&&!visited[nrow][ncol]&&grid[nrow][ncol]=='1'){
                    visited[nrow][ncol]=true;
                    qq.push({nrow,ncol});
                }
            }

           
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n =grid.size();
        int m =grid[0].size();
        int islands=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    bfs(grid, visited,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};

// 2. using recursion for dfs
// time compleixty O(mn)
// space complxity mn for visited and mn for recursion stack =2mn =O(mn)

class Solution {
public:

    void dfs(vector<vector<char>> &grid,vector<vector<bool>> &visited,int row, int col){
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||visited[row][col]||grid[row][col]=='0') return;

        visited[row][col]=true;
        dfs(grid,visited,row-1,col);
        dfs(grid,visited,row+1,col);
        dfs(grid,visited,row,col-1);
        dfs(grid,visited,row,col+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n =grid.size();
        int m =grid[0].size();
        int islands=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    dfs(grid, visited,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};