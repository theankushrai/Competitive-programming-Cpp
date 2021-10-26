/*Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task: 
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100
*/


//1.using recursion
//time complexity n2;
//auxilary space n2;

void insertintostack(stack<int>&s, int val){
    if(s.empty()||val>s.top()){
        s.push(val);
        return;
    }
    int temp=s.top();
    s.pop();
    insertintostack(s,val);
    s.push(temp);
}

void sortstack(stack<int>&s){
    if(s.size()==1)return;
    int val=s.top();
    s.pop();
    sortstack(s);
    insertintostack(s,val);
}
void SortedStack :: sort()
{
  sortstack(s);
}

// 2.using temp stack
// time complexity n2;
//space complexity n;
void SortedStack :: sort()
{
   stack<int> temp;
   while(!s.empty()){
        int t=s.top();
        s.pop();
           while(!temp.empty()&&temp.top()>t){
               s.push(temp.top());
               temp.pop();
           }
        temp.push(t);
   }
  swap(temp,s);
}

//3.using vector
//time complexity nlogn;
//space complexity 2n

void SortedStack :: sort()
{
   vector<int> temp;
   while(!s.empty()){
       temp.push_back(s.top());
       s.pop();
   }
   sort(temp.begin(),temp.end());
   for(auto it:temp)s.push(it);
}