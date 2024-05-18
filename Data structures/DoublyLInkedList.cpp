
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* prev;
    node* next;

    explicit node(int d){
        data=d;
        prev=nullptr;
        next=nullptr;
    }
};

void display(node* &head){
    node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void inserthead(node* &head, int val){
    node* newnode=new node(val);

    if(head==nullptr){
        head=newnode;
        return;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
}
void inserttail(node* &head, int val){
    node* newnode=new node(val);

    if(head==nullptr){
        head=newnode;
        return;
    }

    node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;

}
void deletehead(node* &head){
    if(head==nullptr){
        cout<<"nothing to delete"<<endl;
        return;
    }
    if(head->next== nullptr){
        head=nullptr;
        return;
    }
    node* temp=head;
    head=head->next;
    head->prev=nullptr;
    delete temp;
}
void deletion(node* &head, int pos){
    if(head==nullptr){
        cout<<"nothing to delete"<<endl;
        return;
    }
    if(pos==1){
        deletehead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=nullptr && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=nullptr){
        temp->next->prev=temp->prev;}
    delete temp;
}



int main()
{
    node* h=nullptr;
    inserthead(h,1);
    inserttail(h,2);
    inserttail(h,3);
    inserttail(h,4);
    inserttail(h,5);
    inserthead(h,0);
    display(h);


    return 0;
}