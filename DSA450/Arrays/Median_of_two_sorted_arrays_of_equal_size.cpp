/*
There are 2 sorted arrays A and B of size n each. Write an algorithm to find the median of the array obtained after merging the above 2 arrays(i.e. array of length 2n). The complexity should be O(log(n)). 

median-of-two-arrays
https://media.geeksforgeeks.org/wp-content/cdn-uploads/median-of-two-arrays.jpg
Note: Since the size of the set for which we are looking for the median is even (2n), we need to take the average of the middle two numbers and return the floor of the average
*/

// 1. brute force - make a new array sort it and find the answer
// time complexity nlogn;
//space complexity n;

//2,  using merge sort merge technique to sort the array
// time complexity n;
// space complexity n;


//3. use merge sort like count
//time complexity n
//space complexiy 1
/*
#include <bits/stdc++.h> 
using namespace std;
 
int solve(int a[],int b[], int n){
    
    int m1=-1,m2=-1;
    int i =0,j=0;
    for(int count =0;count<=n;count++){
        if(i==n){
            m1=m2;
            m2=b[0];
            break;
        }
        else if(j==n){
            m1=m2;
            m2=a[0];
            break;
        }
        else if(a[i]<=b[j]){
            m1=m2;
            m2=a[i++];
        }
        else{
            m1=m2;
            m2=b[j++];
        }
    }
    return ((m1+m2)/2);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    cout<<solve(a,b,n);
    
 return 0;
}
*/

//4. using modified binary search
// time complexity log n;



#include <bits/stdc++.h> 
using namespace std;
 
int median(int a[],int sa,int ea){
    return ((a[(sa+ea)/2]+a[(sa+ea+1)/2])/2);
}

int solve(int a[],int sa,int ea, int b[],int sb,int eb){

    if((ea-sa<=1)&&(eb-sa)) return ((max(a[sa],b[sb])+min(a[ea],b[eb]))/2);
    
    int m1=median(a,sa,ea);
    int m2=median(b,sb,eb);
    if(m1==m2)return m1;
    if(m1>m2){
        if(ea%2!=0) return solve(a,sa,(sa+ea)/2,b,(sb+eb+1)/2,eb);
        return solve(a,sa,(sa+ea+1)/2,b,(sb+eb+1)/2,eb);
    }
    if(eb%2!=0) return solve(a,(sa+ea+1)/2,ea,b,sb,(sb+eb)/2);
    return solve(a,(sa+ea+1)/2,ea,b,sb,(sb+eb+1)/2);
    
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int b[n];
    for (int i = 0; i < n; i++)
    {
        cin>>b[i];
    }
    cout<<solve(a,0,n-1,b,0,n-1);
    
 return 0;
}