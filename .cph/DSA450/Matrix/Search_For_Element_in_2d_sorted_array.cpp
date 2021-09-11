/*
Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.

Example 1:

Input:
N = 8
arr[] = {3,1,2,2,1,2,3,3}
k = 4
Output: 2
Explanation: In the given array, 3 and
 2 are the only elements that appears 
more than n/k times.
Example 2:

Input:
N = 4
arr[] = {2,3,3,2}
k = 3
Output: 2
Explanation: In the given array, 3 and 2 
are the only elements that appears more 
than n/k times. So the count of elements 
are 2.
*/

// 1. brute force searching all elements n2

for(int i =0;i<row;i++){
    for(j=0;j<col;j++){
        if(a[i][j]==target)return true;
    }
}
return false;

// as all the rows are sorted .all the elements are greater then elements in first col of row
//2. so search for particular row . then search in all the colums of that row; time complexity= 2n;
for(int i =0;i<row;i++){
    if(a[i][0]<target)row=i;
}
for(int j=0;j<col;j++){
    if(a[row][col]==target) return true;
}
return false;

//3. searching from i=0and j=n;  n+m;
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();
        int i = 0;
        int j = col-1;
        
        
        while(i<row&&j>=0){
            if(matrix[i][j]==target)return true;
            if(target<matrix[i][j])j--;
            else i++;
        }
        return false;
    }
