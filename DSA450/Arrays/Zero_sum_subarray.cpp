/*
Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

Example 1:

Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
Example 2:

Input:
5
4 2 0 1 6

Output: 
Yes

Explanation: 
0 is one of the element 
in the array so there exist a 
subarray with sum 0.
*/

// 1. using brute for O(n3)
 bool subArrayExists(int a[], int n)
    {
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                int temp=0;
                for(int k =i;k<=j;k++){
                    temp+=a[k];
                    if(temp==0)return true;
                }
            }
        }
        return false;
    }
//2. furthur optimizing to O(n2)

bool subArrayExists(int a[], int n)
    {
        for(int i =0;i<n;i++){
            int temp=0;
            for(int j =i;j<n;j++){
                temp+=a[j];
                if(temp==0) return true;
            }
        }
        return false;
    }

//3. O(n) using  unordered map;
  bool subArrayExists(int a[], int n)
    {
        map<int,int> m;
        int sum=0;
        for(int i =0;i<n;i++){
            sum+=a[i];
            if(m.find(sum)!=m.end()||sum==0){
                return true;
            }
            m[sum]++;
        }
        return false;
    }