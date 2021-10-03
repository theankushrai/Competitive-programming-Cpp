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
vector<vector<int>> merge(vector<vector<int>> &a)
{
    vector<vector<int>> ans;
    sort(a.begin(), a.end());

    while (a.size())
    {

        ans.push_back({a.front()[0], a.front()[1]});
        int j = 1;

        while (j < a.size())
        {
            if (ans.back()[1] >= a[j][0])
            {
                ans.back()[1] = max(a[j][1], ans.back()[1]);
                a.erase(a.begin() + j);
            }
            else
                j++;
        }
        a.erase(a.begin());
    }
    return ans;
}

//2. n algorithm
vector<vector<int>> merge(vector<vector<int>> &a)
{
    sort(a.begin(), a.end());

    vector<vector<int>> ans;

    for (auto it : a)
    {
        int s = it[0], e = it[1];
        if (ans.size() && s <= ans.back()[1])
        {
            s = ans.back()[0];
            e = max(e, ans.back()[1]);
            ans.pop_back();
        }
        ans.push_back({s, e});
    }
    return ans;
}
}
;