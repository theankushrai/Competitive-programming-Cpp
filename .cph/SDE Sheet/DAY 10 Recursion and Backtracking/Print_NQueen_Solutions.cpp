/**/

// 1.is safe with recursion
// time complexity 4n2
// space complexity n2


    bool is_safe(vector<string> board,int row, int col, int n){
        //checking top of col;
        for(int i =0;i<row;i++) if(board[i][col]=='Q')return false;
        //checking left digonal
        int i=row,j=col;
        while(i>=0&&j>=0) if(board[i--][j--]=='Q')return false;
        //checking right digonal
        i=row;j=col;
        while(i>=0&&j<n) if(board[i--][j++]=='Q')return false;
        return true;
    }
    void NQueen(int n,int row,vector<string>& board,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        
        for(int col=0;col<n;col++){
            if(is_safe(board,row,col,n)){
                board[row][col]='Q';
                NQueen(n,row+1,board,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        NQueen(n,0,board,ans);
        return ans;
    }

//2. optimizing is safe with digonal vectors
//time complexity 4n2
//space complexity 3n+n2;

void NQueen(int n,int row,vector<string>& board,vector<vector<string>>& ans,vector<bool> & leftdigonal,vector<bool> & rightdigonal,vector<bool>& colup){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        
        for(int col=0;col<n;col++){
            if(leftdigonal[col-row+n-1]&&rightdigonal[row+col]&&colup[col]){
                
                board[row][col]='Q'; 
                rightdigonal[row+col]=0;
                leftdigonal[col-row+n-1]=0;
                colup[col]=0;
                NQueen(n,row+1,board,ans,leftdigonal,rightdigonal,colup);
                rightdigonal[row+col]=1;
                leftdigonal[col-row+n-1]=1;
                colup[col]=1;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        vector<bool> leftdigonal(n+n-1,1);
        vector<bool> rightdigonal(n+n-1,1);
        vector<bool> colup(n,1);
        NQueen(n,0,board,ans,leftdigonal,rightdigonal,colup);
        return ans;
    }