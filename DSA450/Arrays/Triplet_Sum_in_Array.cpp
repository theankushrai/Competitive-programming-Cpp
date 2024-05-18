/*
Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.


Example 1:

Input:
n = 6, X = 13
arr[] = [1 4 45 6 10 8]
Output:
1
Explanation:
The triplet {1, 4, 8} in 
the array sums up to 13.
Example 2:

Input:
n = 5, X = 10
arr[] = [1 2 4 3 6]
Output:
1
Explanation:
The triplet {1, 3, 6} in 
the array sums up to 10.
*/

// 1. brute force - complexity n3;
bool find3Numbers(int a[], int n, int x)
    {
        
    for(int i =0;i<n;i++){
        for(int j =i+1;j<n;j++){
            for(int k =j+1;k<n;k++){
                if(a[i]==a[j]&&a[j]==a[k])continue;
                else if((a[i]+a[j]+a[k])==x)return true;
            }
        }
    }
    return false;
    }

// 2.  using two pointer approach as well as fixing an element  time complexity n2;

bool find3Numbers(int a[], int n, int x)
    {
        sort(a,a+n);
        
        for(int i =0;i<n;i++){
            int l =i+1;
            int r =n-1;
            
            while(l<r){
                int sum=a[i]+a[l]+a[r];
                if(sum==x) return true;
                else if(sum>x)r--;
                else l++;
            }
        }
        return false;
    }

//3. using hashing time complexity n2, space complexity n

bool find3Numbers(int A[], int arr_size, int sum)
{
    for (int i = 0; i < arr_size - 2; i++)
    {
        unordered_set<int> s;
        int curr_sum = sum - A[i];
        for (int j = i + 1; j < arr_size; j++)
        {
            if (s.find(curr_sum - A[j]) != s.end())
            {
                printf("Triplet is %d, %d, %d", A[i],
                       A[j], curr_sum - A[j]);
                return true;
            }
            s.insert(A[j]);
        }
    }

