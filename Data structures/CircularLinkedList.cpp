
#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

    explicit node(int d){
        data=d;
        next=nullptr;
    }
};

void inserthead(node* &head, int val){
    node* newnode=new node(val);
    if(head==nullptr){
        head=newnode;
        head->next=head;
        return;
    }
    node* temp=head;

    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    head=newnode;


}

void inserttail(node* &head, int val){

if(head==nullptr){
inserthead(head,val);
return;
}

node* newnode=new node(val);
node* temp=head;
while(temp->next!=head){
temp=temp->next;
}
temp->next=newnode;
newnode->next=head;
}

void display(node* &head){
    if(head==nullptr){
        cout<<"nothing to display";
        return;
    }
    node* temp=head;
    cout<<temp->data<<" ";
    temp=temp->next;
    while(temp!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deletion(node* &head, int pos){
    if(head==null){
        cout<<"nothing to delete"<<endl;
        return;
    }
    if(pos==0){
        deletehead(head);
        return;
    }
    node* temp=head;
    int count=0;
    while(count<pos&&temp!=head){
        temp=temp->next;
        count++;
    }
}


int main()
{
    node* head=nullptr;
    inserttail(head,1);
    inserttail(head,2);
    inserttail(head,3);
    inserttail(head,4);
    inserthead(head,0);
    display(head);
    return 0;
}