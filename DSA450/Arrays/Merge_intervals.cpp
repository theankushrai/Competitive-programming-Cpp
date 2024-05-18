// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

// 1. with extra space
 vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int > > result;
        sort(intervals.begin(), intervals.end());
        
        for(auto it: intervals) {
            int s = it[0], e = it[1];
            
            if(result.size() && s <= result.back()[1]) {//if result vector=0 add intervals
                s = result.back()[0];
                e = max(it[1], result.back()[1]);

                result.pop_back();
            }
            
            result.push_back({s, e});
        }
        
        return result;
    }