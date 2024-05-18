/*Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
Example 4:

Input: n = 4
Output: true
Example 5:

Input: n = 5
Output: false
 

Constraints:

-231 <= n <= 231 - 1
*/

//1. brute force - log using stl
//time complexity logn;
bool isPowerOfTwo(int n) {
        if(n==0)return false;
        if(ceil(log2(n))==floor(log2(n)))return 1;
        return 0;
    }

// 2.using while loop- we divide by 2;
//time complexity logn;
bool isPowerOfTwo(int n) {
        if(n==0)return false;
        while(n>=2){
            if(n%2!=0)return false;
        }
        return true;
    }

//3. using recursion we divide;
//time complexity logn;
bool power(long long n){
        if(n==0)return false;
        if(n==1)return true;
        if(n%2!=0)return false;
        return power(n/2);
    }

//4. bit manipulation- counting set bits
//time complexity linear;
//(a) counting each bit;
int count_bits(int n){
        int count=0;
        while(n){
            count+=(n&1);
            n>>=1;
        }
        return count;
    }
//(b)Brian Kernighan's algorithm
int count_bits(int n){
        int count=1;
        while(n){
            if(n&(n-1))count++;
            n=n&(n-1);
        }
        return count;
    }

//5. using & on n and n-1;
//time complexity linear
//(a) using ~ operation
if(n==0)return false;
        if((n&(~(n-1)))==n)return true;
        return false;
//(b) without using ~operation
bool isPowerOfTwo(int n) {
        if(n==0)return false;
        if((n&(n-1))==0)return true;
        return false;
    }
