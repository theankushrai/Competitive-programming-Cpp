#include<algorithm>
#include<queue> 
#include<iostream>
using namespace std;
 
class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    Stack(){
        N=0;
    }
    //when push is the expensive operation
    // void push(int val){
    //     q2.push(val);
    //     N++;
    //     while(!q1.empty()){
    //         q2.push(q1.front());
    //         q1.pop();
    //     }
    //     swap(q1,q2);
    // }
    // void pop(){
    //     q1.pop();
    //     N--;
    // }

    //when pop is the expensive operation

    void push(int val){
        q1.push(val);
        N++;
    }
    void pop(){
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1,q2);
        N--;
    }
    int top(){
        return q1.back();
    }
    int size(){
        return N;
    }

};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;s.pop();
    cout<<s.top()<<endl;s.pop();
    cout<<s.top()<<endl;
    return 0;
}