/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

 

Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/

// 1.using backtracking
//time complexity 9^n^2
//space complexity n2
 bool is_safe(vector<vector<char>>& board,int row, int col,char c){
        for(int i =0;i<9;i++){
            if(board[row][i]==c)return false;
            if(board[i][col]==c)return false;
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
            //(row/3)//(col/3)tells which 3*3 square its belongs to
            //we multiply (row/3)||(col/3) with 3 to get the starting row||col of the 3*3 square;
            //we do i/3 to change rows if i exceeds 3;
            //we do i%3 to change columns;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                
                if(board[i][j]=='.'){
                    for(char n='1';n<='9';n++){
                        if(is_safe(board,i,j,n)){
                            board[i][j]=n;
                            if(solve(board))return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }