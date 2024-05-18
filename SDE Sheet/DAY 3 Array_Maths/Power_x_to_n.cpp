/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 

Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
 

Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104
*/
// 1.brute force
// time complexity n;

 double myPow(double x, int n) {
        if(n==0)return 1;
        if(x==0)return 0;
        double ans=1;
        for(int i =0;i<abs(n);i++){
            ans*=x;
        }
        if(n<0) ans=1/ans;
        return ans;
    }

//2. optimized approach 
// time complexity logn  2^4= (2*2) ^2 and so on;

double myPow(double x, int n) {
        if(n==0)return 1;
        if(n==-1)return 1/x;
        if(n==1)return x;
        if(n%2!=0)return x*myPow(x,n-1);
        return pow(x*x,n/2);
    }
double myPow(double x, int n) {
        long long nn=n;
        if(n<0)nn*=(-1);
        double ans=1;
        while(nn){
            if(nn%2==0){
                x*=x;
                nn/=2;
            }else{
                ans*=x;
                nn--;
            }
        }
        if(n<0)ans=1/ans;
        return ans;
    }
