/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30


1. by the sum of two upper elements 
time complexity n2
*/

vector<vector<int>> generate(int n)
{

    vector<vector<int>> a(n);

    for (int i = 0; i < n; i++)
    {
        a[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                a[i][j] = 1;
            else
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }
    }
    return a;
}

// 2. using combinations
// time complexity n*m*(combinaion)

int combination(int n, int r)
{
    double result = 1;
    for (int i = 1; i <= r; i++)
    {
        result = result * (n - r + i) / i;
    }
    return (int)result;
}
vector<vector<int>> generate(int n)
{

    vector<vector<int>> a(n);

    for (int i = 0; i < n; i++)
    {
        a[i].resize(i + 1);
        for (int j = 0; j <= i; j++)
        {
            a[i][j] = combination(i, j);
        }
    }
    return a;
}