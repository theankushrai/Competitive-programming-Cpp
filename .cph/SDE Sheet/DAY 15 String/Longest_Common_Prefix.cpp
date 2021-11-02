/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.*/

// 1.using pointer to check prefix
//time complexity n*sizea[i];
 int minlength(vector<string>& s){
        int length=INT_MAX;
        for(auto it:s){
            if(it.length()<length)length=it.length();
        }
        return length;
    }
    bool commonforall(vector<string>& a,int mid){
        for(int i =1;i<a.size();i++){
            if(a[i-1][mid]!=a[i][mid])return false;
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& s) {
        int min=minlength(s);
        string ans="";
        for(int i =0;i<min;i++){
            if(commonforall(s,i))ans+=s[0][i];
            else break;
        }
        return ans;
    }

//2.sort array and find common prefix of first and last element
//time complexity nlogn
int minlength(vector<string>& s){
        int length=INT_MAX;
        for(auto it:s){
            if(it.length()<length)length=it.length();
        }
        return length;
    }
   
    string longestCommonPrefix(vector<string>& s) {
        int min=minlength(s);
        sort(s.begin(),s.end());
        string ans="";
        for(int i =0;i<min;i++){
            if(s[0][i]==s[s.size()-1][i])ans+=s[0][i];
            else break;
        }
        return ans;
    }
//3.usinb binary search
//time complexity n*log(mina[i]);

int minlength(string a[],int n){
        int minl=INT_MAX;
        for(int i =0;i<n;i++){
            if(a[i].length()<minl) minl=a[i].length();
        }
        return minl;
    }
    
    bool commonforall(string a[],int n,int mid){
        for(int i =1;i<n;i++){
            if(a[i-1][mid]!=a[i][mid])return false;
        }
        return true;
    }
    
    int endingindex(string a[],int n){
        int min=minlength(a,n);
        int low=0;
        int high=min-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(commonforall(a,n,mid))low=mid+1;
            else high=mid-1;
        }
        if(commonforall(a,n,high))return high;
        return -1;
    }
    
    string longestCommonPrefix (string a[], int n)
    {
        int end=endingindex(a,n);
        if(end==-1)return "-1";
        string ans;
        for(int i =0;i<=end;i++)ans+=a[0][i];
        return ans;
    }

