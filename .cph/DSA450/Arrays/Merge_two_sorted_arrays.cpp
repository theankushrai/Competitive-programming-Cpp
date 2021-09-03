// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.


// Example 1:

// Input:
// N = 4, M = 5
// arr1[] = {1, 3, 5, 7}
// arr2[] = {0, 2, 6, 8, 9}
// Output: 0 1 2 3 5 6 7 8 9
// Explanation: Since you can't use any 
// extra space, modify the given arrays
// to form 
// arr1[] = {0, 1, 2, 3}
// arr2[] = {5, 6, 7, 8, 9}

// Example 2:

// Input:
// N = 2, M = 3
// arr1[] = {10, 12}
// arr2[] = {5, 18, 20}
// Output: 5 10 12 18 20
// Explanation: Since you can't use any
// extra space, modify the given arrays
// to form 
// arr1[] = {5, 10}
// arr2[] = {12, 18, 20}

// 1. By using a third arrray 
//  we intitalize a third array we the size equal to m+n then put all the elements
//  sort the elements
//  then place elements back in two arrays 
//  time complexiy - n log n for sorting + n for copying - nfor pasting 
//  space complexity n+m

//2. using merge of mergesort - time complexity n+m space complexity n+m
// put i and j on both arrays 
// put the lesser value in array c
// add the remianing elements

//3. insertion sort type - O(nm) space complexity 1
void merge(int a[], int b[], int n, int m) {
	    // code here
	    int i =0,j;
	    while(i<n&&j<m){
	        j=0;
	        if(a[i]>b[j]){
	            swap(a[i],b[j]);
	            while(b[j]>b[j+1]&&j<m){
	                swap(b[j],b[j+1]);
	                j++;
	            }
	            i++;
	        }
	    }
	}
//4. using pointers

void merge(int a[], int b[], int n, int m) {
	    // code here
	    int i =n-1; // initialize i poiinter at last of first array
	    int j =0; // j at first of second array 
	    while(i>=0&&j<m){ // this will swap all the smaller elements to array 1 and bigger ones to 2
	        if(a[i]>b[j]) {swap(a[i],b[j]);}
	        i--;
	        j++;
	    }
	    sort(a,a+n);//then we can just sort them.
	    sort(b,b+m);
	}