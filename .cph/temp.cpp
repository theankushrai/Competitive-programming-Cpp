#include <bits/stdc++.h> 
#include<vector>
#include<string>
using namespace std;
  bool safe(int row, int col, vector<bool> is_safe){
        for(int i  =0;i<=(row+col);i++) if(is_safe[i]==0)return false;
        return true;
        
    }
    void NQueen(int n,int row,vector<string>& board,vector<vector<string>>& ans,vector<bool>& is_safe){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        
        for(int col=0;col<n;col++){
            if(safe(row,col,is_safe)){
                board[row][col]='Q'; 
                is_safe[row+col]=0;
                NQueen(n,row+1,board,ans,is_safe);
                is_safe[row+col]=1;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<bool> is_safe((2*n)-2,1);//true is no queen false is queen
        NQueen(n,0,board,ans,is_safe);
        return ans;
    }

int main()
{solveNQueens(4);
 return 0;
}