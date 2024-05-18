/*
Given an array of integers arr[] and a number m, count the number of subarrays having XOR of their elements as m.
Examples: 

Input : arr[] = {4, 2, 2, 6, 4}, m = 6
Output : 4
Explanation : The subarrays having XOR of 
              their elements as 6 are {4, 2}, 
              {4, 2, 2, 6, 4}, {2, 2, 6},
               and {6}

Input : arr[] = {5, 6, 7, 8, 9}, m = 5
Output : 2
Explanation : The subarrays having XOR of
              their elements as 5 are {5}
              and {5, 6, 7, 8, 9}
*/

//brute force - generate all subarrays n3;
// time complexity n3
 
// int solve(int a[],int n,int target){
//     int count=0;
//     for(int i =0;i<n;i++){
//         for(int j=0;j<n;j++){
//             int sum=0;
//             for(int k =i;k<=j;k++){
//                 sum^=a[k];
//             }
//             if(sum==target)count++;
//         }
//     }
//     return count;
// }

//optimized brute force - generate all subarrays n2;
// time complexity n2
 
// int solve(int a[],int n,int target){
//     int count=0;
//     for(int i =0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum^=a[j];
//             if(sum==target)count++;
//         }
//     }
//     return count;
// }

//using hashmap and subarray sum property
//time complexity n
//space complexity n

int solve(int a[],int n,int target){
    unordered_map<int,int> temp;
    int count=0;
    int sum=0;
    for(int i =0;i<n;i++){
        sum^=a[i];
        if(sum==target)count++;
        if(temp.find(target^sum)!=temp.end())count+=temp[sum^target];
        temp[sum]++;
    }
    return count;
}