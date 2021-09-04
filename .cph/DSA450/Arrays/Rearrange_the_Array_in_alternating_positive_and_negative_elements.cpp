/*
Given an array arr[ ] containing equal number of positive and negative elements, arrange the array such that every positive element is followed by a negative element.
Note- The relative order of positive and negative numbers should be maintained.

Example 1:

Input:
N = 6
arr[] = {-1, 2, -3, 4, -5, 6}
Output:  
2 -1 4 -3 6 -5
Explanation: Positive numbers in order 
are 2, 4 and 6. Negative numbers in order 
are -1, -3 and -5. So the arrangement we 
get is 2, -1, 4, -3, 6 and -5.
Example 2:

Input:
N = 4
arr[] = {-3, 2, -4, 1}
Output:  
2 -3 1 -4 
*/

//1.  we can make two separate arrays for negative and positive and then place them back in correct order. O(n) time and space complexity


    vector<int> arranged(int a[],int n)
    {
        vector<int> ans;
        vector<int> neg; // for negitive
        vector<int> pos;
        for(int i =0;i<n;i++){
            if(a[i]<0) neg.push_back(a[i]);
            else pos.push_back(a[i]);
        }
        
        int i =0;
        int j=0;
        while(i<pos.size()&&j<neg.size()){
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);

        }
        while(i<pos.size())ans.push_back(pos[i++]);
        while(j<neg.size())ans.push_back(neg[j++]);
        return ans;
    }
//2. if we dont have to preserve the order of elements 
// we can manipulate all negative elements to last and then place the elements accordingly
void rightrotate(int a[],int i,int j){
        int temp=a[j];
        for(int k=i;k<j;j++){
            a[k+1]=a[k];
        }
        a[i]=temp;
    }
    vector<int> arranged(int a[],int n)
    {
        vector<int> ans;
        int target=-1;
        for(int i =0;i<n;i++){
            if(target==-1){
                if((i%2==0&&a[i]<0)||(i%2==1&&a[i]>=0))target=i;
            }
            else{
                if((a[target]<0&&a[i]>=0)||(a[target]>=0&&a[i]<0)){
                    rightrotate(a,target,i);
                    
                    if(i-target>=2) target+=2;//if i-target>=2 that means all elements between i& target are target
                    else target=-1;
                }
            }
        }
        for(int i =0;i<n;i++){
            ans.push_back(a[i]);
        }
    return ans;
    }