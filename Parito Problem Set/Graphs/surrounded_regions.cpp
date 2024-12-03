// 130. Surrounded Regions
// Solved
// Medium
// Topics
// Companies
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
// A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.

 

// Example 1:

// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

// Explanation:


// In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

// Example 2:

// Input: board = [["X"]]

// Output: [["X"]]

 

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.


//checking if there are zeroes connected to boundry
//marking them as B.
//time complezit O(mn)
class Solution {
public:
    void dfs(int r, int c,int row, int col, vector<vector<char>>& board){
        if(r==row || c==col || r<0 || c<0 || board[r][c]=='X' || board[r][c]=='B') return ;
        board[r][c]='B';
        dfs(r,c-1,row,col,board);
        dfs(r,c+1,row,col,board);
        dfs(r+1,c,row,col,board);
        dfs(r-1,c,row,col,board);

    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int c=0;c<col;c++){
            dfs(0,c,row, col, board);
            dfs(row-1,c,row, col, board);
        }
        for(int r=0;r<row;r++){
            dfs(r,0,row, col, board);
            dfs(r,col-1,row, col, board);
        }

        for(int i=0;i<row;i++){
            for(int j =0;j<col;j++){
                if(board[i][j]=='B') board[i][j]='O';
                else if(board[i][j]=='O')board[i][j]='X';
                
            }
        }
    }
};