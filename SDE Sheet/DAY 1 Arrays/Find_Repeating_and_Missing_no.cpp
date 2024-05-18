/*Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Examples: 

 Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 
2 is missing and 3 occurs twice 

Input: arr[] = {4, 3, 6, 2, 1, 1}
Output: Missing = 5, Repeating = 1
*/


// 1.brute force - check for each no from 1 to n 
// time complxity - 2*n2;
// space complexity -1;

// #include <bits/stdc++.h> 
// using namespace std;
 
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }

//     int missing=0;
//     int repeating=0;

//     // bool mflag=false;
//     // bool rflag=false;
    
//     for (int i = 1; i <= n; i++)
//     {
//         bool pflag=false;
//         for (int j = 0; j < n; j++)
//         {
//             if(i==a[j])pflag=true;
//         }
//         if(pflag==false)missing=i;
        
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if(i!=j&&a[i]==a[j])repeating=a[i];
//         }
        
//     }
    
//     cout<<missing<<endl;
//     cout<<repeating<<endl;
    
//  return 0;
// }

//2. sorting the array then finding missing repeating
// time complexity - nlogn
//space complexity - 1


// #include <bits/stdc++.h> 
// using namespace std;
 
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }

//     int missing=-1;
//     int repeating=-1;

//     sort(a,a+n);

//     int no=1;
//     for (int i = 0; i < n; i++)
//     {
//         if(a[i]==no)no++;
//     }

//     missing=no;

//     for (int i = 1; i < n; i++)
//     {
//         if(a[i]==a[i-1]){
//             repeating=a[i];
//             break;
//         }
//     }
    

//     cout<<missing<<endl;
//     cout<<repeating<<endl;
    
//  return 0;
// }

//3. count array
//time complexity 2n;
//space complexity n;


// #include <bits/stdc++.h> 
// #include<vector>
// using namespace std;
 
// int main()
// {
//     int n;
//     cin>>n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }

//     int missing=-1;
//     int repeating=-1;

//     vector<int> count(n+1,0);

//     for (int i = 0; i < n; i++)
//     {
//         count[a[i]]++;
//     }

//     for (int i = 1; i < n+1; i++)
//     {
//         if(count[i]==0)missing=i;
//         else if(count[i]>=2)repeating=i;
//     }
    
    

//     cout<<missing<<endl;
//     cout<<repeating<<endl;
    
//  return 0;
// }

//4. use elements as index and mark the visited places
//time complexity n

//for repeating
        // for(int i =0;i<n;i++){
        //     if(a[abs(a[i])-1]>0){
        //         a[abs(a[i])-1]=-a[abs(a[i])-1];
        //     }
        //     else repeating=abs(a[i]);
        // }
        
        // //for missing
        // for(int i =0;i<n;i++){
        //     if(a[i]>0){
        //         missing=i+1;
        //         break;
        //     }
        // }


//5. equation method
/* time complexity n

Let x be the missing and y be the repeating element.
Let N is the size of array.
Get the sum of all numbers using formula S = N(N+1)/2
Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
Iterate through a loop from i=1….N
S -= A[i]
Sum_Sq -= (A[i]*A[i])
It will give two equations 
x-y = S – (1) 
x^2 – y^2 = Sum_sq 
x+ y = (Sum_sq/S) – (2) */


#include <bits/stdc++.h> 
#include<vector>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    long long int SUM=(n*(n+1))/2;
    long long int SQ_SUM=(n*(n+1)*((2*n)+1))/6;

    for(int i=0;i<n;i++) {
        SUM-=a[i];
        SQ_SUM-=(a[i]*a[i]);
    }

    int missing=(SUM+(SQ_SUM/SUM))/2;
    int repeating=((SQ_SUM/SUM)-SUM)/2;
    cout<<missing<<endl;
    cout<<repeating<<endl;
    
 return 0;
}