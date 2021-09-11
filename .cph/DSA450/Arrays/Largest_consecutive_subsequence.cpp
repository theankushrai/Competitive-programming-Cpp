/*
Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.
*/

// 1. nlogn solution - sort then count consecutive elements ;
 int findLongestConseqSubseq(int a[], int n)
    {
        sort(a,a+n);
        int maxcount=1;
        int count=1;
        for(int i =1;i<n;i++){
            if((a[i-1]+1)==a[i])count++;
            else{
                count=1;
            }
        }
        return count;
        
    }

//2. n solutoin using unordered map

int findLongestConseqSubseq(int a[], int n)
    {
        if(n==1)return 1;
        
        unordered_set<int> set;
        int maxcount=1;
        
        
        for(int i =0;i<n;i++){
            set.insert(a[i]);
        }
        for(int i =0;i<n;i++){
            
            int count=1;    
            
            if(set.find(a[i]-1)!=set.end()) continue;
            
            int temp=a[i];
            while(set.find(temp+1)!=set.end()){
                count++;
                temp++;
            }
            maxcount=max(maxcount,count);
        }
        return maxcount;
    }