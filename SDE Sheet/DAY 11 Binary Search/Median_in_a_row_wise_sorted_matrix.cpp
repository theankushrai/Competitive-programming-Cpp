/*Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

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

Your Task:  
You don't need to read input or print anything. Your task is to complete the function median() which takes the integers R and C along with the 2D matrix as input parameters and returns the median of the matrix.

Expected Time Complexity: O(32 * R * log(C))
Expected Auxiliary Space: O(1)


Constraints:
1<= R,C <=150
1<= matrix[i][j] <=2000*/

// 1. bruteforce - iteralte over all elements and put all elements in vector
//time complexity r*c*logn;
//space complexity r*c;

int median(vector<vector<int>> &a, int r, int c){
        vector<int> temp;
        for(auto arr:a){
            for(auto it:arr)temp.push_back(it);
        }
        sort(temp.begin(),temp.end());
        int n=r*c;
        int mid=n/2;
        if(n%2==0){
            return ((temp[mid]+temp[mid-1])/2);
        }
        else return temp[mid];
    }
//2. using modified binary search;
//time complexity 32*r*logc

int median(vector<vector<int>> &matrix, int r, int c){
        int size=(r*c)/2;
        int low=1;
        int high=2000;
        while(low<=high){
            int mid=(low+high)/2;
            int count=0;
            for(auto it:matrix){
                count+=(upper_bound(it.begin(),it.end(),mid)-it.begin());
            }
            if(count<=size)low=mid+1;
            else high=mid-1;
        }
        return low;
    }