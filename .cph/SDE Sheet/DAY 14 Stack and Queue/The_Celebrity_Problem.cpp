/*Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n). There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.

 

Example 1:


Input: graph = [
  [1,1,0],
  [0,1,0],
  [1,1,1]
]
Output: 1
Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j, otherwise graph[i][j] = 0 means person i does not know person j. The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.
Example 2:


Input: graph = [
  [1,0,1],
  [1,1,0],
  [0,1,1]
]
Output: -1
Explanation: There is no celebrity.
 

Note:

The directed graph is represented as an adjacency matrix, which is an n x n matrix where a[i][j] = 1 means person i knows person j while a[i][j] = 0 means the contrary.
Remember that you won't have direct access to the adjacency matrix.*/

// 1.brute force - using graph inward outward- calculing how many know i and i knows how many
//time complexity n2;
//space complexity 2n;

int celebrity(vector<vector<int> >& a, int n) 
    {
        vector<int> knowshim(n,0);
        vector<int> heknows(n,0);
        for(int i =0;i<n;i++) {
            for(int j =0;j<n;j++){
                if(a[i][j]==1){
                    heknows[i]++;
                    knowshim[j]++;
                }
            }
        }
        for(int i =0;i<n;i++){
            if(heknows[i]==0&&knowshim[i]==n-1)return i;
        }
        return -1;
    }
  
  //2.using stack - push all -pop top 2; if a knows b then a is not celbrity push b ;
  //time complexity n;
  //space complexity n;

  int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i =0;i<n;i++)st.push(i);
        
        while(st.size()>1){
            int a =st.top();st.pop();
            int b=st.top();st.pop();
            
            if(M[a][b]==1)st.push(b);
            else st.push(a);
        }
        
        int c =st.top();st.pop();
        //check if c is actually a celebrity
        for(int i =0;i<n;i++){
            if(i!=c&&(M[c][i]||!M[i][c]))return -1;
        }
        return c;
        
    }
  
  //3.using single pointer and elimination-if a knows b then a cant be celebrity , then eliminate a;
  //time complexity n;
  //space complexity 1;

  int celebrity(vector<vector<int> >& a, int n) 
    {
        int c=0;
        
        for(int i =1;i<n;i++){
            if(a[c][i])c=i;
        }
        
        //check if c is really a celbrity
        
        for(int i =1;i<n;i++){
            if(i!=c&&(a[c][i]||!a[i][c]))return -1;
        }
        return c;
    }