/*Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800*/

// 1. n2 time complexity

    vector<int> factorial(int N){
        // code here
        vector<int> res;
        res.push_back(1);
        if(N==1) return res;
        for(int i =2;i<=N;i++){
            int carry=0;
            for(int j=res.size()-1;j>=0;j--){
                int temp=(i*res[j])+carry;
                res[j]=temp%10;
                carry=temp/10;
            }
             while(carry){
                    res.insert(res.begin(),carry%10);
                    carry/=10;
                }
        }
        
        return res;
    }