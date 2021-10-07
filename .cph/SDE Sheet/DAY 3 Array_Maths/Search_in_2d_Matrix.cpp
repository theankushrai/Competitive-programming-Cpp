/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

// 1.brute force
// time complexity nm;

 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(auto i: matrix){
            for(auto it: i){
                if(it==target)return true;
            }
        }
        return false;
    }

//2. binary search on every row 
//time complexity n*(logm);
 bool searchMatrix(vector<vector<int>>& a, int target) {
        int result=false;
        int n=a.size();
        int m =a[0].size();
        for(int i =0;i<n;i++){
            result=binary_search(a[i].begin(),a[i].end(),target);
            if(result==true)break;
        }
        return result;
    }
//3. using i j pointer
// time complexity n+m;
bool searchMatrix(vector<vector<int>>& a, int target) {
        int n=a.size();
        int m=a[0].size();
        int i=0;
	    int j=m-1;
	    while(i<n&&j>=0){
	        if(a[i][j]==target)return 1;
	        if(target<a[i][j])j--;
	        else i++;
	    }
	    return 0;
    }

//4.using binary search
// time complexity log(n+m)

 bool searchMatrix(vector<vector<int>>& a, int target) {
        int n=a.size();
        int m =a[0].size();
	    int l=0;
        int r=(n*m)-1;
        
        while(l<=r){
            int mid=(l+r)/2;    
            if(a[mid/m][mid%m]==target)return true;
            if(target<a[mid/m][mid%m])r=mid-1;
            else l=mid+1;
        }
        return false;
    }