/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.*/

// 1.using two stacks
// time complexity 1;
//space complexity 2n;
MinStack() {
        
    }
    stack<int> s;
        stack<int> min;
    void push(int val) {
        if(min.empty()||val<=min.top()) min.push(val);
        s.push(val);
    }
    
    void pop() {
            if(!min.empty()&&s.top()==min.top())min.pop();
            s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }


//2. putting min and value on top of each other;
//time complexity 1;
//space complexity n;
 MinStack() {
        
    }
        stack<int> st;
    int min = INT_MAX;
    void push(int val) {
        if(val<min)min=val;
        st.push(val);
        st.push(min);
    }
    
    void pop() {
        st.pop();
        st.pop();
        if(st.empty())min=INT_MAX;
        else min=st.top();
    }
    
    int top() {
        int temp=st.top();
        st.pop();
        int res=st.top();
        st.push(temp);
        return res;
    }
    
    int getMin() {
        return min;
    }


//3. data structure methord
//time complexity 1;
//space complexity 1;

class MinStack {
	private Node head;
        
    public void push(int x) {
        if (head == null) 
            head = new Node(x, x, null);
        else 
            head = new Node(x, Math.min(x, head.min), head);
    }
    
    public void pop() {
        head = head.next;
    }
    
    public int top() {
        return head.val;
    }
    
    public int getMin() {
        return head.min;
    }
        
    private class Node {
        int val;
        int min;
        Node next;
            
        private Node(int val, int min, Node next) {
            this.val = val;
            this.min = min;
            this.next = next;
        }
    }
}