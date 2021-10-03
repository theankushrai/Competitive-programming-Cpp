/*
Given two sorted arrays, we need to merge them in O((n+m)*log(n+m)) time with O(1) extra space into a sorted array, when n is the size of the first array, and m is the size of the second array.

Example:  

Input: ar1[] = {10};
       ar2[] = {2, 3};
Output: ar1[] = {2}
        ar2[] = {3, 10}  

Input: ar1[] = {1, 5, 9, 10, 15, 20};
       ar2[] = {2, 3, 8, 13};
Output: ar1[] = {1, 2, 3, 5, 8, 9}
        ar2[] = {10, 13, 15, 20}
*/

// 1. brute force - initialize new array , place all elements in it, sort it, return all elements back to original arr
// time complexity nlogn +n+n;
// space complexity n

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin>>n>>m;
//     int a[n],b[m];
//     for (int i = 0; i < n; i++)
//     {
//         cin>>a[i];
//     }
//     for (int j = 0; j < m; j++)
//     {
//         cin>>b[j];
//     }

//     int arr[n+m];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i]=a[i];
//     }
//     for (int i = n; i < n+m; i++)
//     {
//         arr[i]=b[i-n];
//     }

//     sort(arr,arr+n+m);
//     for (int i = 0; i < n; i++)
//     {
//         a[i]=arr[i];
//     }
//     for (int i = 0; i < m; i++)
//     {
//         b[i]=arr[i+n];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
//     for (int i = 0; i < m; i++)
//     {
//         cout<<b[i]<<" ";
//     }

//  return 0;
// }

// 2. initialize two arrays and then merge using mergesort merge
// time complexity n+m
//space complexit n+m;

/*
#include <bits/stdc++.h> 
#include<vector>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin>>b[j];
    }

    vector<int> temp;
    
    int i =0;
    int j=0;

    while(i<n&&j<m){
            if(a[i]<=b[j])temp.push_back(a[i++]);
            else temp.push_back(b[j++]);
    }
    while(i<n) temp.push_back(a[i++]);
    while(j<m)temp.push_back(b[j++]);
    
    for (int i = 0; i < n; i++)
    {
        a[i]=temp[i];
    }
    for (int i = 0; i < m; i++)
    {
        b[i]=temp[i+n];
    }

    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < m; i++)
    {
        cout<<b[i]<<" ";
    }
    
    
 return 0;
}
*/

//3. place the smallest element from 2nd array in 1st and then place the element of 2nd array in its correct place for every element in 1st array
// time complexity n*m

/*
#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin>>b[j];
    }

   for (int i = 0; i < n; i++)
   {
        if(b[0]<a[i]){
                int j=0;
                swap(b[0],a[i]);
                while(b[j]>b[j+1]&&j<m-1)
                {
                        swap(b[j],b[j+1]);
                        j++;
                }
        }           
   }
   
   
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < m; i++)
    {
        cout<<b[i]<<" ";
    }
    
    
 return 0;
}
*/

//4. place all the smaller elements in 1st array bigger in 2nd array thn sort both arrays
//time complexity n+m+nlogn+mlongm
/*
#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin>>b[j];
    }

        int r=n-1;
        int l=0;
        while(r>=0&&l<m){
                if(a[r]>b[l])swap(a[r],b[l]);
                l++;
                r--;
        }
        sort(a,a+n);
        sort(b,b+m);

   for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < m; i++)
    {
        cout<<b[i]<<" ";
    }
    
    
 return 0;
}
*/

//5. using shell sort
// time compleixty m+m;
// space complexity 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }

    int gap = ceil((float)(m + n) / 2);//float for correct ceiling values
    while (gap > 0)
    {
        int i = 0;
        int j = gap;

        while (j < m + n)
        {
            if (j >= n)
            {
                if (i >= n)
                {
                    if (b[i - n] > b[j - n])
                        swap(b[i - n], b[j - n]);
                }
                else
                {
                    if (a[i] > b[j - n])
                        swap(a[i], b[j - n]);
                }
            }
            else
            {
                if (a[i] > a[j])
                    swap(a[i], a[j]);
            }
            i++;
            j++;
        }
        gap = ceil(gap / 2);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}