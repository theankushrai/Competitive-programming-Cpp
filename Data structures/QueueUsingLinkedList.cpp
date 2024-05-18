 
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int d){
        data=d;
        next=nullptr;
    }
};

class Que{
    public:
    node* front;
    node* back;
    Que(){
        front=back=nullptr;
    }

    bool empty(){
        if(front==nullptr&&back==nullptr)return true;
        return false;
    }

    void enqueue(int val){
        node* newnode=new node(val);
        if(empty()){
            front=back=newnode;
            return;
        }
        back->next=newnode;
        back=back->next;
    }

    void dequeue(){
        if(empty()){
            cout<<"nothing to delete"<<endl;
            return;
        }
        if(front==back){
            front=back=nullptr;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }
    void peek(){
        if(empty()){
            cout<<"empty queue"<<endl;
            return;
        }
        cout<<front->data<<endl;
    }

    void display(){
        if(empty()){
            cout<<"nothing to display"<<endl;
            return;
        }
        node* temp=front;
        while(temp!=back){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
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
    q.enqueue(6);   
    q.enqueue(7);   
    q.display();
    q.peek();
    q.dequeue();
    q.peek();
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
    return 0;
}