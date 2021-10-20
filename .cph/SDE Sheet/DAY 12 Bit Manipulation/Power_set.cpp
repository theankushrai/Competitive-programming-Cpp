/*Given a string S find all possible subsequences of the string in lexicographically-sorted order.

Example 1:

Input : str = "abc"
Output: a ab abc ac b bc c
Explanation : There are 7 substrings that 
can be formed from abc.
Example 2:

Input: str = "aa"
Output: a a aa
Explanation : There are 3 substrings that 
can be formed from aa.
Your Task:
You don't need to read ot print anything. Your task is to complete the function AllPossibleStrings() which takes S as input parameter and returns a list of all possible substrings(non-empty) that can be formed from S in lexicographically-sorted order.
 

Expected Time Complexity: O(2n) where n is the length of the string
Expected Space Complexity : O(n * 2n)
 

Constraints: 
1 <= Length of string <= 16*/
// 1.bit manipulation
//time complexity 2^n*n
	    bool getbit(int n, int pos){
	        return ((n&(1<<pos))!=0);
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    int n=s.length();
		    for(int i =0;i<(1<<n);i++){
		        string temp="";
		        for(int j =0;j<n;j++){
		            if(getbit(i,j))temp+=s[j];
		        }
		      //  if(temp!="")
		            ans.push_back(temp);
		    }
		  //  sort(ans.begin(),ans.end());
		    return ans;
		}
    