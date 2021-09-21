/*
Lexicographically first palindromic string
Rearrange the characters of the given string to form a lexicographically first palindromic string. If no such string exists display message “no palindromic string”.

Examples:

Input : malayalam
Output : aalmymlaa

Input : apple
Output : no palindromic string
*/

#include <bits/stdc++.h> 
#include<string>
using namespace std;

bool isPalindome(int n,string s){
    if(n<1) return false;
    int i =0;
    int j=n-1;
    while(i<j){
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}

string lexographicallyNextPalindrome(int n, string s){
    sort(s.begin(),s.end());
    int i =0;
    while(i<(n*n*n)){
        next_permutation(s.begin(),s.end());
        if(isPalindome(n,s))return s; 
        i++;
    }
    return "NOT APPLICABLE";
    
}

int main()
{
 int n ;
 string s ;
 cin>>n>>s;

 string res=lexographicallyNextPalindrome(n,s);
 cout<<res;
 return 0;
}
