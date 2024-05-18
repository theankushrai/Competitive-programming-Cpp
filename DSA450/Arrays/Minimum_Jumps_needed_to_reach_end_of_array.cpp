// Given an array of N integers arr[] where each element represents the max number of steps that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.


// Example 1:

// Input:
// N = 11 
// arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
// Output: 3 
// Explanation: 
// First jump from 1st element to 2nd 
// element with value 3. Now, from here 
// we jump to 5th element with value 9, 
// and from here we will jump to last. 

// 1.dp methord
//2. O(n) methord ( https://www.youtube.com/watch?v=CqgK_qi4SKQ&t=467s )

int minJumps(int a[], int n){
        
        if(n<=1)return 0;
        if(a[0]==0)return -1;// if first value is zero that means we can make zero jumps. thus not possible to reach end
        
        int step=a[0]; //no of steps we can take/ no of steps left
        int maxR=a[0];// the maximum index we can reach
        int jump=1;//what jump are we currentlyon
        
        for(int i =1;i<n-1;i++){//since we have to reach end. finding maxR for n-1 is a waste of time
            
            maxR=max(maxR,i+a[i]);
            step--;
            
            if(step==0){
                if(maxR<=i)return -1;//if step==0 ie maxreach-i<=0 then we cant go forward.
                jump++;
                step=maxR-i;
            }
        }
        return jump;
        
    }