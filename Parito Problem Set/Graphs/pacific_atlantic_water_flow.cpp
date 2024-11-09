// 417. Pacific Atlantic Water Flow
// Solved
// Medium
// Topics
// Companies
// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

// Example 1:


// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
// [0,4]: [0,4] -> Pacific Ocean 
//        [0,4] -> Atlantic Ocean
// [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
//        [1,3] -> [1,4] -> Atlantic Ocean
// [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
//        [1,4] -> Atlantic Ocean
// [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
//        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
// [3,0]: [3,0] -> Pacific Ocean 
//        [3,0] -> [4,0] -> Atlantic Ocean
// [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
//        [3,1] -> [4,1] -> Atlantic Ocean
// [4,0]: [4,0] -> Pacific Ocean 
//        [4,0] -> Atlantic Ocean
// Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
// Example 2:

// Input: heights = [[1]]
// Output: [[0,0]]
// Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.
 

// Constraints:

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105

// using dfs and recursion. starting from end rows and columsn
//time complexity 2 nm or O(nm)
//space compleixty nm

class Solution {
public:

    void dfs(int r , int c , set<pair<int,int>> &visited,int &prevHeight,int row,int col,
        vector<vector<int>>& heights){
        if( r==row || c==col || r<0 || c<0 ||
            visited.count({r,c}) ||
            prevHeight>heights[r][c]){
                return;
            }
        
        visited.insert({r,c});
        dfs(r-1,c,visited,heights[r][c],row,col,heights);
        dfs(r,c-1,visited,heights[r][c],row,col,heights);
        dfs(r+1,c,visited,heights[r][c],row,col,heights);
        dfs(r,c+1,visited,heights[r][c],row,col,heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();
        set<pair<int,int>> atlantic;
        set<pair<int,int>> pacific;

        for(int c=0;c<col;c++){
            dfs(0,c,pacific,heights[0][c],row,col,heights);
            dfs(row-1,c,atlantic,heights[row-1][c],row,col,heights);
        }
        for(int r=0;r<row;r++){
            dfs(r,0,pacific,heights[r][0],row,col,heights);
            dfs(r,col-1,atlantic,heights[r][col-1],row,col,heights);
        }

        vector<vector<int>> results;
        for(int i=0;i<row;i++){
            for(int j =0;j<col;j++){
                if(pacific.count({i,j}) && atlantic.count({i,j})){
                    results.push_back({i,j});
                }
            }
        }
        return results;
    }
};