/*
Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times.

Example 1:

Input:
N = 8
arr[] = {3,1,2,2,1,2,3,3}
k = 4
Output: 2
Explanation: In the given array, 3 and
 2 are the only elements that appears 
more than n/k times.
Example 2:

Input:
N = 4
arr[] = {2,3,3,2}
k = 3
Output: 2
Explanation: In the given array, 3 and 2 
are the only elements that appears more 
than n/k times. So the count of elements 
are 2.*/

// 1. brute force n2 = pick element and check for its occurence. if occurence is more then n/k count++ return count;
//2. sort and check count of each element n logn
//3. using modified version of moores voting algorithm time complexity nk space complexity k;

struct elecount
{
    int el;
    int c;
};
//Function to find all elements in array that appear more than n/k times.
int countOccurence(int a[], int n, int k)
{

    int tempsize = k - 1;
    if (k < 2)
        return 0;
    struct elecount temp[tempsize];
    for (int i = 0; i < tempsize; i++)
        temp[i].c = 0;

    // step 1; loop through array

    for (int i = 0; i < n; i++)
    {
        int j;

        //step 2; if element is present in temp inc its count;
        for (j = 0; j < tempsize; j++)
        {
            if (a[i] == temp[j].el)
            {
                temp[j].c += 1;
                break;
            }
        }
        //step 3; if element is not present(or count is 0) and temp is not full add element
        if (j == tempsize)
        {
            int l;
            for (l = 0; l < tempsize; l++)
            {
                if (temp[l].c == 0)
                {
                    temp[l].el = a[i];
                    temp[l].c = 1;
                    break;
                }
            }
            //step 4; if element is not present but temp is full reduce count of every element by 1
            if (l == tempsize)
            {
                for (l = 0; l < tempsize; l++)
                    temp[l].c -= 1;
            }
        }
    }

    //step 5. check count of remaining element of array;

    int countToCross = n / k;
    int totalelements = 0;

    for (int i = 0; i < tempsize; i++)
    {
        int currcount = 0;
        for (int j = 0; j < n; j++)
        {
            if (temp[i].el == a[j])
            {
                currcount++;
            }
        }
        if (currcount > countToCross)
            totalelements++;
    }

    return totalelements;
}
//4. count each element using hashmap n time and space complexity;
