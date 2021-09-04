/*Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.*/

// 1. brute force

for (int i = 0; i < n1; i++)
{
    for (int j = 0; j < n2; j++)
    {
        for (int k = 0; k < n3; k++)
        {
            if (a[i] == b[j] && b[j] == c[k])
                vector.push_back(a[i]);
        }
    }
}
// 2. 3 pointer approach - but it prints duplicate elements
vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    vector<int> result;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            result.push_back(a[i]);
            i++;
            j++;
            k++;
        }
        else if (a[i] <= b[j] && a[i] <= c[k])
            i++;
        else if (b[j] <= c[k] && b[j] <= a[i])
            j++;
        else
            k++;
    }
    return result;
}
// 3. we create a linear funciton to delete duplicate elements
vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    vector<int> result;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            result.push_back(a[i]);
            i++;
            j++;
            k++;
        }
        else if (a[i] <= b[j] && a[i] <= c[k])
            i++;
        else if (b[j] <= c[k] && b[j] <= a[i])
            j++;
        else
            k++;
    }
    i = 1;
    while (i < result.size())
    { //function to delete duplicate elements from resuls vector
        if (result[i] == result[i - 1])
            result.erase(result.begin() + i);
        else
            i++;
    }
    return result;
}
//4. we maintain 3 count hashmaps or vector pairs