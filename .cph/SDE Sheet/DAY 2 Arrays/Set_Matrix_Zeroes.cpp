/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1

1.brute force
check for zeroes by traversitng the array. if zero is found mark the row and column with -1
replace all -1 with 0
Time Complexity - nm*(n+m)
*/

void setZeroes(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                int r = 0;
                int c = j;
                while (r < n)
                {
                    if (a[r][c] != 0)
                        a[r][c] = -1;
                    r++;
                }
                r = i;
                c = 0;
                while (c < m)
                {
                    if (a[r][c] != 0)
                        a[r][c] = -1;
                    c++;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == -1)
                a[i][j] = 0;
        }
    }
}

//2. using row and column arrays to mark row column
//mark col and rows with zero and then replace whole row column with zero if either row or column is zero;
//time complexity nm
//space complexity n+m;

void setZeroes(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();

    vector<int> row(n, -1);
    vector<int> col(m, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 0 || col[j] == 0)
            {
                a[i][j] = 0;
            }
        }
    }
}

//3. using first row and column to marks rows and columns
//time complexity nm
//space complexity 1;

void setZeroes(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    bool col = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] == 0)
            col = false;
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][0] = a[0][j] = 0;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (a[0][j] == 0 || a[i][0] == 0)
            {
                a[i][j] = 0;
            }
        }
        if (col == false)
            a[i][0] = 0;
    }
}
