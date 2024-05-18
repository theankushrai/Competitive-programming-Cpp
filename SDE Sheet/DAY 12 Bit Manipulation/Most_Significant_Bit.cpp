/*Given a number, find the greatest number less than the given a number which is the power of two or find the most significant bit number .

Examples: 

Input : 10
Output : 8
Greatest number which is a Power of 2 less than 10 is 8
Binary representation of 10 is 1010
The most significant bit corresponds
to decimal number 8.

Input : 18
Output : 16 */

// 1. using loop from 31 to >n or using loop from 0 to <n
//time complexity logn;

int findMSB(int n)
{
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) > n)
            return (1 << (i - 1));
    }
    return n;
}

//2. dividing n untill it reachs 0;
//time complexity logn;

int findMSB(int n)
{
    int count=0;
    while(n>1){
        n/=2;
        count++;
    }
    return (1<<count);
}

//3. using log to the base 2;
//time complexity logn


int findMSB(int n)
{
    int t=floor(log2(n));
    return (1<<t);
}

//4. setting all bits <=n;
// time complexity O(1)

int findMSB(int n)
{
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;
    n+=1;
    return (n>>1);
}
