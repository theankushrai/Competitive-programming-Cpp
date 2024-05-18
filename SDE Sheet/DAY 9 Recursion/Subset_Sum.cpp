/*Given a list arr of N integers, print sums of all subsets in it.

Example 1:

Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
Example 2:

Input:
N = 3
arr = {5, 2, 1}
Output:
0 1 2 3 5 6 7 8
Your Task:  
You don't need to read input or print anything. Your task is to complete the function subsetSums() which takes a list/vector and an integer N as an input parameter and return the list/vector of all the subset sums.

Expected Time Complexity: O(2N)
Expected Auxiliary Space: O(2N)

Constraints:
1 <= N <= 15
0 <= arr[i] <= 104
*/
// 1. find all the subsets and print sum
//time complexity 2^n*n

bool getbit(int n,int pos){
        return ((n&(1<<pos))!=0);
    }
    vector<int> subsetSums(vector<int> a, int n)
    {
        vector<int> ans;
        for(int i =0;i<(1<<n);i++){
            int sum=0;
            for(int j=0;j<n;j++){
                if(getbit(i,j)){
                    sum+=a[j];
                }
            }
            ans.push_back(sum);
        }
        return ans;
    }
//2. using recursion - pick not pick technique;
//time complexity 2^n
void subset(vector<int> arr, int n, int pos, vector<int>& ans,int sum){
        if(pos>=n){
            ans.push_back(sum);
            return;
        }
        subset(arr,n,pos+1,ans,sum+arr[pos]);
        subset(arr,n,pos+1,ans,sum);
    }
    vector<int> subsetSums(vector<int> a, int n)
    {
        vector<int> ans;
        subset(a,n,0,ans,0);
        return ans;
    }