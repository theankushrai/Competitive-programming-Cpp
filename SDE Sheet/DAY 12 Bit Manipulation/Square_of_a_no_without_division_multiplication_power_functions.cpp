/*Given an integer n, calculate the square of a number without using *, / and pow(). 

Examples : 

Input: n = 5
Output: 25

Input: 7
Output: 49

Input: n = 12
Output: 144
*/

// 1. adding n to n ,n times
//time complexity n;


// int squareOfNo(int n){
//     int res=0;
//     for(int i =0;i<n;i++)res+=n;
//     return res;
// }

//2. using property
// num = 10, square(num) = 10 * 10 
//                           = 10 * (8 + 2) = (10 * 8) + (10 * 2)
// num = 15, square(num) = 15 * 15 
//                       = 15 * (8 + 4 + 2 + 1) = (15 * 8) + (15 * 4) + (15 * 2) + (15 * 1)
//time complexity logn

int squareOfNo(int num){
    int t=num;//t= right value i.e. 8 4 2 1 etc in case of 15
    int res=0;
    while(t>0){
        int currt=1,pos=0;// no of pos we hae to shift to multiply with 8=3,4=2 etc;
        while((currt<<1)<=t){
            currt<<=1;
            pos++;
        }
        res+=(num<<pos);
        t-=currt;
    }
    return res;
}
