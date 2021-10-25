/*Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows.
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Example
Input:

1
5 3
1
2
8
4
9
Output:

3
Output details:

FJ can put his 3 cows in the stalls at positions 1, 4 and 8,
resulting in a minimum distance of 3.
*/

// 1. using binary search- possible is left and not possible is right;
//time complexity n*log(N) where N is search space
bool is_possible(vector<int>&a, int m, int mid){
        int pos =a[0];
        m--;
        for(int i =1;i<a.size();i++){
            if(a[i]-pos>=mid){
                m--;
                pos=a[i];
            }
            if(!m)return true;;
        }
        return false;
    }
    int maxDistance(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int low=1;
        int high=a[a.size()-1]-a[0];
        while(low<=high){
            int mid=(low+high)/2;
            if(is_possible(a,m,mid))low=mid+1;
            else high=mid-1;
        }
        return high;
    }
