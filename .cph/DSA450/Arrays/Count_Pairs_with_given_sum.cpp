// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

/*Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.


Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.
*/

// 1.Brute force
   int getPairsCount(int a[], int n, int k) {
        int count=0;
        for(int i=0;i<n;i++){
            for(int j =i+1;j<n;j++){
                if(a[i]+a[j]==k)count++;
            }
        }
        return count;
    }
//2. using count array or hashmap
int getPairsCount(int arr[], int n, int k) {
        // code here
        int count=0;
        map<int,int> m;
        for(int i =0;i<n;i++){
            if(m.find(k-arr[i])!=m.end()){
                count+=m[k-arr[i]];
            }
            m[arr[i]]++;
        }
        return count;
    }
