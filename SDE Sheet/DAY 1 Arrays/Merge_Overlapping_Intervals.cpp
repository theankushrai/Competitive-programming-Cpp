/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

// 1. n2 algorithm
    bool canmerge(int a1,int b0){
        return a1>=b0;
    }
    vector<int> merge( int a0,int a1, int b1){
        vector<int> ans;
        ans.push_back(a0);
        ans.push_back(max(a1,b1));
        return ans;
    }    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        
        while(a.size()){
            ans.push_back(a.front());
            int j =1;
            while(j<a.size()){
                if(canmerge(ans.back()[1],a[j][0])){
                    ans.back()=merge(ans.back()[0],ans.back()[1],a[j][1]);
                    a.erase(a.begin()+j);
                }
                else j++;
            }
            a.erase(a.begin());
        }
        return ans;
    }

//2. n algorithm
    bool canmerge(int a1,int b0){
        return a1>=b0;
    }
    vector<int> merge( int a0,int a1, int b1){
        vector<int> ans;
        ans.push_back(a0);
        ans.push_back(max(a1,b1));
        return ans;
    }
    
    vector<vector<int>> merge(vector<vector<int>>& a) {
        
        vector<vector<int>> ans;
        sort(a.begin(),a.end());
        ans.push_back(a[0]);
        
        for(int i =1;i<a.size();i++){
            if(canmerge(ans.back()[1],a[i][0])){
                ans.back()=merge(ans.back()[0],ans.back()[1],a[i][1]);
            }
            else ans.push_back(a[i]);
        }
        return ans;
        
    }