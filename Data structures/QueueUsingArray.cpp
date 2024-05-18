 
#include<iostream>
using namespace std;
#define n 20
class Que{
    int* a;
    int front;
    int back;

    public:
    Que(){
        a=new int[n];
        front=-1;
        back=-1;
    }

    bool empty(){
        if(front==-1||front>back){
            return true;
        }
        return false;
    }
    void enqueue(int val){
        if(back==n){
            cout<<"queue overflow"<<endl;
            return;
        }
        if(front==-1){
            front++;
            a[++back]=val;
            return;
        }
        a[++back]=val;
    }

    void dequeue(){
        if(empty()){
            cout<<"nothing to delete";
            return;
        }
        front++;
    }

    int peek(){
        if(empty()){
            cout<<"queue empty";
            return -1;
        }
        return a[front];
    }

    void display(){
        if(empty()){
            cout<<"queue empty";
            return;
        }
        for(int i =front;i<=back;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    Que q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    cout<<q.peek()<<endl;
    return 0;
}