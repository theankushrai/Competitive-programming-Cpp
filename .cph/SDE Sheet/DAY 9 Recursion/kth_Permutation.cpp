/*The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!*/

// 1. using logic
//time complexity nlogn;
//space complexity n
string getPermutation(int n, int k) {
        vector<int> nos;
        int part=1;
        for(int i =1;i<n;i++){
            part*=i;
            nos.push_back(i);
        }
        nos.push_back(n);
        k-=1;
        string ans;
        while(true){
            ans=ans+to_string(nos[k/part]);
            nos.erase(nos.begin()+(k/part));
            if(nos.size()==0)break;
            
            k%=part;
            part/=nos.size();
            
        }
        return ans;
    }