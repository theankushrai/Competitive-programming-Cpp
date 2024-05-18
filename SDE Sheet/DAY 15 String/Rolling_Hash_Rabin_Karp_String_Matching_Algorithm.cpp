/*
RABIN KARP ALGORITHM

Since we need to efficiently calculate hash values for all the substrings of size m of text, we must have a hash function which has the following property. 
Hash at the next shift must be efficiently computable from the current hash value and next character in text or we can say hash(txt[s+1 .. s+m]) must be efficiently computable from hash(txt[s .. s+m-1]) and txt[s+m] i.e., hash(txt[s+1 .. s+m])= rehash(txt[s+m], hash(txt[s .. s+m-1])) and rehash must be O(1) operation.
The hash function suggested by Rabin and Karp calculates an integer value. The integer value for a string is the numeric value of a string. 

For example, if all possible characters are from 1 to 10, the numeric value of “122” will be 122. The number of possible characters is higher than 10 (256 in general) and pattern length can be large. So the numeric values cannot be practically stored as an integer. Therefore, the numeric value is calculated using modular arithmetic to make sure that the hash values can be stored in an integer variable (can fit in memory words). To do rehashing, we need to take off the most significant digit and add the new least significant digit for in hash value. Rehashing is done using the following formula. 

hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q 
hash( txt[s .. s+m-1] ) : Hash value at shift s. 
hash( txt[s+1 .. s+m] ) : Hash value at next shift (or shift s+1) 
d: Number of characters in the alphabet 
q: A prime number 
h: d^(m-1)

How does the above expression work? 

This is simple mathematics, we compute decimal value of current window from previous window. 
For example pattern length is 3 and string is “23456” 
You compute the value of first window (which is “234”) as 234. 
How how will you compute value of next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.
*/

//QUESTION 
/*
Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences of pattern string in the text string. For printing, Starting Index of a string should be taken as 1.

Example 1:

Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 
â€‹Example 2:

Input: 
S = "abesdu", pat = "edu"
Output: -1
Explanation: There's not substring "edu"
present in S.

Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string S and the string pat as inputs and returns an array denoting the start indices (1-based) of substring pat in the string S. 


Expected Time Complexity: O(|S|*|pat|).
Expected Auxiliary Space: O(1).


Constraints:
1<=|S|<=105
1<=|pat|<|S|
*/

vector <int> search(string pat, string txt)
        {
            vector<int> ans;
            int d =256;//d is no of characters;
            int m=pat.length();
            int n =txt.length();
            int p=0;
            int t=0;//hash value for text;
            int h =1;//d^(m-1)]
            int q=101;
            
            //calculating h;
            for(int i =0;i<m-1;i++){
                h=(h*d)%q;
            }
            
            //intial window
            for(int i =0;i<m;i++){
                p = (d * p + pat[i]) % q; 
                t = (d * t + txt[i]) % q; 
            }
            
            //rolling hash
            for(int i =0;i<n-m+1;i++){
                //if the hash values match then check the pattern one by one
                if(p==t){
                    int j ;
                    for (j = 0; j < m; j++) 
                    { 
                        if (txt[i+j] != pat[j])break;
                    }
                    if(j==m)ans.push_back(i+1);
                }
                // Calculate hash value for next window of text: Remove 
                // leading digit, add trailing digit 
                if ( i < n-m ) 
                { 
                    t = (d*(t - txt[i]*h) + txt[i+m])%q; 
          
                    // We might get negative value of t, converting it 
                    // to positive 
                    if (t < 0) 
                    t = (t + q); 
                } 
            
        }
        if(ans.empty())ans.push_back(-1);
        return ans;
    } 