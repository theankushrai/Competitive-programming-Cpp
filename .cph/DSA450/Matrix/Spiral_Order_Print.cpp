/*
Given a matrix of size r*c. Traverse the matrix in spiral form.

Example 1:

Input:
r = 4, c = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
r = 3, c = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.

*/

vector<int> spirallyTraverse(vector<vector<int> > a, int r, int c) 
    {
        int cs=0;
        int rs=0;
        int ce=c-1;
        int re=r-1;
        vector<int> ans;
        
        while(cs<=ce&&rs<=re){
            
            if(cs<=ce&&rs<=re) for(int i =cs;i<=ce;i++) ans.push_back(a[rs][i]);
            else break;
            rs++;
            if(cs<=ce&&rs<=re) for(int i=rs;i<=re;i++) ans.push_back(a[i][ce]);
            else break;
            ce--;
            if(cs<=ce&&rs<=re)for(int i =ce;i>=cs;i--) ans.push_back(a[re][i]);
            else break;
            re--;
            if(cs<=ce&&rs<=re)for(int i =re;i>=rs;i--) ans.push_back(a[i][cs]);
            else break;
            cs++;
        }
        return ans;
    }