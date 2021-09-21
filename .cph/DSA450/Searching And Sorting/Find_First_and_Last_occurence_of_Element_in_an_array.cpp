/*
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.

Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5. 
 

Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  6 6 
*/

// 1. brute force. loop through array and find first and last occurence
//time complexity n


vector<int> find(int a[], int n , int x )
{
    vector<int> occ;
    int first=-1,second=-1;
    for(int i =0;i<n;i++){
        if(a[i]==x){
            if(first == -1)first=i;
            else second=i;
        }
    }
    if(second==-1)second=first;
    occ.push_back(first);
    occ.push_back(second);
    return occ;
}
//2. using lower bound and upper bound using c++ stl
//time complexity n;

