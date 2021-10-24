/*Given a string S. The task is to print all permutations of a given string.

 

Example 1:

Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function find_permutaion() which takes the string S as input parameter and returns a vector of string in lexicographical order.

 

Expected Time Complexity: O(n! * n)

Expected Space Complexity: O(n)

 

Constraints:
1 <= length of string <= 5
 */

//1. print using next permutation;
//time complexity n!*logn
    int fact(int n){
	        if(n==0||n==1)return 1;
	        return n*fact(n-1);
	    }
		vector<string>find_permutation(string s)
		{
		    vector<string> ans;
		    for(int i=0;i<fact(s.size());i++){
		        next_permutation(s.begin(),s.end());
		        ans.push_back(s);
		    }
		    return ans;
		}

// 2.using swap logic
//time complexity n!*n;

void permutation(int idx, vector<int>& nums, vector<vector<int>> &ans){
        
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i =idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            permutation(idx+1,nums,ans);
            swap(nums[i],nums[idx]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permutation(0,nums,ans);
        return ans;
    }