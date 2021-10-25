/*Given two numbers N and A, find N-th root of A. In mathematics, Nth root of a number A is a real number that gives A, when we raise it to integer power N. These roots are used in Number Theory and other advanced branches of mathematics. 
Refer Wiki page for more information. 
Examples: 
 

Input : A = 81
        N = 4
Output : 3 
3^4 = 81*/

// 1. using binary search
//time complexity n*log(m*10^d) where d stands for no of decimal places for answer;

double solve(int n, int m){
	    double high=m,low=1;
	    double diff=1e-6;
	    while((high-low)>diff){
	        double mid=(high+low)/2;
	        double temp=pow(mid,n);
	        if(temp==m)return mid;
	        if(temp<m)low=mid;
	        else high=mid;
	    }
	    return high;
	}
	int NthRoot(int n, int m)
	{
	    return floor(solve(n,m));
	}