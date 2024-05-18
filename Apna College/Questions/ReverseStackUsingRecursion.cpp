#include<stack> 
#include<iostream>
using namespace std;
 
void insertatbottom(stack<int> st, int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int topel=st.top();
    st.pop();
    insertatbottom(st,val);
    st.push(topel);
}

void reversestackusingrecursion(stack<int> st){
    
    if(st.empty()) return;

    int val=st.top();
    st.pop();
    reversestackusingrecursion(st);
    insertatbottom(st,val);
}

int main()
{
    stack<int> st;
    for (int i = 0; i < 10000; i++)
    {
        st.push(i);
    }
    reversestackusingrecursion(st);
    while(!st.empty())   {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}