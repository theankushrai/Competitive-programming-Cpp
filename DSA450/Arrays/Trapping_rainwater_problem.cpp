/*
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.
*/

// 1.brute force n2;

long long trappingWater(int a[], int n){
        long long water=0;
        int lmax=0,rmax=0;
        
        for(int i =0;i<n;i++){
            lmax=max(lmax,a[i]); 
            rmax=0;
            for(int j=i+1;j<n;j++){
                rmax=max(rmax,a[j]);
            }
            int temp=min(lmax,rmax);
            if(a[i]<temp) water=water+temp-a[i];
        }
        return water;
    }

// 2. using rmax array time and space complexity n

long long trappingWater(int a[], int n){
        long long water=0;
        int lmax=0;
        
        int rmax[n];
        rmax[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--) rmax[i]=max(rmax[i+1],a[i]);
        
        for(int i =0;i<n;i++){
            lmax=max(lmax,a[i]); 
            int temp=min(lmax,rmax[i]);
            if(a[i]<temp) water=water+temp-a[i];
        }
        return water;
    }

//3. two pointer approach time space complexiy linear

long long trappingWater(int a[], int n){
        // code here
        long long water=0;
        int l=1,r=n-2;
        int lmax=a[0];
        int rmax=a[n-1];
        
        while(l<=r){
            
            if(lmax<=rmax){
                lmax=max(lmax,a[l]);
                water+=(lmax-a[l]);
                l++;
            }
            else{
                rmax=max(rmax,a[r]);
                water+=(rmax-a[r]);
                r--;
            }
            
        }
        return water;
    }