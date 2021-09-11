/*Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

Example 1:

Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
Example 2:

Input:
N = 6
Arr[] = {2, 3, 4, 5, -1, 0}
Output: 120
Explanation: Subarray with maximum product
is [2, 3, 4, 5] which gives product as 120.*/

// 1. cubic solution brute force

long long maxProduct(vector<int> a, int n) {
	    
	    long long ans=INT_MIN;
	    for(int i =0;i<n;i++){
	        for(int j=0;j<n;j++){
	            long long temp=1;
	            for(int k=i;k<=j;k++){
	                temp*=a[k];
	            }
	            ans=max(temp,ans);
	        }
	    }
	    return ans;
	}

//2. optimizing into n2
long long maxProduct(vector<int> a, int n) {
	    
	    long long ans=INT_MIN;
	    for(int i =0;i<n;i++){
	        long long temp=1;
	        for(int j=i;j<n;j++){
	            temp*=a[j];
	            ans=max(temp,ans);
	        }
	    }
	    return ans;
	}

//3. linear solution
	long long maxProduct(vector<int> a, int n) {
	    // code here
	    if(n==1)return a[0];
	    long long mx=1,mn=1,res=1;
	    
	    for(int i =0;i<n;i++){
	        if(a[i]==0){
	            mn=mx=1;
	        }
	        else if(a[i]>0){
	            mx=max(mx,a[i]*mx);
	            mn=min(mn,a[i]*mn);
	        }
	        else{
	            swap(mx,mn);
	            mx=max(mx,a[i]*mx);
	            mn=min(mn,a[i]*mn);
	        }
	        res=max(mx,res);
	        
	    }
	    
	    return res;
	}
