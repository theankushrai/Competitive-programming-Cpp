/*
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500


1. sorting the profit
time complexity n+nlogn+n;
space complexity n
*/    
    
    static bool mycomp(Job j1, Job j2){
        return (j1.profit>j2.profit);
    }

    vector<int> JobScheduling(Job a[], int n) 
    { 
        sort(a,a+n,mycomp);
        vector<int> ans;
        
        int max_deadline=0;
        for(int i =0;i<n;i++)max_deadline=max(max_deadline,a[i].dead);
        vector<int> temp(max_deadline+1,-1);
        
        for(int i =0;i<n;i++){
            if(temp[a[i].dead]==-1){
                temp[a[i].dead]=a[i].profit;
            }
            else{
                int j=a[i].dead;
                while(temp[j]!=-1)j--;
                if(j<1)continue;
                temp[j]=a[i].profit;
            }
        }
        
        int count=0;
        int maxprofit=0;
        for(int i =0;i<=max_deadline;i++){
            if(temp[i]!=-1){
                count++;
                maxprofit+=temp[i];
            }
        }
        ans.push_back(count);
        ans.push_back(maxprofit);
        return ans;
    } 