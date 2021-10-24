/*Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is 
blocked.
Your Task:  
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order. 
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1*/

//1.backtracking
// Time Complexity: 4^(n^2)
// Space: n2

void solve(vector<vector<int>> &a,vector<string>& ans,vector<vector<int>> &vis,string temp, int n,int row, int col){
        if(row==n-1&&col==n-1){
            ans.push_back(temp);
            return;
        }
        
        //left
        if(col-1>=0&&a[row][col-1]==1&&vis[row][col-1]==0){
            vis[row][col-1]=1;
            solve(a,ans,vis,temp+'L',n,row,col-1);
            vis[row][col-1]=0;
        }
        //right
        if(col+1<n&&a[row][col+1]==1&&vis[row][col+1]==0){
            vis[row][col+1]=1;
            solve(a,ans,vis,temp+'R',n,row,col+1);
            vis[row][col+1]=0;
        }
        //up
        if(row-1>=0&&a[row-1][col]==1&&vis[row-1][col]==0){
            vis[row-1][col]=1;
            solve(a,ans,vis,temp+'U',n,row-1,col);
            vis[row-1][col]=0;
        }
        //down
        if(row+1<n&&a[row+1][col]==1&&vis[row+1][col]==0){
            vis[row+1][col]=1;
            solve(a,ans,vis,temp+'D',n,row+1,col);
            vis[row+1][col]=0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &a, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        if(a[0][0]==1)solve(a,ans,vis,"",n,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
//2. optimizing code and solving all directions in 1 loop
// Time Complexity: 4^(n^2)
// Space: n2

    void solve(vector<vector<int>> &a, vector<string> & ans,vector<vector<int>> & vis,int di[],int dj[], string temp, int n , int row, int col){
        if(row==n-1&&col==n-1){
            ans.push_back(temp);
            return;
        }
        string dir="DLRU";
        for(int i =0;i<4;i++){
            int nr=row+di[i];
            int nc=col+dj[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<n&&vis[nr][nc]==0&&a[nr][nc]){
                vis[nr][nc]=1;
                solve(a,ans,vis,di,dj,temp+dir[i],n,nr,nc);
                vis[nr][nc]=0;//backtrack
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &a, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        int di[]={+1,0,0,-1};
        int dj[]={0,-1,1,0};
        if(a[0][0]==1)solve(a,ans,vis,di,dj,"",n,0,0);
        return ans;
    }
