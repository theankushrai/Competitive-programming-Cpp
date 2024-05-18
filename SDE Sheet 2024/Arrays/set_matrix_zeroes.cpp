// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

 

// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1
 

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

// ------------------------------------------------------------------------------------------------------------
// method 1 - brute force
//time complexity O((n*m)(n+m))+O(n+m)
//space complexity O(1)

// void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

            //if element is zero mark all rows and columns as -1
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     for (int k = 0; k < n; k++)
//                         if (matrix[k][j]!=0)
//                             matrix[k][j] = -1; 
//                     for (int k = 0; k < m; k++)
//                         if (matrix[i][k]!=0)
//                             matrix[i][k] = -1;
//                 }
//             }
//         }
            //convert -1 to 0
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == -1)
//                     matrix[i][j] = 0;
//             }
//         }
// }


// ------------------------------------------------------------------------------------------------------------

// method 2 - using extra space
// time complexity O(mn)
// space complexity O(m+n)



// void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//
        //take a row and column vector
//         vector<bool> row(n,false);
//         vector<bool> col(m,false);
        
        // if element is 0 mark row and column as 0 or true
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     col[i]=true;
//                     row[j]=true;
//                 }
//             }
//         }
            //if row or column is true mark element as 0
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 if(col[i]||row[j]) matrix[i][j]=0;
//             }
            
//         }
// }

// ------------------------------------------------------------------------------------------------------------

//method 3
//time complexity O(2nm)
//space complexity O(1)


// void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

            //take column and row vector inside matrix col0 to represent col 0
//         int col0=1;
// //      vector<bool> row(n,false); -> [something][0]
// //      vector<bool> col(m,false); -> [0][something]


            //mark column and row vector as 0 if el is 0
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     matrix[i][0]=0;
//                     if(j==0) col0=0; //if it is first column then mark col0 as 0
//                     else matrix[0][j]=0; //else mark in regular column space
//                 }
//             }
//         }

            // checking for everything except row and column vector

//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 1; j < m; j++)
//             {
//                 if(matrix[i][j]!=0) if(matrix[i][0]==0||matrix[0][j]==0)matrix[i][j]=0;
//             }
            
//         }

            // if first element of row is 0 then mark whole row as zero
//         if(matrix[0][0]==0){
//             for (int j = 0; j < m; j++)
//             {
//                 matrix[0][j]=0;
//             }
//         }

            //if first element of column is zero then mark whole column as zero
//         if(col0==0){
//             for (int i = 0; i < n; i++)
//             {
//                 matrix[i][0]=0;
//             }            
//         }
        
// }
