/*
Given a boolean 2D array of n x m dimensions where each row is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input: 
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input: 
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).
*/

// 1. brute force n*m;

	int rowWithMax1s(vector<vector<int> > a, int n, int m) {
	    int mx=0;
	    int row=-1;
	    
	    for(int i =0;i<n;i++){
	        int count=0;
	        for(int j =0;j<m;j++){
	            if(a[i][j]==1)count++;
	        }
	        if(count>mx){
	            mx=max(count,mx);
	            row=i;
	        }
	    }
	    return row;
	}

//2. modified binary search mlogn
binary search for 1st one and then 


//3. first find 1st 1 position in first row. then iterate other rows. if 1 is on the left of the position in first row. update maxrow
//time complexity (n+m)

	int rowWithMax1s(vector<vector<int> > a, int n, int m) {
	    int row=-1;
	    
	    int i;
	    for(i =0;i<m;i++)if(a[0][i]==1) break;
	    if(i<m) row=0;
	    
	    for(int j=0;j<n;j++){
	        if(i==-1)break;
	        while(a[j][i-1]==1){
	            i--;
	            row=j;
	        }
	    }
	    return row;
	}
