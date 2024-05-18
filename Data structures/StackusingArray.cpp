 
#include<iostream>
using namespace std;
 
#define n 100

class stack{
    int* a;
    int top;
    public:
    stack(){
        a=new int[n];
        top=-1;
    }
    void push(int val){
        if(top>n-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        a[top]=val;
    }
    void pop(){
        if(top==-1){
            cout<<"nothing to delte"<<endl;
            return;
        }
        top--;
    }
    bool empty(){
        return top==-1;
    }
    int topel(){
        if(top==-1){
            return -1;
        }
        return a[top];
    }
    void display(){
        if(top==-1){
            cout<<"nothing to display"<<endl;
            return;
        }
        for (int i = 0; i <=top; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        
    }
};


int main()
{
    stack st;;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    st.pop();
    st.pop();
    st.display();
    cout<<st.empty()<<endl;
    cout<<st.topel();
    return 0;
}