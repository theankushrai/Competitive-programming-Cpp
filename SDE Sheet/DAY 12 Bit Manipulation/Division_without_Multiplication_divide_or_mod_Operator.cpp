/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, assume that your function returns 231 − 1 when the division result overflows.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Example 3:

Input: dividend = 0, divisor = 1
Output: 0
Example 4:

Input: dividend = 1, divisor = 1
Output: 1
 

Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0*/

//1.brute force - using subtract operator;
// time complexity dividend/divisor

int divide(long dividend, long divisor) {
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        dividend=abs(dividend);
        divisor=abs(divisor);
        long quo=0;
        while(dividend>=divisor){
            dividend-=divisor;
            quo++;
        }
        quo*=sign;
        if(quo>INT_MAX)return INT_MAX;
        if(quo<INT_MIN)return INT_MIN;
        return quo;
    }
//2. bit manipulation
//time complexity logn;
 int divide(long dividend, long divisor) {
        
        int sign=((dividend<0)^(divisor<0))?-1:1;
        long quo=0,temp=0;
        divisor=abs(divisor);
        dividend=abs(dividend);
        for(int i=31;i>=0;i--){
            if(((divisor<<i))<=dividend){
                quo|=(1LL<<i);
                dividend-=(divisor<<i);
            }
        }
        quo*=sign;
        if(quo<INT_MIN)return INT_MIN;
        if(quo>INT_MAX)return INT_MAX;
        return quo;
    }