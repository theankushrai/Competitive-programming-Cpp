/*Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

 

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105
*/

// 1.brute force - shifting n and checking rightmost bit
// average log n;
int setBits(int n) {
        int count=0;
        while(n){
            count+=(n&1);
            n>>=1;
        }
        return count;
    }

//2. built in pop count funciton
int setBits(int n) {
        return __builtin_popcount(n);
    }
//3. Brian kerninghan's algorithm
//time complexity -log n
int setBits(int n) {
        if(n==0||n==1)return 1;
        int count=1;
        while(n){
            if((n&(n-1)))count++;
            n&=(n-1);
        }
        return count;
    }