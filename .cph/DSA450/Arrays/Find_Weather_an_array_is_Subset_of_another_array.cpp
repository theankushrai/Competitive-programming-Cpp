/*
Array Subset of another array 
Easy Accuracy: 51.91% Submissions: 22519 Points: 2
Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.
 

Example 1:

Input:
a1[] = {11, 1, 13, 21, 3, 7}
a2[] = {11, 3, 7, 1}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 2:

Input:
a1[] = {1, 2, 3, 4, 5, 6}
a2[] = {1, 2, 4}
Output:
Yes
Explanation:
a2[] is a subset of a1[]*/

// 1. brute force timecomplexity nm

string isSubset(int a[], int b[], int n, int m) {

if(n<m)return "No";

    for(int i =0;i<m;i++){
        bool isPresent=false;
        for(int j =0;j<n;j++){
            if(a[i]==a[j]) isPresent=true;
        }
        if(isPresent==false) return "No";
    }
    
    return "Yes";
}

//2. sort and check timecomplexity nlongn+mlongm


string isSubset(int a[], int b[], int n, int m) {
    
    if(n<m)return "No";
    
    sort(a,a+n);
    sort(b,b+m);
    
    int i =0;
    int j =0;
    
    while(i<n&&j<m){
        if(a[i]==b[j]){i++; j++;}
        else if(b[j]>a[i]) i++;
        else return "No";
    }
    if(j==m)return "Yes";
    return "No";
}

//3. sort and binary search nlogn+ logm

string isSubset(int a[], int b[], int n, int m) {
    
    if(n<m)return "No";
    
    sort(a,a+n);
    
    for(int j =0;j<m;j++){
        if(binary_search(a,a+n,b[j])==0)return "No";
    }
    return "Yes";
}

//4. put in unordered set and check if its present time compelxit m+n space n
string isSubset(int a[], int b[], int n, int m) {
    
    if(n<m)return "No";
    unordered_set<int> s;
    for(int i =0;i<n;i++) s.insert(a[i]);
    
    for(int j=0;j<m;j++){
        if(s.find(b[j])==s.end()) return "No";
    }
    return "Yes";
}