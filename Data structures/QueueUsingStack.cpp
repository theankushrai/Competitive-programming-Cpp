#include<stack> 
#include<iostream>
using namespace std;


// //with using 2nd atack

// class Que{
//     stack<int> s1;
//     stack<int> s2;

//     public:


//     bool empty(){
//         if(s1.empty()&&s2.empty()){
//             return true;
//         }
//         return false;
//     }

//     void enqueue(int val){
//         s1.push(val);
//     }

//     void dequeue(){
//         if(empty()){
//             cout<<"queue is empty"<<endl;
//             return;
//         }
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s2.pop();
//     }

//     void peek(){
//         if(empty()){
//             cout<<"queue is empty"<<endl;
//             return;
//         }
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         cout<<s2.top()<<endl;
//     }

    

// };

//using only 1 stack with recursion
class Que{
    stack<int> s1;

    public:


    bool empty(){
        if(s1.empty()){
            return true;
        }
        return false;
    }

    void enqueue(int val){
        s1.push(val);
    }

    int dequeue(){
        int x=s1.top();
        s1.pop();
        if(empty()) return x;
        int item=dequeue();
        s1.push(x);
        return item;

    }


};
int main()
{
    Que q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}