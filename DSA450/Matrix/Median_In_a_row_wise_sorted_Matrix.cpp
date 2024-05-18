/*
Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5], 
     [2, 6, 9], 
     [3, 6, 9]]

Output: 5

Explanation:
Sorting matrix elements gives us 
{1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 
 

Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
*/

// 1.brute force - put elements in vector sort it and find median
// time complexity - rlogc
// space complexity - r*c

  int median(vector<vector<int>> &a, int r, int c){
        vector<int> s;
        for(int i =0;i<r;i++){
            for(int j=0;j<c;j++) s.push_back(a[i][j]);
        }
        sort(s.begin(),s.end());
        int size=s.size();
        int median=s[(s.size()/2)];
        return median;
    }

//2. using modified binary search 
// time complexity rlogc
// space 1

int median(vector<vector<int>> &a, int r, int c){
        int min=INT_MAX,max=INT_MIN;
        
        for(int i =0;i<r;i++){
            if(a[i][0]<min) min=a[i][0];
            if(a[i][c-1]>max) max=a[i][c-1];
        }
        
        int reqCount=(r*c+1)/2;
        
        while(min<max){
            int mid = (min+max)/2;
            int count=0;
            
            for(int i =0;i<r;i++) count+=(upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin());
            
            if(count<reqCount)min=mid+1;
            else max=mid;
        }
        return min;
        
    }
